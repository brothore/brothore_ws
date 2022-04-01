//èµ°åˆ¶å®šè·ç¦?1m,ctrl+k ctrl+1
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>
// #include "lino_msgs/wheel_speed.h"
#include <lino_msgs/wheel_speed.h>
#include <lino_msgs/Velocities.h>
#include <lino_msgs/Imu.h>
#include <lino_msgs/PID.h>
#include <lino_msgs/car_param.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/MagneticField.h>
#include <ros/time.h>
#include "PID.h"
// #include "Imu.h"
// #include "Kinematics.h"
// #include "PID.h"
// #include "Imu.h"
#define IMU_PUBLISH_RATE 20 //hz
#define COMMAND_RATE 20     //hz
#define DEBUG_RATE 5
#define MotorL1countA 21 //ç¼–ç å™¨A
#define MotorL1countB 45 //ç¼–ç å™¨B

#define MotorR1countA 20 //ç¼–ç å™¨A
#define MotorR1countB 44 //ç¼–ç å™¨B

#define MotorL2countA 18 //ç¼–ç å™¨A
#define MotorL2countB 43 //ç¼–ç å™¨B

#define MotorR2countA 2 //ç¼–ç å™¨A
#define MotorR2countB 34 //ç¼–ç å™¨B

#define MotorL3countA 19 //ç¼–ç å™¨A
#define MotorL3countB 42 //ç¼–ç å™¨B


#define MotorR3countA 3 //ç¼–ç å™¨A
#define MotorR3countB 33 //ç¼–ç å™¨B
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
void(* resetFunc) (void) = 0;
//you
const int R3S = 12;
const int R3A = 26;
const int R3B = 25;
const int L3A = 23;
const int L3B = 24;
const int L3S = 13;
//zuo

const int L1A = 35;
const int L1B = 36;
const int L1S = 9;
const int L2S = 6;
const int L2A = 39;
const int L2B = 38;


const int R1A = 29;
const int R1B = 28;
const int R1S = 8;
const int R2S = 7;
const int R2A = 30;
const int R2B = 31;

unsigned long g_prev_command_time = 0;
int H_L1_B = 0;
int H_R1_B = 0;
int H_L2_B = 0;
int H_R2_B = 0;
int H_L3_B = 0;
int H_R3_B = 0;
volatile float motorL1 = 0; //ä¸­æ–­å˜é‡ï¼Œå·¦è½®å­è„‰å†²è®¡æ•°
volatile float motorR1 = 0; //ä¸­æ–­å˜é‡ï¼Œå³è½®å­è„‰å†²è®¡æ•°
volatile float motorL2 = 0; //ä¸­æ–­å˜é‡ï¼Œå·¦è½®å­è„‰å†²è®¡æ•°
volatile float motorR2 = 0; //ä¸­æ–­å˜é‡ï¼Œå³è½®å­è„‰å†²è®¡æ•°
volatile float motorL3 = 0; //ä¸­æ–­å˜é‡ï¼Œå·¦è½®å­è„‰å†²è®¡æ•°
volatile float motorR3 = 0; //ä¸­æ–­å˜é‡ï¼Œå³è½®å­è„‰å†²è®¡æ•°

volatile float S_motorL1 = 0; //ä¸­æ–­å˜é‡ï¼Œå·¦è½®å­è„‰å†²è®¡æ•°
volatile float S_motorR1 = 0; //ä¸­æ–­å˜é‡ï¼Œå³è½®å­è„‰å†²è®¡æ•°
volatile float S_motorL2 = 0; //ä¸­æ–­å˜é‡ï¼Œå·¦è½®å­è„‰å†²è®¡æ•°
volatile float S_motorR2 = 0; //ä¸­æ–­å˜é‡ï¼Œå³è½®å­è„‰å†²è®¡æ•°
volatile float S_motorL3 = 0; //ä¸­æ–­å˜é‡ï¼Œå·¦è½®å­è„‰å†²è®¡æ•°
volatile float S_motorR3 = 0; //ä¸­æ–­å˜é‡ï¼Œå³è½®å­è„‰å†²è®¡æ•°


float S_L1, S_R1, S_L2, S_R2, S_L3, S_R3;
float C_L1, C_R1, C_L2, C_R2, C_L3, C_R3;

