
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

//you
const int R3S = 12;
const int R3A = 25;
const int R3B = 26;
const int L3A = 24;
const int L3B = 23;
const int L3S = 13;
//zuo



const int L1A = 36;
const int L1B = 35;
const int L1S = 9;
const int L2S = 6;
const int L2A = 38;
const int L2B = 39;


const int R1A = 31;
const int R1B = 30;
const int R1S = 7;
const int R2S = 6;
const int R2A = 28;
const int R2B = 29;

int H_L1_B = 0;
int H_R1_B = 0;
int H_L2_B = 0;
int H_R2_B = 0;
int H_L3_B = 0;
int H_R3_B = 0;
volatile float motorL1 = 0; //中断变量，左轮子脉冲计数
volatile float motorR1 = 0; //中断变量，右轮子脉冲计数
volatile float motorL2 = 0; //中断变量，左轮子脉冲计数
volatile float motorR2 = 0; //中断变量，右轮子脉冲计数
volatile float motorL3 = 0; //中断变量，左轮子脉冲计数
volatile float motorR3 = 0; //中断变量，右轮子脉冲计数
float v1 = 0; //单位cm/s
float v2 = 0; //单位cm/s
float v3 = 0; //单位cm/s
float v4 = 0; //单位cm/s
float v5 = 0; //单位cm/s
float v6 = 0; //单位cm/s
// Servo myservo;

  /**
     函数作用：读取左右电机的速度
     返回值：  无
     
    r3------l3
    l2------l1
    r2------r1

   * */
void Read_Moto_V() {

  //这是读取电机速度的函数
  unsigned long nowtime = 0;
  motorL1 = 0;
  motorR1 = 0;
  motorL2 = 0;
  motorR2 = 0;
  motorL3 = 0;
  motorR3 = 0;
  nowtime = millis() + 50; //读50毫秒
  attachInterrupt(digitalPinToInterrupt(MotorL1countA), Read_Moto_L1, RISING); //左轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MotorR1countA), Read_Moto_R1, RISING); //右轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MotorL2countA), Read_Moto_L2, RISING); //左轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MotorR2countA), Read_Moto_R2, RISING); //右轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MotorL3countA), Read_Moto_L3, RISING); //左轮脉冲开中断计数
  attachInterrupt(digitalPinToInterrupt(MotorR3countA), Read_Moto_R3, RISING); //右轮脉冲开中断计数
  while (millis() < nowtime); //达到50毫秒关闭中断
  detachInterrupt(digitalPinToInterrupt(MotorL1countA));//左轮脉冲关中断计数
  detachInterrupt(digitalPinToInterrupt(MotorR1countA));//右轮脉冲关中断计数
  detachInterrupt(digitalPinToInterrupt(MotorL2countA));//左轮脉冲关中断计数
  detachInterrupt(digitalPinToInterrupt(MotorR2countA));//右轮脉冲关中断计数
  detachInterrupt(digitalPinToInterrupt(MotorL3countA));//左轮脉冲关中断计数
  detachInterrupt(digitalPinToInterrupt(MotorR3countA));//右轮脉冲关中断计数
float V_L1,V_R1,V_L2,V_R2,V_L3,V_R3;
V_L1=V_R1=V_L2=V_R2=V_L3=V_R3 = 0;
  //390来自转速比1:30中的30乘以编码器线数13
  V_L1 = ((motorL1 / 390) * 6.5 * PI) / 0.05; //单位cm/s
  V_R1 = ((motorR1 / 390) * 6.5 * PI) / 0.05; //单位cm/s
  V_L2 = ((motorL2 / 130) * 6.5 * PI) / 0.05; //单位cm/s
  V_R2 = ((motorR2 / 130) * 6.5 * PI) / 0.05; //单位cm/s
  V_L3 = ((motorL3 / 390) * 6.5 * PI) / 0.05; //单位cm/s
  V_R3 = ((motorR3 / 390) * 6.5 * PI) / 0.05; //单位cm/s
  v1 = V_L1;
  v2 = V_R1;
  v3 = V_L2;
  v4 = V_R2;
  v5 = V_L3;
  v6 = V_R3;
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
// 变压器一边为车头

}

