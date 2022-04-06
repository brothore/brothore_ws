#include <Wire.h>
#include <JY901.h>
float Acc_lr, Acc_fb, Acc_g;
float Angle_tg, Angle_tt, Angle_fx;
float AcAngle_tg, AcAngle_tt, AcAngle_fx;

/*
http://item.taobao.com/item.htm?id=43511899945
Test on mega2560.
JY901   mega2560
TX <---> 0(Rx)
*/
void setup() 
{
  Serial.begin(9600);  
  Serial2.begin(9600);
  Serial.println("BEGIN");
}
void getAngle() {

  Acc_fb = ((float)JY901.stcAcc.a[0] / 32768 * 16);
  Acc_lr = ((float)JY901.stcAcc.a[1] / 32768 * 16);
  Acc_g = ((float)JY901.stcAcc.a[2] / 32768 * 16);
  AcAngle_tg = ((float)JY901.stcGyro.w[0] / 32768 * 2000);
  AcAngle_tt = ((float)JY901.stcGyro.w[1] / 32768 * 2000);
  AcAngle_fx = ((float)JY901.stcGyro.w[2] / 32768 * 2000);
  Angle_tg = ((float)JY901.stcAngle.Angle[0] / 32768 * 180);//x
  Angle_tt = ((float)JY901.stcAngle.Angle[1] / 32768 * 180);//y
  Angle_fx = ((float)JY901.stcAngle.Angle[2] / 32768 * 180);//z


  // Serial.print("加速度:");
  // Serial.print("前后: ");
  // Serial.println(Acc_fb);
  // // 后退是正的，前进是负的
  // Serial.print("左右: ");
  // Serial.println(Acc_lr);
  // //左负右正
  // Serial.print("\t垂直:");
  // Serial.println(Acc_g);
  // Serial.print("角度:");
  Serial.print("桶滚");
  Serial.print(Angle_tg);
  Serial.print(" 抬头");
  Serial.print(Angle_tt);
  Serial.print(" 方向");
  Serial.println(Angle_fx);
  // Serial.print("角加速度:");
  // //桶滚 右边为负 左边为正
  // Serial.print("桶滚");
  // Serial.print(AcAngle_tg);
  // //抬头 抬头为正 低头为负
  // Serial.print(" 抬头");
  // Serial.print(AcAngle_tt);
  // //方向 左边为正 右边为负
  // //车头为降压模块一方
  // Serial.print(" 方向");
  // Serial.println(AcAngle_fx);
  Serial.println(" ");
    delay(500);
  /*
    acc是加速度
    gyro是角度变化率(角加速度)
    angle是角度
    mag地磁/电子罗盘
    Z是斜着倾斜的角度
  */
}
void loop() 
{
    getAngle();


  while (Serial2.available()) 
  {
    JY901.CopeSerialData(Serial2.read()); //Call JY901 data cope function
  }

}


