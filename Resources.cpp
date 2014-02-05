// emo 的声音与眼睛闪烁相关的子程序

#include "Resources.h"


/*
 * emoBlink01 - emo 眼睛闪烁模式 1
 * 输出：emo 眼睛亮度
 */
uint8_t emoBlink01()
{
  static uint16_t eyeCounter;
  eyeCounter++;
  if(eyeCounter <= 25)
  {
    return eyeCounter;
  }
  else
  {
    if(26 == eyeCounter)
    {
      return 0;
    }
    else if(30 == eyeCounter)
    {
      return 255;
    }
    else if(40 == eyeCounter)
    {
      return 0;
    }
    else if(100 <= eyeCounter)
    {
      eyeCounter = 0;
    }
  }
}

/*
 * emoSayOut - emo 声音模式 1
 * 输入：emo声音输出引脚和声音模式
 */
void emoSayOut(uint8_t mPin, uint8_t var)
{
  switch (var) {
  case 1://sa jiao
    for(int i=200;i<990;i++){
      tone(mPin,i,10);
    }
    for(int i=990;i>200;i--){
      tone(mPin,i,10);
    }
    for(int i=200;i<350;i++){
      tone(mPin,i,10);
    }
    delay(500);
    break;
  case 2: // di di
    tone(mPin,900,200);
    delay(200);
    tone(mPin,900,200);
    delay(200);
    break;
  case 3: // de li
    tone(mPin,300,400);
    delay(50);
    tone(mPin,400,250);
    delay(50);
    break;
  case 4: // du da
    tone(mPin,300,500);
    delay(100);
    for(int i=300;i<500;i++){
      tone(mPin,i,5);
    }
    delay(50);
    break;
  case 5: // du~ do~~
    for(int i=450;i<650;i++){
      tone(mPin,i);
      delay(1);
    }
    noTone(mPin);
    delay(500);
    //
    for(int i=450;i< 750;i++){
      tone(mPin,i);
      delay(1);
    }
    noTone(mPin);
    delay(500);
    break;
  case 6: // du_-`~
    for(int i=1000;i<1400;i++){
      tone(mPin,i);
      delay(1);
    }
    noTone(mPin);
    delay(100);
    break;
  case 7: // di- dang-_
    tone(mPin,1200);
    delay(100);
    noTone(mPin);
    delay(100);
    for(int i=900;i>300;i--){
      tone(mPin,i);
      delay(1);
    }
    noTone(mPin);
    delay(100);
    break;
  case 8: // dang~ dang-
    tone(mPin,1100);
    delay(120);
    noTone(mPin);
    delay(100);
    tone(mPin,600);
    delay(350);
    noTone(mPin);
    delay(100);
    break;
  case 9: //u- u~
    tone(mPin,150);
    delay(400);
    noTone(mPin);
    delay(250);
    tone(mPin,200);
    delay(400);
    noTone(mPin);
    delay(100);
    break;
  case 12: // bee boo
    for(int i=300;i<400;i++){
      tone(mPin,i);
      delay(1);
    }
    tone(mPin,400);
    delay(200);
    for(int i=400;i>350;i--){
      tone(mPin,i);
      delay(1);
    }
    tone(mPin,350);
    delay(200);
    noTone(mPin);
    break;
  default: //bee bee
    tone(mPin,500,300);
    delay(400);
    tone(mPin,500,300);
    delay(400);
  }
}