float v1 = 0;               //å•ä½m/s
float v2 = 0;               //å•ä½m/s
float v3 = 0;               //å•ä½m/s
float v4 = 0;               //å•ä½m/s
float v5 = 0;               //å•ä½m/s
float v6 = 0;               //å•ä½m/s
// Servo myservo;
float g_req_linear_vel_x = 0;
float g_req_linear_vel_y = 0;
float g_req_angular_vel_z = 0;
long lasttim;
PID motor1_pid(PWM_MIN, PWM_MAX, 500, 10, 0);
PID motor2_pid(PWM_MIN, PWM_MAX, 500, 10, 0);
PID motor3_pid(PWM_MIN, PWM_MAX, 500, 10, 0);
PID motor4_pid(PWM_MIN, PWM_MAX, 500, 10, 0);
PID motor5_pid(PWM_MIN, PWM_MAX, 500, 10, 0);
PID motor6_pid(PWM_MIN, PWM_MAX, 500, 10, 0);
double left_vel;
double right_vel;
long tim;
char imu_link[] = "imu_link";
char odom[] = "odom";
double roll,pitch,yaw;
double qx,qy,qz,qw;
void messageCb(const geometry_msgs::Twist &cmd_vel);
void PIDCallback(const lino_msgs::PID &pid);
void CarCallback(const lino_msgs::car_param &car_p);
int vel_flag = 0;

float R_wheel = 0.0911;
float W_car = 0.22;
float L_car = 0.28;
unsigned long nowtime = 0;

ros::NodeHandle nh;
lino_msgs::wheel_speed str_wheel;
ros::Publisher wheel_speed_pub("wheel_speed_msg", &str_wheel);

sensor_msgs::Imu str_imu;
ros::Publisher sensor_imu_pub("imu/data_raw", &str_imu);

sensor_msgs::MagneticField str_mag;
ros::Publisher sensor_mag_pub("imu/mag", &str_mag);

lino_msgs::Imu raw_imu_msg;
ros::Publisher raw_imu_pub("raw_imu", &raw_imu_msg);

lino_msgs::Velocities raw_vel_msg;
ros::Publisher raw_vel_pub("raw_vel", &raw_vel_msg);

ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", messageCb);
ros::Subscriber<lino_msgs::PID> pid_sub("pid", PIDCallback);
ros::Subscriber<lino_msgs::car_param> car_sub("car_param",CarCallback);

//ç§»åŠ¨ä¿¡æ¯å›žè°ƒ
void messageCb(const geometry_msgs::Twist &cmd_vel)
{
  lasttim = millis();
  Serial.println("recevied");
  vel_x = cmd_vel.linear.x;
  vel_th = cmd_vel.angular.z;
  g_prev_command_time = millis();
}
//è¡Œèµ°å‡½æ•°
void moveBase()
{
  // left_vel = vel_x - (vel_th*W_car);
  // right_vel = vel_x + (vel_th * W_car);
  left_vel = vel_x - (vel_th*(W_car/2));
  right_vel = vel_x + (vel_th * (W_car/2));
  // Serial.print("Lsp:");
  // Serial.print(left_vel);
  // Serial.print("\tLsp:");
  // Serial.println(right_vel);
float left_speed = left_vel;
float right_speed = right_vel;
// if (S_L1>1&&S_L2>1&&S_L3>1&&S_R1>1&&S_R2>1&&S_R3>1)
// if (C_L1>=5&&C_L2>=5&&C_L3>=5&&C_R1>=5&&C_R2>=5&&C_R3>=5)
float C_avr = (C_L1+C_L2+C_L3+C_R1+C_R2+C_R3)/6;
float S_avr = (S_L1+S_L2+S_L3+S_R1+S_R2+S_R3)/6;

// if (C_avr>5||S_avr<-5)

// if (S_avr>=(1.399422448))
if (S_avr>=(1))
{
  /* code */
  nh.loginfo("STOPED!!!");

  left_speed = 0;
  right_speed = 0;
}

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

  float l1_pid = motor1_pid.compute(left_speed, v1);
  float r1_pid = motor2_pid.compute(right_speed, v2);
  float l2_pid = motor3_pid.compute(left_speed, v3);
  float r2_pid = motor4_pid.compute(right_speed, v4);
  float l3_pid = motor5_pid.compute(left_speed, v5);
  float r3_pid = motor6_pid.compute(right_speed, v6);

  Run_Moto_F(l1_pid, r1_pid, 1, 1);
  Run_Moto_F(l2_pid, r2_pid, 2, 2);
  Run_Moto_F(l3_pid, r3_pid, 3, 3);
  // Run_Moto_F(100, 100, 2, 2);
  // Run_Moto_F(left_speed,right_speed,3,3);
  str_wheel.L_SPEED = left_speed;
  str_wheel.R_SPEED = right_speed;
  // str_wheel.L1_PID = l1_pid;
  // str_wheel.R1_PID = r1_pid;
  // str_wheel.L2_PID = l2_pid;
  // str_wheel.R2_PID = r2_pid;
  // str_wheel.L3_PID = l3_pid;
  // str_wheel.R3_PID = r3_pid;
}
//åœæ­¢å‡½æ•°
void stopBase()
{
  vel_x = 0;
  vel_th = 0;
  // Run_Moto_F(0, 0, 1, 1);
  // Run_Moto_F(0, 0, 2, 2);
  // Run_Moto_F(0, 0, 3, 3);
}

