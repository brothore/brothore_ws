

// #include "Imu.h"
// #include "Kinematics.h"
// #include "PID.h"
// #include "Imu.h"
#define IMU_PUBLISH_RATE 20 //hz
#define COMMAND_RATE 20     //hz
#define DEBUG_RATE 5
#define MotorL1countA 21 //编码器A
#define MotorL1countB 45 //编码器B

#define MotorR1countA 20 //编码器A
#define MotorR1countB 44 //编码器B

#define MotorL2countA 18 //编码器A
#define MotorL2countB 43 //编码器B

#define MotorR2countA 2  //编码器A
#define MotorR2countB 34 //编码器B

#define MotorL3countA 19 //编码器A
#define MotorL3countB 42 //编码器B

#define MotorR3countA 3  //编码器A
#define MotorR3countB 33 //编码器B
// #define K_P 0.6 // P constant
// #define K_I 0.3 // I constant
// #define K_D 0.5 // D constant

#define K_P 1.5 // P constant
#define K_I 0.1 // I constant
#define K_D 0.0 // D constant

#define ROBOT_WIDTH 255
#define PWM_MIN -255
#define PWM_MAX 255
#define UTESLA_TO_TESLA 0.000001
#include <Wire.h>
#include <JY901.h>
double vel_x;
double vel_th;
float Acc_lr, Acc_fb, Acc_g;
float Angle_tg, Angle_tt, Angle_fx;
float Gyro_tg, Gyro_tt, Gyro_fx;
const int R3A = 23;
const int R3B = 24;
const int R3S = 13;
const int L3S = 12;
const int L3A = 25;
const int L3B = 26;
const int L2A = 36;
const int L2B = 35;
const int L2S = 9;
const int L1S = 6;
const int L1A = 39;
const int L1B = 38;
const int R1A = 28;
const int R1B = 29;
const int R1S = 8;
const int R2S = 7;
const int R2A = 31;
const int R2B = 30;
unsigned long g_prev_command_time = 0;
int H_L1_B = 0;
int H_R1_B = 0;
int H_L2_B = 0;
int H_R2_B = 0;
int H_L3_B = 0;
int H_R3_B = 0;
unsigned long nowtime = 0;
volatile float motorL1 = 0; //中断变量，左轮子脉冲计数
volatile float motorR1 = 0; //中断变量，右轮子脉冲计数
volatile float motorL2 = 0; //中断变量，左轮子脉冲计数
volatile float motorR2 = 0; //中断变量，右轮子脉冲计数
volatile float motorL3 = 0; //中断变量，左轮子脉冲计数
volatile float motorR3 = 0; //中断变量，右轮子脉冲计数
float v1 = 0;               //单位cm/s
float v2 = 0;               //单位cm/s
float v3 = 0;               //单位cm/s
float v4 = 0;               //单位cm/s
float v5 = 0;               //单位cm/s
float v6 = 0;               //单位cm/s
// Servo myservo;
int vel_flag = 0;
float g_req_linear_vel_x = 0;
float g_req_linear_vel_y = 0;
float g_req_angular_vel_z = 0;
long lasttim;

double left_vel;
double right_vel;
long tim;
char imu_link[] = "imu_link";
char odom[] = "odom";
double roll,pitch,yaw;
double qx,qy,qz,qw;
void messageCb();
void PIDCallback();

void messageCb()
{
lasttim = millis();
Serial.println("recevied");

g_prev_command_time = millis();
}
void moveBase()
{

left_vel = vel_x - vel_th * ROBOT_WIDTH / 2000;
right_vel = vel_x + vel_th * ROBOT_WIDTH / 2000;
// Serial.print("Lsp:");
// Serial.print(left_vel);
// Serial.print("\tLsp:");
// Serial.println(right_vel);
double left_speed = left_vel * 255;
double right_speed = right_vel * 255;
// Serial.print("Lsp:");
// Serial.print(left_speed);
// Serial.print("\tLsp:");
// Serial.println(right_speed);
//     float l1_pid = motor1_pid.compute(v1, left_vel*255);
//   float r1_pid = motor2_pid.compute(v2, right_vel*255);
// float l2_pid = motor3_pid.compute(v3, left_vel*255);
// float r2_pid = motor4_pid.compute(v4, right_vel*255);
// float l3_pid = motor5_pid.compute(v5, left_vel*255);
// float r3_pid = motor6_pid.compute(v6, right_vel*255);


// Run_Moto_F(left_speed,right_speed,3,3);

}

