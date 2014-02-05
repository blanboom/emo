// 实现 emo 各部分功能的子程序

#include "Functions.h"
#include "Resources.h"
#include "CapacitiveSensor.h"


// 输入部分引脚
#define EMO_EAR 1    // 声音感应
#define EMO_EYE_IN 0 // 光线感应
#define EMO_SKIN_0 4 // 触摸感应引脚 1
#define EMO_SKIN_1 2 // 触摸感应引脚 2
CapacitiveSensor cs_emoSkin = CapacitiveSensor(EMO_SKIN_0,EMO_SKIN_1);  // 触摸感应对象


// 灵敏度
#define EMO_EAR_SENTIVITY 600
#define EMO_EYE_SENTIVITY 600
#define EMO_TOUCH_SENTIVITY 2000

// 输出部分引脚
#define EMO_MOUTH 9      // 声音输出
#define EMO_EYE_OUT_R 6  // 光线输出-红
#define EMO_EYE_OUT_G 5  // 光线输出-绿
#define EMO_EYE_OUT_B 4  // 光线输出-蓝

boolean emoHeard = 0;       // emo 听到了~
boolean emoSaw = 0;         // emo 看到了~
boolean emoTouched = 0;     // emo 被触摸~
boolean sensorLock = 0;     // 传感器锁，一次只能使一种传感器被触发

/************************* 输入部分 *************************/

/* 声音感应 */
void emoHear()
{
  if(0 == sensorLock && EMO_EAR_SENTIVITY < analogRead(EMO_EAR))
  {
    emoHeard = 1;
    sensorLock = 1;
  }
}

/* 光线感应 */
void emoSee()
{
  if(0 == sensorLock && EMO_EYE_SENTIVITY < analogRead(EMO_EYE_IN))
  {
    emoSaw = 1;
    sensorLock = 1;
  }

}

/* 触摸 */
void emoTouch()
{
  if(0 == sensorLock && EMO_EYE_SENTIVITY < cs_emoSkin.capacitiveSensor(30))
  {
    emoTouched = 1;
    sensorLock = 1;
  }
}

/*********************** 输入部分结束 ************************/


/************************* 输出部分 *************************/

/* 蜂鸣器 */
void emoSay()
{
  if(emoSaw)
  {
    emoSayOut(EMO_MOUTH, 1);
    emoSaw = 0;
    sensorLock = 0;
    analogWrite(EMO_EYE_OUT_G, 0);  // 顺便关灯
  }
  else if(emoTouched)
  {
    emoSayOut(EMO_MOUTH, 8);
    emoTouched = 0;
    sensorLock = 0;
    analogWrite(EMO_EYE_OUT_G, 0);  // 顺便关灯
  }
  else if(emoHeard)
  {
    emoSayOut(EMO_MOUTH, 2);
    emoHeard = 0;
    sensorLock = 0;
    analogWrite(EMO_EYE_OUT_R, 0);  // 顺便关灯
  }
}

/* 眼睛闪烁 */
void emoBlink()
{
  if(emoSaw)
  {
    analogWrite(EMO_EYE_OUT_G, emoBlink01());
  }
  else if(emoTouched)
  {
    analogWrite(EMO_EYE_OUT_G, emoBlink01());
  }
  else if(emoHeard)
  {
    analogWrite(EMO_EYE_OUT_R, emoBlink01());
  }
}
/*********************** 输出部分结束 ************************/


/************************* 其他部分 *************************/

/* 初始化 */
void hardwareInit()
{
  pinMode(EMO_EAR, INPUT);
  pinMode(EMO_EYE_IN, INPUT);
  pinMode(EMO_SKIN_0, INPUT);
  pinMode(EMO_SKIN_1, INPUT);
  pinMode(EMO_MOUTH, OUTPUT);
  pinMode(EMO_EYE_OUT_R, OUTPUT);
  pinMode(EMO_EYE_OUT_G, OUTPUT);
  pinMode(EMO_EYE_OUT_B, OUTPUT);

  cs_emoSkin.set_CS_AutocaL_Millis(0xFFFFFFFF); 
}

/*********************** 其他部分结束 ************************/

