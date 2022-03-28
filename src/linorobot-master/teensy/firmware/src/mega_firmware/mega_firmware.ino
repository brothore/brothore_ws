#if (ARDUINO >= 100)
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

#include <Servo.h>

#include "ros.h"
#include "ros/time.h"
//header file for publishing velocities for odom
#include "lino_msgs/Velocities.h"
//header file for cmd_subscribing to "cmd_vel"
#include "geometry_msgs/Twist.h"
//header file for pid server
#include "lino_msgs/PID.h"
//header file for imu
#include "lino_msgs/Imu.h"

#include "lino_base_config.h"
#include "Motor.h"
#include "Kinematics.h"
#include "PID.h"
#include "Imu.h"
#include <ros.h> 
#include <std_msgs/String.h> 
#include <std_msgs/Empty.h> 
#include <geometry_msgs/Twist.h>
#define ENCODER_OPTIMIZE_INTERRUPTS // comment this out on Non-Teensy boards
#include "Encoder.h"

#define PI 3.14159265
#define MotorL1countA 21 //编码器A
#define MotorL1countB 45 //编码器B

#define MotorR1countA 20 //编码器A
#define MotorR1countB 44 //编码器B

#define MotorL2countA 18 //编码器A
#define MotorL2countB 43 //编码器B

#define MotorR2countA 2 //编码器A
#define MotorR2countB 34 //编码器B

#define MotorL3countA 19 //编码器A
#define MotorL3countB 42 //编码器B


#define MotorR3countA 3 //编码器A
#define MotorR3countB 33 //编码器B
#define IMU_PUBLISH_RATE 20 //hz
#define COMMAND_RATE 20 //hz
#define DEBUG_RATE 5

const int  R3A =23;
const int  R3B =24;
const int  R3S =13;
const int  L3S =12;
const int  L3A =25;
const int  L3B =26;
const int  L2A =36;
const int  L2B =35;
const int  L2S =9;
const int  L1S =6;
const int  L1A =39;
const int  L1B =38;
const int  R1A =28;
const int  R1B =29;
const int  R1S =8;
const int  R2S =7;
const int  R2A =31;
const int  R2B =30;

volatile float motorL1 = 0; //中断变量，左轮子脉冲计数
volatile float motorR1 = 0; //中断变量，右轮子脉冲计数
volatile float motorL2 = 0; //中断变量，左轮子脉冲计数
volatile float motorR2 = 0; //中断变量，右轮子脉冲计数
volatile float motorL3 = 0; //中断变量，左轮子脉冲计数
volatile float motorR3 = 0; //中断变量，右轮子脉冲计数

int H_L1_B = 0;
int H_R1_B = 0;
int H_L2_B = 0;
int H_R2_B = 0;
int H_L3_B = 0;
int H_R3_B = 0;

float v1 = 0; //单位cm/s
float v2 = 0; //单位cm/s
float v3 = 0; //单位cm/s
float v4 = 0; //单位cm/s
float v5 = 0; //单位cm/s
float v6 = 0; //单位cm/s

Encoder motor1_encoder(MOTOR1_ENCODER_A, MOTOR1_ENCODER_B, COUNTS_PER_REV);
Encoder motor2_encoder(MOTOR2_ENCODER_A, MOTOR2_ENCODER_B, COUNTS_PER_REV); 
Encoder motor3_encoder(MOTOR3_ENCODER_A, MOTOR3_ENCODER_B, COUNTS_PER_REV); 
Encoder motor4_encoder(MOTOR4_ENCODER_A, MOTOR4_ENCODER_B, COUNTS_PER_REV); 

Servo steering_servo;

Controller motor1_controller(Controller::MOTOR_DRIVER, MOTOR1_PWM, MOTOR1_IN_A, MOTOR1_IN_B);
Controller motor2_controller(Controller::MOTOR_DRIVER, MOTOR2_PWM, MOTOR2_IN_A, MOTOR2_IN_B); 
Controller motor3_controller(Controller::MOTOR_DRIVER, MOTOR3_PWM, MOTOR3_IN_A, MOTOR3_IN_B);
Controller motor4_controller(Controller::MOTOR_DRIVER, MOTOR4_PWM, MOTOR4_IN_A, MOTOR4_IN_B);