void stopBase()
{
vel_x = 0;
vel_th = 0;
Run_Moto_F(0, 0, 1, 1);
Run_Moto_F(0, 0, 2, 2);
Run_Moto_F(0, 0, 3, 3);
}

/**
    函数作用：读取左右电机的速度
    返回值：  无
    
  r3------l3
  l2------l1
  r2------r1

  * */
void Read_Moto_V(int ifDebug)
{

//这是读取电机速度的函数

if(vel_flag == 0){
  // Serial.print("begin_millis:");
  // Serial.println(millis());     
  nowtime = millis() + 50; 
// Serial.print("nowtime:");
//   Serial.println(nowtime);                                             //读50毫秒
  vel_flag = 1;
}
attachInterrupt(digitalPinToInterrupt(MotorL1countA), Read_Moto_L1, RISING); //左轮脉冲开中断计数
attachInterrupt(digitalPinToInterrupt(MotorR1countA), Read_Moto_R1, RISING); //右轮脉冲开中断计数
attachInterrupt(digitalPinToInterrupt(MotorL2countA), Read_Moto_L2, RISING); //左轮脉冲开中断计数
attachInterrupt(digitalPinToInterrupt(MotorR2countA), Read_Moto_R2, RISING); //右轮脉冲开中断计数
attachInterrupt(digitalPinToInterrupt(MotorL3countA), Read_Moto_L3, RISING); //左轮脉冲开中断计数
attachInterrupt(digitalPinToInterrupt(MotorR3countA), Read_Moto_R3, RISING); //右轮脉冲开中断计数
// while (millis() < nowtime)
// {
//   /* code */
// }
  //      Serial.print("millis");
  // Serial.println(millis()); 
// if (true){//会拖慢系统运行速度                                                    //达到50毫秒关闭中断
if (millis() >= nowtime){//会拖慢系统运行速度  
  //      Serial.print("millis");
  // Serial.println(millis());        
  //        Serial.print("--:");
  // Serial.println(nowtime);     
  
    Serial.print("L1:");
  Serial.print(motorL1);
  Serial.print("\tL2:");
  Serial.print(motorL2);
  Serial.print("\tL3:");
  Serial.println(motorL3);                                  //达到50毫秒关闭中断
// detachInterrupt(digitalPinToInterrupt(MotorL1countA)); //左轮脉冲关中断计数
// detachInterrupt(digitalPinToInterrupt(MotorR1countA)); //右轮脉冲关中断计数
// detachInterrupt(digitalPinToInterrupt(MotorL2countA)); //左轮脉冲关中断计数
// detachInterrupt(digitalPinToInterrupt(MotorR2countA)); //右轮脉冲关中断计数
// detachInterrupt(digitalPinToInterrupt(MotorL3countA)); //左轮脉冲关中断计数
// detachInterrupt(digitalPinToInterrupt(MotorR3countA)); //右轮脉冲关中断计数
// float V_L1, V_R1, V_L2, V_R2, V_L3, V_R3;
// V_L1 = V_R1 = V_L2 = V_R2 = V_L3 = V_R3 = 0;
// //390来自转速比1:30中的30乘以编码器线数13
// V_L1 = ((motorL1 / 390) * 7.45 * PI) / 0.05; //单位cm/s
// V_R1 = ((motorR1 / 390) * 7.45 * PI) / 0.05; //单位cm/s
// V_L2 = ((motorL2 / 130) * 7.45 * PI) / 0.05; //单位cm/s
// V_R2 = ((motorR2 / 130) * 7.45 * PI) / 0.05; //单位cm/s
// V_L3 = ((motorL3 / 390) * 7.45 * PI) / 0.05; //单位cm/s
// V_R3 = ((motorR3 / 390) * 7.45 * PI) / 0.05; //单位cm/s
// v1 = V_L1;
// v2 = V_R1;
// v3 = V_L2;
// v4 = V_R2;
// v5 = V_L3;
// v6 = V_R3;


// if (ifDebug == 1)
// {
//   Serial.print("L1:");
//   Serial.print(motorL1);
//   Serial.print("\tL2:");
//   Serial.print(motorL2);
//   Serial.print("\tL3:");
//   Serial.println(motorL3);

//   // Serial.print("R1:");
//   // Serial.print(v2);
//   // Serial.print("\tR2:");
//   // Serial.print(v4);
//   // Serial.print("\tR3:");
//   // Serial.println(v6);
//   Serial.println();
// }
// else if (ifDebug == 2)
// {
  
// }

vel_flag = 0;



// motorL1 = 0;
// motorR1 = 0;
// motorL2 = 0;
// motorR2 = 0;
// motorL3 = 0;
// motorR3 = 0;



} 

// 变压器一边为车头
}
void PIDCallback()
{
//callback function every time PID constants are received from lino_pid for tuning

}
void Read_Moto_L1()
{

H_L1_B = digitalRead(MotorL1countB); //0是倒转 1是正转
if (H_L1_B == 1)
{
  motorL1++;
}
else
{
  motorL1--;
}
//  Serial.print("Moto LB = ");
//  Serial.print(motorL);
}
void Read_Moto_L2()
{
/**
    函数作用：读取左电机的编码器
    返回值：  无
  * */
H_L2_B = digitalRead(MotorL2countB); //0是倒转 1是正转
if (H_L2_B == 0)
{
  motorL2++;
}
else
{
  // motorL2--;
}
//  Serial.print("Moto LB = ");
//  Serial.print(motorL);
}
void Read_Moto_L3()
{
/**
    函数作用：读取左电机的编码器
    返回值：  无
  * */
H_L3_B = digitalRead(MotorL3countB); //0是倒转 1是正转

if (H_L3_B == 1)
{
  motorL3++;
}
else
{
  // motorL3--;
}

//  Serial.print("Moto LB = ");
//  Serial.print(motorL);
}
//读取右轮脉冲
void Read_Moto_R1()
{
/**
    函数作用：读取右电机的编码器
    返回值：  无
  * */
H_R1_B = digitalRead(MotorR1countB); //0是倒转 1是正转
if (H_R1_B == 0)
{
  motorR1++;
}
else
{
  motorR1--;
}

//  Serial.print("\tMoto RB = ");
//  Serial.println(motorR);
}
void Read_Moto_R3()
{
/**
    函数作用：读取右电机的编码器
    返回值：  无
  * */
H_R3_B = digitalRead(MotorR3countB); //0是倒转 1是正转
if (H_R3_B == 1)
{
  motorR3++;
}
else
{
  motorR3--;
}

//  Serial.print("\tMoto RB = ");
//  Serial.println(motorR);
}
void Read_Moto_R2()
{
/**
    函数作用：读取右电机的编码器
    返回值：  无
  * */
H_R2_B = digitalRead(MotorR2countB); //0是倒转 1是正转
if (H_R2_B == 1)
{
  motorR2++;
}
else
{
  motorR2--;
}

//  Serial.print("\tMoto RB = ");
//  Serial.println(motorR);
}