void Read_Moto_L1() {
  
  H_L1_B = digitalRead(MotorL1countB);//0是倒转 1是正转
  if (H_L1_B == 1)
  {
    motorL1++;
  } else
  {
    motorL1--;
  }
  //  Serial.print("Moto LB = ");
  //  Serial.print(motorL);
}
void Read_Moto_L2() {
  /**
     函数作用：读取左电机的编码器
     返回值：  无
   * */
  H_L2_B = digitalRead(MotorL2countB);//0是倒转 1是正转
  if (H_L2_B == 0)
  {
    motorL2--;
  } else
  {
    motorL2++;
  }
  //  Serial.print("Moto LB = ");
  //  Serial.print(motorL);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
void Read_Moto_L3() {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
  /**
     函数作用：读取左电机的编码器
     返回值：  无
   * */
  H_L3_B = digitalRead(MotorL3countB);//0是倒转 1是正转
  if (H_L3_B == 1)
  {
    motorL3++;
  } else
  {
    motorL3--;
  }
  //  Serial.print("Moto LB = ");
  //  Serial.print(motorL);
}
//读取右轮脉冲
void Read_Moto_R1() {
  /**
     函数作用：读取右电机的编码器
     返回值：  无
   * */
  H_R1_B = digitalRead(MotorR1countB);//0是倒转 1是正转
  if (H_R1_B == 0)
  {
    motorR1++;
  } else
  {
    motorR1--;
  }


  //  Serial.print("\tMoto RB = ");
  //  Serial.println(motorR);
}
void Read_Moto_R3() {
  /**
     函数作用：读取右电机的编码器
     返回值：  无
   * */
  H_R3_B = digitalRead(MotorR3countB);//0是倒转 1是正转
  if (H_R3_B == 1)
  {
    motorR3--;
  } else
  {
    motorR3++;
  }


  //  Serial.print("\tMoto RB = ");
  //  Serial.println(motorR);
}
void Read_Moto_R2() {
  /**
     函数作用：读取右电机的编码器
     返回值：  无
   * */
  H_R2_B = digitalRead(MotorR2countB);//0是倒转 1是正转
  if (H_R2_B == 1)
  {
    motorR2--;
  } else
  {
    motorR2++;
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
void Run_Moto_F(int L_v, int R_v, int L_Moto,int R_Moto) {
  int L_Motor_A,R_Motor_A,L_Motor_B,R_Motor_B,L_Motor_SPEED,R_Motor_SPEED;
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
  else if ( L_v < -250 )
  {
    L_v = -250;
  }
  if (R_v > 250)
  {
    R_v = 250;
  }
  else if ( R_v < -250 )
  {
    R_v = -250;
  }
  //前进，可设置左右轮速度
  if (L_v > 0) {
    digitalWrite(L_Motor_A, 0);
    digitalWrite(L_Motor_B, HIGH);
    analogWrite(L_Motor_SPEED, L_v);
  } else if (L_v < 0) {
    digitalWrite(L_Motor_A, HIGH);
    digitalWrite(L_Motor_B, 0);
    analogWrite(L_Motor_SPEED, -L_v);
  } else
  {
    digitalWrite(L_Motor_A, 0);
    digitalWrite(L_Motor_B, 0);
    analogWrite(L_Motor_SPEED, 0);
  }
  if (R_v > 0) {
    digitalWrite(R_Motor_A, HIGH);
    digitalWrite(R_Motor_B, 0);
    analogWrite(R_Motor_SPEED, R_v);
  } else if (R_v < 0) {
    digitalWrite(R_Motor_A, 0);
    digitalWrite(R_Motor_B, HIGH);
    analogWrite(R_Motor_SPEED, -R_v);
  } else
  {
    digitalWrite(R_Motor_A, 0);
    digitalWrite(R_Motor_B, 0);
    analogWrite(R_Motor_SPEED, 0);
    // delay(2000);
  }
}



void setup() {
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

  delay(1000);

  Serial.begin(9600);
  Serial.println("BRGIN");


}


                                                                           
void loop() { 
Read_Moto_V();
// Run_Moto_F(100,0,L1A,R1A,L1B,R1B,L1S,R1S);
//  Run_Moto_F(100,0,L2A,R2A,L2B,R2B,L2S,R2S);

// // Run_Moto_F(100,100,1,0);
// Run_Moto_F(100,100,1,0);
// // Run_Moto_F(100,100,1,0);
// delay(2000);
Run_Moto_F(100,0,3,0);

// Run_Moto_F(100,50,1,0);

// delay(2000);
}
