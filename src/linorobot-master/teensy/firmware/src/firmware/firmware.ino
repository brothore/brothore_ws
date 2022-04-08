#if (ARDUINO >= 100)
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

// #include <Servo.h>
#include "JY901_Serial.h"
#include "ros.h"
#include "ros/time.h"
//header file for publishing velocities for odom
#include "lino_msgs/Velocities.h"
//header file for cmd_subscribing to "cmd_vel"
#include "geometry_msgs/Twist.h"
//header file for pid server
#include "lino_msgs/PID.h"
#include <lino_msgs/car_param.h>

//header file for imu
#include "lino_msgs/Imu.h"
#include <lino_msgs/wheel_speed.h>
#include "lino_base_config.h"
#include "Motor.h"
#include "Kinematics.h"
#include "PID.h"
#include "Imu.h"

#define ENCODER_OPTIMIZE_INTERRUPTS // comment this out on Non-Teensy boards
// #include "Encoder.h"

#define IMU_PUBLISH_RATE 20 //hz
#define COMMAND_RATE 20 //hz
#define DEBUG_RATE 5
#define BACKGROUND_RATE 1000

// Encoder motor1_encoder(MOTOR1_ENCODER_A, MOTOR1_ENCODER_B, COUNTS_PER_REV);
// Encoder motor2_encoder(MOTOR2_ENCODER_A, MOTOR2_ENCODER_B, COUNTS_PER_REV); 
// Encoder motor3_encoder(MOTOR3_ENCODER_A, MOTOR3_ENCODER_B, COUNTS_PER_REV); 
// Encoder motor4_encoder(MOTOR4_ENCODER_A, MOTOR4_ENCODER_B, COUNTS_PER_REV); 
// Encoder motor5_encoder(MOTOR5_ENCODER_A, MOTOR5_ENCODER_B, COUNTS_PER_REV); 
// Encoder motor6_encoder(MOTOR6_ENCODER_A, MOTOR6_ENCODER_B, COUNTS_PER_REV); 
void(* resetFunc) (void) = 0;
volatile int H_L1_B = 0;
volatile int H_R1_B = 0;
volatile int H_L2_B = 0;
volatile int H_R2_B = 0;
volatile int H_L3_B = 0;
volatile int H_R3_B = 0;

volatile int H_L1_A = 0;
volatile int H_R1_A = 0;
volatile int H_L2_A = 0;
volatile int H_R2_A = 0;
volatile int H_L3_A = 0;
volatile int H_R3_A = 0;

volatile int motorL1 = 0; //中断变量，左轮子脉冲计数
volatile int motorR1 = 0; //中断变量，右轮子脉冲计数
volatile int motorL2 = 0; //中断变量，左轮子脉冲计数
volatile int motorR2 = 0; //中断变量，右轮子脉冲计数
volatile int motorL3 = 0; //中断变量，左轮子脉冲计数
volatile int motorR3 = 0; //中断变量，右轮子脉冲计数
int v1 = 0;               //单位m/s
int v2 = 0;               //单位m/s
int v3 = 0;               //单位m/s
int v4 = 0;               //单位m/s
int v5 = 0;               //单位m/s
int v6 = 0;               //单位m/s
// Servo steering_servo;

Controller motor1_controller(Controller::MOTOR_DRIVER, MOTOR1_PWM, MOTOR1_IN_A, MOTOR1_IN_B);
Controller motor2_controller(Controller::MOTOR_DRIVER, MOTOR2_PWM, MOTOR2_IN_A, MOTOR2_IN_B); 
Controller motor3_controller(Controller::MOTOR_DRIVER, MOTOR3_PWM, MOTOR3_IN_A, MOTOR3_IN_B);
Controller motor4_controller(Controller::MOTOR_DRIVER, MOTOR4_PWM, MOTOR4_IN_A, MOTOR4_IN_B);
Controller motor5_controller(Controller::MOTOR_DRIVER, MOTOR5_PWM, MOTOR5_IN_A, MOTOR5_IN_B);
Controller motor6_controller(Controller::MOTOR_DRIVER, MOTOR6_PWM, MOTOR6_IN_A, MOTOR6_IN_B);

PID motor1_pid(PWM_MIN, PWM_MAX, K_P, K_I, K_D);
PID motor2_pid(PWM_MIN, PWM_MAX, K_P, K_I, K_D);
PID motor3_pid(PWM_MIN, PWM_MAX, K_P, K_I, K_D);
PID motor4_pid(PWM_MIN, PWM_MAX, K_P, K_I, K_D);
PID motor5_pid(PWM_MIN, PWM_MAX, K_P, K_I, K_D);
PID motor6_pid(PWM_MIN, PWM_MAX, K_P, K_I, K_D);