/**
    函数作用：电机行走，传入的L_v R_v为左右轮速度，范围-255~255，对应倒转和正转
    返回值：  无
    L      R
    1------1
    2------2
    3------3

  * */
void Run_Moto_F(int L_v, int R_v, int L_Moto, int R_Moto)
{
int L_Motor_A, R_Motor_A, L_Motor_B, R_Motor_B, L_Motor_SPEED, R_Motor_SPEED;
switch (L_Moto)
{
case 1:
  L_Motor_A = L1A;
  L_Motor_B = L1B;
  L_Motor_SPEED = L1S;
  break;
case 2:
  L_Motor_A = L2A;
  L_Motor_B = L2B;
  L_Motor_SPEED = L2S;
  break;
case 3:
  L_Motor_A = L3A;
  L_Motor_B = L3B;
  L_Motor_SPEED = L3S;
  break;
default:
  break;
}
switch (R_Moto)
{
case 1:
  R_Motor_A = R1A;
  R_Motor_B = R1B;
  R_Motor_SPEED = R1S;
  break;
case 2:
  R_Motor_A = R2A;
  R_Motor_B = R2B;
  R_Motor_SPEED = R2S;
  break;
case 3:
  R_Motor_A = R3A;
  R_Motor_B = R3B;
  R_Motor_SPEED = R3S;
  break;
default:
  break;
}
if (L_v > 250)
{
  L_v = 250;
}
else if (L_v < -250)
{
  L_v = -250;
}
if (R_v > 250)
{
  R_v = 250;
}
else if (R_v < -250)
{
  R_v = -250;
}
//前进，可设置左右轮速度
if (L_v > 0)
{
  digitalWrite(L_Motor_A, 0);
  digitalWrite(L_Motor_B, HIGH);
  analogWrite(L_Motor_SPEED, L_v);
}
else if (L_v < 0)
{
  digitalWrite(L_Motor_A, HIGH);
  digitalWrite(L_Motor_B, 0);
  analogWrite(L_Motor_SPEED, -L_v);
}
else
{
  digitalWrite(L_Motor_A, 0);
  digitalWrite(L_Motor_B, 0);
  analogWrite(L_Motor_SPEED, 0);
}
if (R_v > 0)
{
  digitalWrite(R_Motor_A, HIGH);
  digitalWrite(R_Motor_B, 0);
  analogWrite(R_Motor_SPEED, R_v);
}
else if (R_v < 0)
{
  digitalWrite(R_Motor_A, 0);
  digitalWrite(R_Motor_B, HIGH);
  analogWrite(R_Motor_SPEED, -R_v);
}
else
{
  digitalWrite(R_Motor_A, 0);
  digitalWrite(R_Motor_B, 0);
  analogWrite(R_Motor_SPEED, 0);
  // delay(2000);
}
}