/**
     å‡½æ•°ä½œç”¨ï¼šè¯»å–å·¦å³ç”µæœºçš„é€Ÿåº¦
     è¿”å›žå€¼ï¼š  æ—?     
    r3------l3
    l2------l1
    r2------r1

   * */
void Read_Moto_V(int ifDebug)
{

  //è¿™æ˜¯è¯»å–ç”µæœºé€Ÿåº¦çš„å‡½æ•? 
  if(vel_flag == 0)
  {
  nowtime = millis() + 50; 
  vel_flag = 1;
  } //è¯?0æ¯«ç§’
  attachInterrupt(digitalPinToInterrupt(MotorL1countA), Read_Moto_L1, RISING); //å·¦è½®è„‰å†²å¼€ä¸­æ–­è®¡æ•°
  attachInterrupt(digitalPinToInterrupt(MotorR1countA), Read_Moto_R1, RISING); //å³è½®è„‰å†²å¼€ä¸­æ–­è®¡æ•°
  attachInterrupt(digitalPinToInterrupt(MotorL2countA), Read_Moto_L2, RISING); //å·¦è½®è„‰å†²å¼€ä¸­æ–­è®¡æ•°
  attachInterrupt(digitalPinToInterrupt(MotorR2countA), Read_Moto_R2, RISING); //å³è½®è„‰å†²å¼€ä¸­æ–­è®¡æ•°
  attachInterrupt(digitalPinToInterrupt(MotorL3countA), Read_Moto_L3, RISING); //å·¦è½®è„‰å†²å¼€ä¸­æ–­è®¡æ•°
  attachInterrupt(digitalPinToInterrupt(MotorR3countA), Read_Moto_R3, RISING); //å³è½®è„‰å†²å¼€ä¸­æ–­è®¡æ•°
  if (millis() >= nowtime){                                          //è¾¾åˆ°50æ¯«ç§’å…³é—­ä¸­æ–­
    detachInterrupt(digitalPinToInterrupt(MotorL1countA)); //å·¦è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
    detachInterrupt(digitalPinToInterrupt(MotorR1countA)); //å³è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
    detachInterrupt(digitalPinToInterrupt(MotorL2countA)); //å·¦è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
    detachInterrupt(digitalPinToInterrupt(MotorR2countA)); //å³è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
    detachInterrupt(digitalPinToInterrupt(MotorL3countA)); //å·¦è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
    detachInterrupt(digitalPinToInterrupt(MotorR3countA)); //å³è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
    float V_L1, V_R1, V_L2, V_R2, V_L3, V_R3;
    V_L1 = V_R1 = V_L2 = V_R2 = V_L3 = V_R3 = 0;
    //390æ¥è‡ªè½¬é€Ÿæ¯”1:30ä¸­çš„30ä¹˜ä»¥ç¼–ç å™¨çº¿æ•?3
    V_L1 = ((motorL1 / 390) * R_wheel  * PI) / 0.05; //å•ä½m/s
    V_R1 = ((motorR1 / 390) * R_wheel  * PI) / 0.05; //å•ä½m/s
    V_L2 = ((motorL2 / 390) * R_wheel  * PI) / 0.05; //å•ä½m/s
    V_R2 = ((motorR2 / 390) * R_wheel  * PI) / 0.05; //å•ä½m/s
    V_L3 = ((motorL3 / 390) * R_wheel  * PI) / 0.05; //å•ä½m/s
    V_R3 = ((motorR3 / 390) * R_wheel  * PI) / 0.05; //å•ä½m/s
    
    C_L1 = ((S_motorL1 / 390) ) ; //å•ä½m
    C_R1 = ((S_motorR1 / 390) ) ; //å•ä½m
    C_L2 = ((S_motorL2 / 390) ) ; //å•ä½m
    C_R2 = ((S_motorR2 / 390) ) ; //å•ä½m
    C_L3 = ((S_motorL3 / 390) ) ; //å•ä½m
    C_R3 = ((S_motorR3 / 390) ) ; //å•ä½m

    S_L1 = ((S_motorL1 / 390) * R_wheel  * PI) ; //å•ä½m
    S_R1 = ((S_motorR1 / 390) * R_wheel  * PI) ; //å•ä½m
    S_L2 = ((S_motorL2 / 390) * R_wheel  * PI) ; //å•ä½m
    S_R2 = ((S_motorR2 / 390) * R_wheel  * PI) ; //å•ä½m
    S_L3 = ((S_motorL3 / 390) * R_wheel  * PI) ; //å•ä½m
    S_R3 = ((S_motorR3 / 390) * R_wheel  * PI) ; //å•ä½m
    v1 = V_L1;
    v2 = V_R1;
    v3 = V_L2;
    v4 = V_R2;
    v5 = V_L3;
    v6 = V_R3;

    raw_vel_msg.linear_x = ((float)(v1 + v2 + v3 + v4 + v5 + v6) / 6) ; // m/s
    raw_vel_msg.linear_y = 0;
    // raw_vel_msg.angular_z =  ((v2+v4+v6)-(v1+v3+v5))/0.22;//left+ right-
    raw_vel_msg.angular_z = (((v2 + v4 + v6) - (v1 + v3 + v5))) / W_car; //left+ right-
    raw_vel_pub.publish(&raw_vel_msg);
    if (ifDebug == 1)
    {
      

        Serial.print("L1:");
      Serial.print(v1);
      Serial.print("\tL2:");
      Serial.print(v3);
      Serial.print("\tL3:");
      Serial.println(v5);

      Serial.print("R1:");
      Serial.print(v2);
      Serial.print("\tR2:");
      Serial.print(v4);
      Serial.print("\tR3:");
      Serial.println(v6);
      Serial.println();
    }
    else if (ifDebug == 2)
    {
      str_wheel.L1 = v1;
      str_wheel.L2 = v3;
      str_wheel.L3 = v5;
      str_wheel.R1 = v2;
      str_wheel.R2 = v4;
      str_wheel.R3 = v6;
    }else if (ifDebug == 3)
    {
      str_wheel.L1 = S_L1;
      str_wheel.L2 = S_L2;
      str_wheel.L3 = S_L3;
      str_wheel.R1 = S_R1;
      str_wheel.R2 = S_R2;
      str_wheel.R3 = S_R3;
      str_wheel.L1_PID = ((C_L1+C_L2+C_L3+C_R1+C_R2+C_R3)/6);
    }
    vel_flag = 0;
     motorL1 = 0;
     motorR1 = 0;
     motorL2 = 0;
     motorR2 = 0;
     motorL3 = 0;
     motorR3 = 0;
  }
  // å˜åŽ‹å™¨ä¸€è¾¹ä¸ºè½¦å¤´
}