Kinematics kinematics(Kinematics::LINO_BASE, MAX_RPM, WHEEL_DIAMETER, FR_WHEELS_DISTANCE, LR_WHEELS_DISTANCE);

float g_req_linear_vel_x = 0;
float g_req_linear_vel_y = 0;
float g_req_angular_vel_z = 0;

unsigned long g_prev_command_time = 0;
unsigned long out_time = 0;

    int current_rpm1;
    int current_rpm2;
    int current_rpm3;
    int current_rpm4;
    int current_rpm5;
    int current_rpm6;
//callback function prototypes
void commandCallback(const geometry_msgs::Twist& cmd_msg);
void PIDCallback(const lino_msgs::PID& pid);
void CarCallback(const lino_msgs::car_param &car_p);
int vel_flag = 0;
unsigned long nowtime = 0;
volatile int change = 0;
ros::NodeHandle nh;
ros::Subscriber<lino_msgs::car_param> car_sub("car_param",CarCallback);

ros::Subscriber<geometry_msgs::Twist> cmd_sub("cmd_vel", commandCallback);
ros::Subscriber<lino_msgs::PID> pid_sub("pid", PIDCallback);
lino_msgs::wheel_speed str_wheel;
ros::Publisher wheel_speed_pub("wheel_speed_msg", &str_wheel);
lino_msgs::Imu raw_imu_msg;
ros::Publisher raw_imu_pub("raw_imu", &raw_imu_msg);

lino_msgs::Velocities raw_vel_msg;
ros::Publisher raw_vel_pub("raw_vel", &raw_vel_msg);
void Read_Moto_V()
{

  //这是读取电机速度的函数
 
  if(vel_flag == 0)
  {
  nowtime = millis() + 50; 
  vel_flag = 1;
  } //读50毫秒

  attachInterrupt(digitalPinToInterrupt(MOTOR1_ENCODER_A), Read_Moto_L1, CHANGE); //左轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MOTOR2_ENCODER_A), Read_Moto_R1, CHANGE); //右轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MOTOR3_ENCODER_A), Read_Moto_L2, CHANGE); //左轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MOTOR4_ENCODER_A), Read_Moto_R2, CHANGE); //右轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MOTOR5_ENCODER_A), Read_Moto_L3, CHANGE); //左轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MOTOR6_ENCODER_A), Read_Moto_R3, CHANGE); //右轮脉冲开中断计数


  if (millis() >= nowtime){                                          //达到50毫秒关闭中断
    detachInterrupt(digitalPinToInterrupt(MOTOR1_ENCODER_A)); //左轮脉冲关中断计数
    detachInterrupt(digitalPinToInterrupt(MOTOR2_ENCODER_A)); //右轮脉冲关中断计数
    detachInterrupt(digitalPinToInterrupt(MOTOR3_ENCODER_A)); //左轮脉冲关中断计数
    detachInterrupt(digitalPinToInterrupt(MOTOR4_ENCODER_A)); //右轮脉冲关中断计数
    detachInterrupt(digitalPinToInterrupt(MOTOR5_ENCODER_A)); //左轮脉冲关中断计数
    detachInterrupt(digitalPinToInterrupt(MOTOR6_ENCODER_A)); //右轮脉冲关中断计数
    unsigned long dt = (1000 / COMMAND_RATE);
    double dtm = 60000/(double)dt ;
    current_rpm1 = ((float)motorL1/COUNTS_PER_REV*dtm);
    current_rpm2 = ((float)motorR1/COUNTS_PER_REV*dtm);
    current_rpm3 = ((float)motorL2/COUNTS_PER_REV*dtm);
    current_rpm4 = ((float)motorR2/COUNTS_PER_REV*dtm);
    current_rpm5 = ((float)motorL3/COUNTS_PER_REV*dtm);
    current_rpm6 = ((float)motorR3/COUNTS_PER_REV*dtm);
    // str_wheel.L1=current_rpm1;
    // str_wheel.L2=current_rpm3;
    // str_wheel.R1=current_rpm2;
    // str_wheel.R2=current_rpm4;
    // str_wheel.L3=current_rpm5;
    // str_wheel.R3=current_rpm6;
    vel_flag = 0;
     motorL1 = 0;
     motorR1 = 0;
     motorL2 = 0;
     motorR2 = 0;
     motorL3 = 0;
     motorR3 = 0;
    //  nh.loginfo("hello");
  }
  // 变压器一边为车头
}