PID motor1_pid(PWM_MIN, PWM_MAX, K_P, K_I, K_D);
PID motor2_pid(PWM_MIN, PWM_MAX, K_P, K_I, K_D);
PID motor3_pid(PWM_MIN, PWM_MAX, K_P, K_I, K_D);
PID motor4_pid(PWM_MIN, PWM_MAX, K_P, K_I, K_D);

Kinematics kinematics(Kinematics::LINO_BASE, MAX_RPM, WHEEL_DIAMETER, FR_WHEELS_DISTANCE, LR_WHEELS_DISTANCE);

float g_req_linear_vel_x = 0;
float g_req_linear_vel_y = 0;
float g_req_angular_vel_z = 0;

unsigned long g_prev_command_time = 0;

//callback function prototypes
void commandCallback(const geometry_msgs::Twist& cmd_msg);
void PIDCallback(const lino_msgs::PID& pid);

ros::NodeHandle nh;

ros::Subscriber<geometry_msgs::Twist> cmd_sub("cmd_vel", commandCallback);
ros::Subscriber<lino_msgs::PID> pid_sub("pid", PIDCallback);

lino_msgs::Imu raw_imu_msg;
ros::Publisher raw_imu_pub("raw_imu", &raw_imu_msg);

lino_msgs::Velocities raw_vel_msg;
ros::Publisher raw_vel_pub("raw_vel", &raw_vel_msg);

void setup()
{
    steering_servo.attach(STEERING_PIN);
    steering_servo.write(90); 
    
    nh.initNode();
    nh.getHardware()->setBaud(57600);
    nh.subscribe(pid_sub);
    nh.subscribe(cmd_sub);
    nh.advertise(raw_vel_pub);
    nh.advertise(raw_imu_pub);

    while (!nh.connected())
    {
        nh.spinOnce();
    }
    nh.loginfo("LINOBASE CONNECTED");
    delay(1);
}

// void loop()
// {
//     static unsigned long prev_control_time = 0;
//     static unsigned long prev_imu_time = 0;
//     static unsigned long prev_debug_time = 0;
//     static bool imu_is_initialized;

//     //this block drives the robot based on defined rate
//     if ((millis() - prev_control_time) >= (1000 / COMMAND_RATE))
//     {
//         moveBase();
//         prev_control_time = millis();
//     }

//     //this block stops the motor when no command is received
//     if ((millis() - g_prev_command_time) >= 400)
//     {
//         stopBase();
//     }

//     //this block publishes the IMU data based on defined rate
//     if ((millis() - prev_imu_time) >= (1000 / IMU_PUBLISH_RATE))
//     {
//         //sanity check if the IMU is connected
//         if (!imu_is_initialized)
//         {
//             imu_is_initialized = initIMU();

//             if(imu_is_initialized)
//                 nh.loginfo("IMU Initialized");
//             else
//                 nh.logfatal("IMU failed to initialize. Check your IMU connection.");
//         }
//         else
//         {
//             publishIMU();
//         }
//         prev_imu_time = millis();
//     }

//     //this block displays the encoder readings. change DEBUG to 0 if you don't want to display
//     if(DEBUG)
//     {
//         if ((millis() - prev_debug_time) >= (1000 / DEBUG_RATE))
//         {
//             printDebug();
//             prev_debug_time = millis();
//         }
//     }
//     //call all the callbacks waiting to be called
//     nh.spinOnce();
// }
void loop(){





}
void PIDCallback(const lino_msgs::PID& pid)
{
    //callback function every time PID constants are received from lino_pid for tuning
    //this callback receives pid object where P,I, and D constants are stored
    motor1_pid.updateConstants(pid.p, pid.i, pid.d);
    motor2_pid.updateConstants(pid.p, pid.i, pid.d);
    motor3_pid.updateConstants(pid.p, pid.i, pid.d);
    motor4_pid.updateConstants(pid.p, pid.i, pid.d);
}