void PIDCallback(const lino_msgs::PID &pid)
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
void CarCallback(const lino_msgs::car_param &car_p){
  R_wheel = car_p.R_wheel;
  W_car = car_p.W_car;
  L_car = car_p.L_car;
  int resetCar = car_p.Reset_car;
  if (resetCar >=1)
  {   
//     S_L1=0;
//       S_L2=0;
//       S_L3=0;
//       S_R1=0;
//       S_R2=0;
//       S_R3=0;
      
// detachInterrupt(digitalPinToInterrupt(MotorL1countA)); //å·¦è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
//     detachInterrupt(digitalPinToInterrupt(MotorR1countA)); //å³è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
//     detachInterrupt(digitalPinToInterrupt(MotorL2countA)); //å·¦è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
//     detachInterrupt(digitalPinToInterrupt(MotorR2countA)); //å³è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
//     detachInterrupt(digitalPinToInterrupt(MotorL3countA)); //å·¦è½®è„‰å†²å…³ä¸­æ–­è®¡æ•?    
//     detachInterrupt(digitalPinToInterrupt(MotorR3countA));
//       C_L1=0;
//       C_L2=0;
//       C_L3=0;
//       C_R1=0;
//       C_R2=0;
//       C_R3=0;

//       S_motorL1=0;
//       S_motorL2=0;
//       S_motorL3=0;
//       S_motorR1=0;
//       S_motorR2=0;
//       S_motorR3=0;

//       motorL1=0;
//       motorL2=0;
//       motorL3=0;
//       motorR1=0;
//       motorR2=0;
//       motorR3=0;
      resetFunc();
    /* code */
  }
  

}