void Read_Moto_L1()
{
 H_L1_B = digitalRead(MOTOR1_ENCODER_B); 
H_L1_A = digitalRead(MOTOR1_ENCODER_A); //0是倒转 1是正转
if (H_L1_A == 1)
{

  if (H_L1_B == 1)
  {
    motorL1++;
        //  nh.loginfo("hello");
  }
  else
  {
    motorL1--;
  }

}
else if (H_L1_A == 0)
{

  if (H_L1_B == 0)
  {
    motorL1++;
        //  nh.loginfo("hello");
  }
  else
  {
    motorL1--;
  }

}


}
void Read_Moto_L2()
{
  /**
     函数作用：读取左电机的编码器
     返回值：  无
   * */
   H_L2_B = digitalRead(MOTOR3_ENCODER_B); 
H_L2_A = digitalRead(MOTOR3_ENCODER_A); //0是倒转 1是正转
if (H_L2_A == 1)
{
  if (H_L2_B == 1)
  {
    motorL2++;
  }
  else
  {
    motorL2--;
  }

}
else if (H_L2_A == 0)
{
  if (H_L2_B == 0)
  {
    motorL2++;
  }
  else
  {
    motorL2--;
  }

}
}
void Read_Moto_L3()
{
  /**
     函数作用：读取左电机的编码器
     返回值：  无
   * */
 H_L3_B = digitalRead(MOTOR5_ENCODER_B); 
H_L3_A = digitalRead(MOTOR5_ENCODER_A); //0是倒转 1是正转
  if (H_L3_A == 1)
{
  if (H_L3_B == 1)
  {
    motorL3++;
  }
  else
  {
    motorL3--;
  }

}
else if (H_L3_A == 0)
{
  if (H_L3_B == 0)
  {
    motorL3++;
  }
  else
  {
    motorL3--;
  }

}
}
//读取右轮脉冲
void Read_Moto_R1()
{
  /**
     函数作用：读取右电机的编码器
     返回值：  无
   * */
   H_R1_B = digitalRead(MOTOR2_ENCODER_B); 
H_R1_A = digitalRead(MOTOR2_ENCODER_A); //0是倒转 1是正转
if (H_R1_A == 1)
{
  if (H_R1_B == 0)
  {
    motorR1++;
  }
  else
  {
    motorR1--;
  }

}
else if (H_R1_A == 0)
{
  if (H_R1_B == 1)
  {
    motorR1++;
  }
  else
  {
    motorR1--;
  }

}
}
void Read_Moto_R2()
{
  /**
     函数作用：读取右电机的编码器
     返回值：  无
   * */
 H_R2_B = digitalRead(MOTOR4_ENCODER_B); 
H_R2_A = digitalRead(MOTOR4_ENCODER_A); //0是倒转 1是正转
if (H_R2_A == 1)
{
  if (H_R2_B == 0)
  {
    motorR2++;
  }
  else
  {
    motorR2--;
  }

}
else if (H_R2_A == 0)
{
  if (H_R2_B == 1)
  {
    motorR2++;
  }
  else
  {
    motorR2--;
  }

}
}
void Read_Moto_R3()
{
  /**
     函数作用：读取右电机的编码器
     返回值：  无
   * */
  H_R3_B = digitalRead(MOTOR6_ENCODER_B); 
H_R3_A = digitalRead(MOTOR6_ENCODER_A); //0是倒转 1是正转
if (H_R3_A == 1)
{
  if (H_R3_B == 0)
  {
    motorR3++;
  }
  else
  {
    motorR3--;
  }

}
else if (H_R3_A == 0)
{
  if (H_R3_B == 1)
  {
    motorR3++;
  }
  else
  {
    motorR3--;
  }

}
}
void setup()
{
    // steering_servo.attach(STEERING_PIN);
    // steering_servo.write(90); 
    JY901.attach(Serial1);
    nh.initNode();
    nh.getHardware()->setBaud(57600);
    nh.subscribe(pid_sub);
    nh.subscribe(cmd_sub);
     nh.subscribe(car_sub);
    nh.advertise(raw_vel_pub);
    nh.advertise(raw_imu_pub);
    nh.advertise(wheel_speed_pub);
    while (!nh.connected())
    {
        nh.spinOnce();
    }
      // Serial.begin(9600);
  Serial1.begin(9600);
    nh.loginfo("LINOBASE CONNECTED");
    delay(1);
}
void backgroundSystem(){
    Read_Moto_V();
    //  str_wheel.R1_PID = kinematics.wheels_x_distance_;
    // str_wheel.R2_PID = kinematics.wheels_y_distance_;
    // str_wheel.R3_PID = kinematics.wheel_circumference_;
    

    receiveIMUdata();
    // str_wheel.L_SPEED = (float)g_prev_command_time;
    // str_wheel.R_SPEED =  (float)millis();

  
}
void loop()
{       
    static unsigned long prev_control_time = 0;
    static unsigned long prev_imu_time = 0;
    static unsigned long prev_debug_time = 0;
    static unsigned long prev_background_time = 0;
    static bool imu_is_initialized;
  if ((millis() - prev_background_time) >= (1000 / BACKGROUND_RATE))
        {
            backgroundSystem();
            prev_background_time = millis();
        }

    //this block drives the robot based on defined rate
    if ((millis() - prev_control_time) >= (1000 / COMMAND_RATE))
    {
        moveBase();
        prev_control_time = millis();
    }
    if ((millis() - g_prev_command_time) >= out_time)
    {
        stopBase();
    }

    //this block stops the motor when no command is received

    //this block publishes the IMU data based on defined rate
    if ((millis() - prev_imu_time) >= (1000 / IMU_PUBLISH_RATE))
    {
        //sanity check if the IMU is connected
        if (!imu_is_initialized)
        {
            imu_is_initialized = initIMU();

            imu_is_initialized = true;
            if(imu_is_initialized)
                nh.loginfo("IMU Initialized");
            else
                nh.logfatal("IMU failed to initialize. Check your IMU connection.");
        }
        else
        {
            publishIMU();
        }
        prev_imu_time = millis();
    }

    //this block displays the encoder readings. change DEBUG to 0 if you don't want to display
    if(DEBUG)
    {
        if ((millis() - prev_debug_time) >= (1000 / DEBUG_RATE))
        {
            printDebug();
            prev_debug_time = millis();
        }
    }

        

    //call all the callbacks waiting to be called
    nh.spinOnce();
}