void setup()
{
// put your setup code here, to run once:
pinMode(L1A, OUTPUT);
pinMode(L1B, OUTPUT);
pinMode(R1A, OUTPUT);
pinMode(R1B, OUTPUT);
pinMode(L1S, OUTPUT);
pinMode(R1S, OUTPUT);

pinMode(L2A, OUTPUT);
pinMode(L2B, OUTPUT);
pinMode(R2A, OUTPUT);
pinMode(R2B, OUTPUT);
pinMode(L2S, OUTPUT);
pinMode(R2S, OUTPUT);

pinMode(L3A, OUTPUT);
pinMode(L3B, OUTPUT);
pinMode(R3A, OUTPUT);
pinMode(R3B, OUTPUT);
pinMode(L3S, OUTPUT);
pinMode(R3S, OUTPUT);
            // nh.initNode();
            // nh.getHardware()->setBaud(57600);
            // nh.advertise(wheel_speed_pub);
            // nh.subscribe(sub);
            // nh.subscribe(pid_sub);
            // nh.advertise(raw_vel_pub);
            // nh.advertise(raw_imu_pub);
            //   nh.advertise(sensor_mag_pub);
            // nh.advertise(sensor_imu_pub);
// nh.advertise(raw_imu_pub);
// nh.subscribe(pid_sub);

// Serial.begin(57600);
Serial.begin(57600);
Serial.println("BEGIN");
Serial2.begin(9600);
              // while (!nh.connected())
              // {
              //   nh.spinOnce();
              // }
              // nh.loginfo("CAR CONNECTED");
delay(1);
}
void getAngle()
{
// geometry_msgs::Vector3 gyro;
// gyro.x = (double)Gyro_tg;
// gyro.y = (double)Gyro_tt;
// gyro.z = (double)Gyro_fx;
// geometry_msgs::Vector3 accel;
// accel.x = (double)Acc_fb;
// accel.y = (double)Acc_lr;
// accel.z = (double)Acc_g;
// geometry_msgs::Vector3 mag;
// mag.x = (double)JY901.stcMag.h[0];
// mag.y = (double)JY901.stcMag.h[1];
// mag.z = (double)JY901.stcMag.h[2];
//   str_imu.orientation.x = gyro.x;
//   str_imu.orientation.y = gyro.y;
//   str_imu.orientation.z = gyro.z;
//   str_imu.angular_velocity.x= AcAngle.x;
//   str_imu.angular_velocity.y= AcAngle.y;
// str_imu.angular_velocity.z= AcAngle.z;
//   str_imu.linear_acceleration.x = accel.x;
//   str_imu.linear_acceleration.y = accel.y;
//   str_imu.linear_acceleration.z = accel.z;


// raw_imu_msg.linear_acceleration.x = Angle_tg;
// raw_imu_msg.linear_acceleration.y = Angle_tt;
// raw_imu_msg.linear_acceleration.z = Angle_fx;

//pass gyroscope data to imu object
// raw_imu_msg.angular_velocity = gyro;
// raw_imu_msg.linear_acceleration = accel;

// //pass accelerometer data to imu object
// raw_imu_msg.magnetic_field = mag;
  // str_imu.header.frame_id=imu_link;
  // str_imu.header.stamp = nh.now();
roll  =  (float)JY901.stcAngle.Angle[0]/32768*180;
pitch =  (float)JY901.stcAngle.Angle[1]/32768*180;
yaw   =  (float)JY901.stcAngle.Angle[2]/32768*180;
  yaw = yaw*PI/180;
  pitch = pitch*PI/180;
  roll = roll*PI/180;
  // qx = sin(roll/2) * cos(pitch/2) * cos(yaw/2) - cos(roll/2) * sin(pitch/2) * sin(yaw/2);
  // qy = cos(roll/2) * sin(pitch/2) * cos(yaw/2) + sin(roll/2) * cos(pitch/2) * sin(yaw/2);
  // qz = cos(roll/2) * cos(pitch/2) * sin(yaw/2) - sin(roll/2) * sin(pitch/2) * cos(yaw/2);
  // qw = cos(roll/2) * cos(pitch/2) * cos(yaw/2) + sin(roll/2) * sin(pitch/2) * sin(yaw/2);
// str_imu.orientation.x = qx;
// str_imu.orientation.y = qy;
// str_imu.orientation.z = qz;
// str_imu.orientation.w = qw;

// str_mag.magnetic_field.x = (double)JY901.stcMag.h[0];
// str_mag.magnetic_field.y = (double)JY901.stcMag.h[1];
// str_mag.magnetic_field.z = (double)JY901.stcMag.h[2];

// sensor_imu_pub.publish(&str_imu);
// sensor_mag_pub.publish(&str_mag);


//   Serial.print("加速度:");
//   Serial.print("前后: ");
//   Serial.println(Acc_fb);
// 后退是正的，前进是负的
//   Serial.print("左右: ");
//   Serial.println(Acc_lr);
//   //左负右正
//   Serial.print("\t垂直:");
//   Serial.println(Acc_g);
//   // Serial.print("角加速度:");
// Serial.print("桶滚");
// Serial.print(Angle_tg);
// Serial.print(" 抬头");
// Serial.print(Angle_tt);
// Serial.print(" 方向");
// Serial.println(Angle_fx);
//   Serial.print("角度:");
//   //桶滚 右边为负 左边为正
//   Serial.print("桶滚");
//   Serial.print(AcAngle_tg);
//   //抬头 抬头为正 低头为负
//   Serial.print(" 抬头");
//   Serial.print(AcAngle_tt);
//   //方向 左边为正 右边为负
//   //车头为降压模块一方
//   Serial.print(" 方向");
//   Serial.println(AcAngle_fx);
//   Serial.println(" ");
//     delay(500);
/*
  acc是加速度
  gyro是角度变化率(角加速度)
  angle是角度
  mag地磁/电子罗盘
  Z是斜着倾斜的角度
*/
}
void backGroundSystem()
{
Read_Moto_V(2);
while (Serial2.available())
{
  JY901.CopeSerialData(Serial2.read()); //Call JY901 data cope function
}

}