void Read_Moto_L1()
{

  H_L1_B = digitalRead(MotorL1countB); //0æ˜¯å€’è½¬ 1æ˜¯æ­£è½?  
  if (H_L1_B == 1)
  {
    motorL1++;
    S_motorL1++;
  }
  else
  {
    motorL1--;
    S_motorL1--;
  }
  //  Serial.print("Moto LB = ");
  //  Serial.print(motorL);
}
void Read_Moto_L2()
{
  /**
     å‡½æ•°ä½œç”¨ï¼šè¯»å–å·¦ç”µæœºçš„ç¼–ç å™¨
     è¿”å›žå€¼ï¼š  æ—?   * */
  H_L2_B = digitalRead(MotorL2countB); //0æ˜¯å€’è½¬ 1æ˜¯æ­£è½?  
  if (H_L2_B == 1)
  {
    motorL2++;
    S_motorL2++;
  }
  else
  {
    motorL2--;
    S_motorL2--;
  }
  //  Serial.print("Moto LB = ");
  //  Serial.print(motorL);
}
void Read_Moto_L3()
{
  /**
     å‡½æ•°ä½œç”¨ï¼šè¯»å–å·¦ç”µæœºçš„ç¼–ç å™¨
     è¿”å›žå€¼ï¼š  æ—?   * */
  H_L3_B = digitalRead(MotorL3countB); //0æ˜¯å€’è½¬ 1æ˜¯æ­£è½?  
  if (H_L3_B == 1)
  {
    motorL3++;
    S_motorL3++;
  }
  else
  {
    motorL3--;
    S_motorL3--;
  }
  //  Serial.print("Moto LB = ");
  //  Serial.print(motorL);
}
//è¯»å–å³è½®è„‰å†²
void Read_Moto_R1()
{
  /**
     å‡½æ•°ä½œç”¨ï¼šè¯»å–å³ç”µæœºçš„ç¼–ç å™¨
     è¿”å›žå€¼ï¼š  æ—?   * */
  H_R1_B = digitalRead(MotorR1countB); //0æ˜¯å€’è½¬ 1æ˜¯æ­£è½?  
  if (H_R1_B == 0)
  {
    motorR1++;
    S_motorR1++;
  }
  else
  {
    motorR1--;
    S_motorR1--;
  }

  //  Serial.print("\tMoto RB = ");
  //  Serial.println(motorR);
}
void Read_Moto_R2()
{
  /**
     å‡½æ•°ä½œç”¨ï¼šè¯»å–å³ç”µæœºçš„ç¼–ç å™¨
     è¿”å›žå€¼ï¼š  æ—?   * */
  H_R2_B = digitalRead(MotorR2countB); //0æ˜¯å€’è½¬ 1æ˜¯æ­£è½?  
  if (H_R2_B == 0)
  {
    motorR2++;
    S_motorR2++;
  }
  else
  {
    motorR2--;
    S_motorR2--;

  }

  //  Serial.print("\tMoto RB = ");
  //  Serial.println(motorR);
}
void Read_Moto_R3()
{
  /**
     å‡½æ•°ä½œç”¨ï¼šè¯»å–å³ç”µæœºçš„ç¼–ç å™¨
     è¿”å›žå€¼ï¼š  æ—?   * */
  H_R3_B = digitalRead(MotorR3countB); //0æ˜¯å€’è½¬ 1æ˜¯æ­£è½?  
  if (H_R3_B == 1)
  {
    motorR3--;
    S_motorR3--;

  }
  else
  {
    motorR3++;
    S_motorR3++;

  }

  //  Serial.print("\tMoto RB = ");
  //  Serial.println(motorR);
}