void PIDCallback(const lino_msgs::PID& pid)
{
    //callback function every time PID constants are received from lino_pid for tuning
    //this callback receives pid object where P,I, and D constants are stored
    motor1_pid.updateConstants(pid.p, pid.i, pid.d);
    motor2_pid.updateConstants(pid.p, pid.i, pid.d);
    motor3_pid.updateConstants(pid.p, pid.i, pid.d);
    motor4_pid.updateConstants(pid.p, pid.i, pid.d);
    motor5_pid.updateConstants(pid.p, pid.i, pid.d);
    motor6_pid.updateConstants(pid.p, pid.i, pid.d);


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
    // int current_rpm1 = motor1_encoder.getRPM();
    // int current_rpm2 = motor2_encoder.getRPM();
    // int current_rpm3 = motor3_encoder.getRPM();
    // int current_rpm4 = motor4_encoder.getRPM();
    int l1 = motor1_pid.compute(req_rpm.motor1, current_rpm1);
    int l2 = motor2_pid.compute(req_rpm.motor2, current_rpm2);
    int l3 = motor3_pid.compute(req_rpm.motor3, current_rpm3);
    int l4 = motor4_pid.compute(req_rpm.motor4, current_rpm4);
    int l5 = motor5_pid.compute(req_rpm.motor5, current_rpm5);
    int l6 = motor6_pid.compute(req_rpm.motor6, current_rpm6);
    // str_wheel.L1_PID = (float)l1;
    // str_wheel.R1_PID = (float)l2;
    // str_wheel.L2_PID = (float)l3;
    // str_wheel.R2_PID = (float)l4;
    // str_wheel.L3_PID = (float)l5;
    // str_wheel.R3_PID = (float)l6;

    // str_wheel.L1_PID = (float)req_rpm.motor1;
    // str_wheel.L2_PID = (float)req_rpm.motor3;
    // str_wheel.L3_PID = (float)req_rpm.motor5;
    // str_wheel.R2_PID = (float)req_rpm.motor4;
    // str_wheel.L3_PID = (float)req_rpm.motor5;
    // str_wheel.R3_PID = (float)req_rpm.motor6;
    // current_rpm1 = motorL1;
    // str_wheel.L1=current_rpm1;
    // str_wheel.L2=current_rpm3;
    // str_wheel.R1=current_rpm2;
    // str_wheel.R2=current_rpm4;
    // str_wheel.L3=current_rpm5;
    // str_wheel.R3=current_rpm6;
    // int current_rpm5 = motor5_encoder.getRPM();
    // int current_rpm6 = motor6_encoder.getRPM();

    //the required rpm is capped at -/+ MAX_RPM to prevent the PID from having too much error
    //the PWM value sent to the motor driver is the calculated PID based on required RPM vs measured RPM
    motor1_controller.spin(l1);
    motor2_controller.spin(l2);
    motor3_controller.spin(l3);  
    motor4_controller.spin(l4);    
    motor5_controller.spin(l5);  
    motor6_controller.spin(l6);  


    //    motor1_controller.spin(50);
    // motor3_controller.spin(100);  
    // motor5_controller.spin(255);  


    // motor2_controller.spin(-50);
    // motor4_controller.spin(-100);    
    // motor6_controller.spin(-255);    
    // motor5_controller.spin(motor5_pid.compute(req_rpm.motor5, current_rpm5));
    // motor6_controller.spin(motor6_pid.compute(req_rpm.motor6, current_rpm6));  
 
    Kinematics::velocities current_vel;

    if(kinematics.base_platform == Kinematics::ACKERMANN || kinematics.base_platform == Kinematics::ACKERMANN1)
    {
        int current_steering_angle;
        
        current_steering_angle = steer(g_req_angular_vel_z);
        current_vel = kinematics.getVelocities(current_steering_angle, current_rpm1, current_rpm2);
    }
    else
    {
        current_vel = kinematics.getVelocities(current_rpm1, current_rpm2, current_rpm3, current_rpm4,current_rpm5,current_rpm6);
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
  char buffer[100];
    //pass accelerometer data to imu object
    
    raw_imu_msg.linear_acceleration = readAccelerometer();
    // sprintf (buffer,  "show imu:%f", JY901.getAccRawX());
    // nh.loginfo(buffer);
    // //pass gyroscope data to imu object
    raw_imu_msg.angular_velocity = readGyroscope();

    // //pass accelerometer data to imu object
    raw_imu_msg.magnetic_field = readMagnetometer();

    //publish raw_imu_msg
    raw_imu_pub.publish(&raw_imu_msg);
}

int steer(int steering_angle)
{
    //steering function for ACKERMANN base
    int servo_steering_angle;

    steering_angle = constrain(steering_angle, -MAX_STEERING_ANGLE, MAX_STEERING_ANGLE);
    servo_steering_angle = mapFloat(steering_angle, -MAX_STEERING_ANGLE, MAX_STEERING_ANGLE, PI, 0) * (180 / PI);

    // steering_servo.write(servo_steering_angle);

    return steering_angle;
}

int mapFloat(int x, int in_min, int in_max, int out_min, int out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void printDebug()
{
  wheel_speed_pub.publish(&str_wheel);
    // char buffer[100];

    // sprintf (buffer, "Encoder FrontLeft  : %d\tEncoder FrontRight : %d\nEncoder RearLeft   : %d\tEncoder RearRight  : %d", motorL1, motorR1, motorL2, motorR2);
    // // sprintf (buffer, "Encoder FrontLeft  : %ld\tEncoder FrontRight : %ld\nEncoder RearLeft   : %ld\tEncoder RearRight  : %ld", motor1_encoder.read(), motor2_encoder.read(), motor3_encoder.read(), motor4_encoder.read());
    // nh.loginfo(buffer);

    // sprintf (buffer, "Encoder FrontRight : %ld", motor2_encoder.read());
    // nh.loginfo(buffer);


    // sprintf (buffer, "Encoder RearLeft   : %ld", motor3_encoder.read());
    // nh.loginfo(buffer);
 

    // sprintf (buffer, "Encoder RearRight  : %ld", motor4_encoder.read());

    // nh.loginfo(buffer);


    //     sprintf (buffer, "Encoder RearLeft   : %ld\n", motor5_encoder.read());
    // nh.loginfo(buffer);
    // sprintf (buffer, "Encoder RearRight  : %ld\n", motor6_encoder.read());
    // nh.loginfo(buffer);
}
void CarCallback(const lino_msgs::car_param &car_p){
    int resetCar = car_p.Reset_car;
  if (resetCar >=1)
  {  
      resetFunc();
  }
  kinematics.wheels_x_distance_= car_p.W_car;
  kinematics.wheels_y_distance_= car_p.L_car;
  kinematics.wheel_circumference_ = car_p.R_wheel*PI;
  out_time = car_p.out_time;

}