// void loop()
// {
// static unsigned long prev_control_time = 0;
// static unsigned long prev_imu_time = 0;
// static unsigned long prev_debug_time = 0;
// static bool imu_is_initialized;
// backGroundSystem();

// if ((millis() - prev_control_time) >= (1000 / COMMAND_RATE))
// {
//   moveBase();
//   prev_control_time = millis();
// }

// //this block stops the motor when no command is received
// if ((millis() - g_prev_command_time) >= 400)
// {
//   stopBase();
// }

// // tim = millis();
// //     if((tim-lasttim)>1000)
// //     {
// //     // setSpeed(LEFT,0);
// //     // setSpeed(RIGHT,0);
// //     // Run_Moto_F(0,0,1,1);
// //     // Run_Moto_F(0,0,3,3);
// //     // Run_Moto_F(0,0,2,2);
// //     }
// //this block publishes the IMU data based on defined rate
// if ((millis() - prev_imu_time) >= (1000 / IMU_PUBLISH_RATE))
// {
//   //sanity check if the IMU is connected
//   if (!imu_is_initialized)
//   {
//     imu_is_initialized = true;

//     if (imu_is_initialized)
//       nh.loginfo("IMU Initialized");
//     else
//       nh.logfatal("IMU failed to initialize. Check your IMU connection.");
//   }
//   else
//   {
//     getAngle();
//   }

//   prev_imu_time = millis();
// }
// nh.spinOnce();
// // delay(1);
// }
void loop(){
    // Serial.println("hello1");
  Read_Moto_V(1);
  // Serial.println("hello2");


}