/**
     å‡½æ•°ä½œç”¨ï¼šç”µæœºè¡Œèµ°ï¼Œä¼ å…¥çš„L_v R_vä¸ºå·¦å³è½®é€Ÿåº¦ï¼ŒèŒƒå›?255~255ï¼Œå¯¹åº”å€’è½¬å’Œæ­£è½?     è¿”å›žå€¼ï¼š  æ—?      L      R
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
  //å‰è¿›ï¼Œå¯è®¾ç½®å·¦å³è½®é€Ÿåº¦
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
S_L1 = S_R1 = S_L2 = S_R2 = S_L3 = S_R3 = 0;
C_L1 = C_R1 = C_L2 = C_R2 = C_L3 = C_R3 = 0;

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
  nh.initNode();
  nh.getHardware()->setBaud(57600);
  nh.advertise(wheel_speed_pub);
  nh.subscribe(sub);
  nh.subscribe(pid_sub);
  nh.advertise(raw_vel_pub);
  nh.advertise(raw_imu_pub);
  nh.advertise(sensor_mag_pub);
  nh.advertise(sensor_imu_pub);
  nh.subscribe(car_sub);
  // nh.advertise(raw_imu_pub);
  // nh.subscribe(pid_sub);
  delay(1000);
  // Serial.begin(57600);
  Serial.begin(57600);
  Serial.println("BRGIN");
  Serial2.begin(9600);
  while (!nh.connected())
  {
    nh.spinOnce();
  }
  nh.loginfo("CAR CONNECTED");
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
  raw_imu_msg.pitch = pitch;
  raw_imu_msg.yaw = yaw;
  raw_imu_msg.roll = roll;
  raw_imu_msg.angular_velocity.x = (double)JY901.stcGyro.w[0] / 32768 * 2000 * 3.1415 / 180;
  raw_imu_msg.angular_velocity.y = (double)JY901.stcGyro.w[1] / 32768 * 2000 * 3.1415 / 180;
  raw_imu_msg.angular_velocity.z = (double)JY901.stcGyro.w[2] / 32768 * 2000 * 3.1415 / 180;
  // str_imu.angular_velocity.x = (double)JY901.stcGyro.w[0] / 32768 * 2000 * 3.1415 / 180;
  // str_imu.angular_velocity.y = (double)JY901.stcGyro.w[1] / 32768 * 2000 * 3.1415 / 180;
  // str_imu.angular_velocity.z = (double)JY901.stcGyro.w[2] / 32768 * 2000 * 3.1415 / 180;


  raw_imu_msg.linear_acceleration.x = (double)JY901.stcAcc.a[0] / 32768 * 16 * 9.8;
  raw_imu_msg.linear_acceleration.y = (double)JY901.stcAcc.a[1] / 32768 * 16 * 9.8;
  raw_imu_msg.linear_acceleration.z = (double)JY901.stcAcc.a[2] / 32768 * 16 * 9.8;
  // str_imu.linear_acceleration.x = (double)JY901.stcAcc.a[0] / 32768 * 16 * 9.8;
  // str_imu.linear_acceleration.y = (double)JY901.stcAcc.a[1] / 32768 * 16 * 9.8;
  // str_imu.linear_acceleration.z = (double)JY901.stcAcc.a[2] / 32768 * 16 * 9.8;

  raw_imu_msg.magnetic_field.x = (double)JY901.stcMag.h[0]* UTESLA_TO_TESLA;
  raw_imu_msg.magnetic_field.y = (double)JY901.stcMag.h[1]* UTESLA_TO_TESLA;
  raw_imu_msg.magnetic_field.z = (double)JY901.stcMag.h[2]* UTESLA_TO_TESLA;
  // str_mag.magnetic_field.x = (double)JY901.stcMag.h[0];
  // str_mag.magnetic_field.y = (double)JY901.stcMag.h[1];
  // str_mag.magnetic_field.z = (double)JY901.stcMag.h[2];

  // sensor_imu_pub.publish(&str_imu);
  // sensor_mag_pub.publish(&str_mag);
  raw_imu_pub.publish(&raw_imu_msg);

  //   Serial.print("åŠ é€Ÿåº¦:");
  //   Serial.print("å‰åŽ: ");
  //   Serial.println(Acc_fb);
  // åŽé€€æ˜¯æ­£çš„ï¼Œå‰è¿›æ˜¯è´Ÿçš?  //   Serial.print("å·¦å³: ");
  //   Serial.println(Acc_lr);
  //   //å·¦è´Ÿå³æ­£
  //   Serial.print("\tåž‚ç›´:");
  //   Serial.println(Acc_g);
  //   // Serial.print("è§’åŠ é€Ÿåº¦:");
  // Serial.print("æ¡¶æ»š");
  // Serial.print(Angle_tg);
  // Serial.print(" æŠ¬å¤´");
  // Serial.print(Angle_tt);
  // Serial.print(" æ–¹å‘");
  // Serial.println(Angle_fx);
  //   Serial.print("è§’åº¦:");
  //   //æ¡¶æ»š å³è¾¹ä¸ºè´Ÿ å·¦è¾¹ä¸ºæ­£
  //   Serial.print("æ¡¶æ»š");
  //   Serial.print(AcAngle_tg);
  //   //æŠ¬å¤´ æŠ¬å¤´ä¸ºæ­£ ä½Žå¤´ä¸ºè´Ÿ
  //   Serial.print(" æŠ¬å¤´");
  //   Serial.print(AcAngle_tt);
  //   //æ–¹å‘ å·¦è¾¹ä¸ºæ­£ å³è¾¹ä¸ºè´Ÿ
  //   //è½¦å¤´ä¸ºé™åŽ‹æ¨¡å—ä¸€æ–?  //   Serial.print(" æ–¹å‘");
  //   Serial.println(AcAngle_fx);
  //   Serial.println(" ");
  //     delay(500);
  /*
    accæ˜¯åŠ é€Ÿåº¦
    gyroæ˜¯è§’åº¦å˜åŒ–çŽ‡(è§’åŠ é€Ÿåº¦)
    angleæ˜¯è§’åº?    magåœ°ç£/ç”µå­ç½—ç›˜
    Zæ˜¯æ–œç€å€¾æ–œçš„è§’åº?  */
}
void backGroundSystem()
{
  Read_Moto_V(3);
  while (Serial2.available())
  {
    JY901.CopeSerialData(Serial2.read()); //Call JY901 data cope function
  }
  wheel_speed_pub.publish(&str_wheel);
}