void commandCallback(const geometry_msgs::Twist& cmd_msg)
{
    //callback function every time linear and angular speed is received from 'cmd_vel' topic
    //this callback function receives cmd_msg object where linear and angular speed are stored
    g_req_linear_vel_x = cmd_msg.linear.x;
    g_req_linear_vel_y = cmd_msg.linear.y;
    g_req_angular_vel_z = cmd_msg.angular.z;

    g_prev_command_time = millis();
}

void moveBase()
{
    //get the required rpm for each motor based on required velocities, and base used
    Kinematics::rpm req_rpm = kinematics.getRPM(g_req_linear_vel_x, g_req_linear_vel_y, g_req_angular_vel_z);

    //get the current speed of each motor
    int current_rpm1 = motor1_encoder.getRPM();
    int current_rpm2 = motor2_encoder.getRPM();
    int current_rpm3 = motor3_encoder.getRPM();
    int current_rpm4 = motor4_encoder.getRPM();

    //the required rpm is capped at -/+ MAX_RPM to prevent the PID from having too much error
    //the PWM value sent to the motor driver is the calculated PID based on required RPM vs measured RPM
    motor1_controller.spin(motor1_pid.compute(req_rpm.motor1, current_rpm1));
    motor2_controller.spin(motor2_pid.compute(req_rpm.motor2, current_rpm2));
    motor3_controller.spin(motor3_pid.compute(req_rpm.motor3, current_rpm3));  
    motor4_controller.spin(motor4_pid.compute(req_rpm.motor4, current_rpm4));    

    Kinematics::velocities current_vel;

    if(kinematics.base_platform == Kinematics::ACKERMANN || kinematics.base_platform == Kinematics::ACKERMANN1)
    {
        float current_steering_angle;
        
        current_steering_angle = steer(g_req_angular_vel_z);
        current_vel = kinematics.getVelocities(current_steering_angle, current_rpm1, current_rpm2);
    }
    else
    {
        current_vel = kinematics.getVelocities(current_rpm1, current_rpm2, current_rpm3, current_rpm4);
    }
    
    //pass velocities to publisher object
    raw_vel_msg.linear_x = current_vel.linear_x;
    raw_vel_msg.linear_y = current_vel.linear_y;
    raw_vel_msg.angular_z = current_vel.angular_z;

    //publish raw_vel_msg
    raw_vel_pub.publish(&raw_vel_msg);
}

void stopBase()
{
    g_req_linear_vel_x = 0;
    g_req_linear_vel_y = 0;
    g_req_angular_vel_z = 0;
}

void publishIMU()
{
    //pass accelerometer data to imu object
    raw_imu_msg.linear_acceleration = readAccelerometer();

    //pass gyroscope data to imu object
    raw_imu_msg.angular_velocity = readGyroscope();

    //pass accelerometer data to imu object
    raw_imu_msg.magnetic_field = readMagnetometer();

    //publish raw_imu_msg
    raw_imu_pub.publish(&raw_imu_msg);
}

float steer(float steering_angle)
{
    //steering function for ACKERMANN base
    float servo_steering_angle;

    steering_angle = constrain(steering_angle, -MAX_STEERING_ANGLE, MAX_STEERING_ANGLE);
    servo_steering_angle = mapFloat(steering_angle, -MAX_STEERING_ANGLE, MAX_STEERING_ANGLE, PI, 0) * (180 / PI);

    steering_servo.write(servo_steering_angle);

    return steering_angle;
}

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void printDebug()
{
    char buffer[50];

    sprintf (buffer, "Encoder FrontLeft  : %ld", motor1_encoder.read());
    nh.loginfo(buffer);
    sprintf (buffer, "Encoder FrontRight : %ld", motor2_encoder.read());
    nh.loginfo(buffer);
    sprintf (buffer, "Encoder RearLeft   : %ld", motor3_encoder.read());
    nh.loginfo(buffer);
    sprintf (buffer, "Encoder RearRight  : %ld", motor4_encoder.read());
    nh.loginfo(buffer);
}