void loop()
{
  static unsigned long prev_control_time = 0;
  static unsigned long prev_imu_time = 0;
  static unsigned long prev_debug_time = 0;
  static bool imu_is_initialized;
  backGroundSystem();

  if ((millis() - prev_control_time) >= (1000 / COMMAND_RATE))
  {
    moveBase();
    prev_control_time = millis();
  }

  //this block stops the motor when no command is received
  if ((millis() - g_prev_command_time) >= 1000)
  {
    stopBase();
  }

  // tim = millis();
  //     if((tim-lasttim)>1000)
  //     {
  //     // setSpeed(LEFT,0);
  //     // setSpeed(RIGHT,0);
  //     // Run_Moto_F(0,0,1,1);
  //     // Run_Moto_F(0,0,3,3);
  //     // Run_Moto_F(0,0,2,2);
  //     }
  //this block publishes the IMU data based on defined rate
  if ((millis() - prev_imu_time) >= (1000 / IMU_PUBLISH_RATE))
  {
    //sanity check if the IMU is connected
    if (!imu_is_initialized)
    {
      imu_is_initialized = true;

      if (imu_is_initialized)
        nh.loginfo("IMU Initialized");
      else
        nh.logfatal("IMU failed to initialize. Check your IMU connection.");
    }
    else
    {
      getAngle();
    }

    prev_imu_time = millis();
  }
  nh.spinOnce();
  // delay(1);
}