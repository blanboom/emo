// emo 0.1
// 待解决问题：
//     1. 电容触摸需要屏蔽中断一段时间，可能会影响任务调度器在某些时间进入中断，进而影响系统的时间精度. 不过对于现有的程序来说不需要较高的时间精度.
//     2. 电容触摸和 Arduino 的声音输出库都需要用到中断或定时器，在更换输出引脚或添加其他功能时，可能会与任务调度器产生潜在的冲突.
//
// 2014 - 02 - 04

#include "Functions.h"
#include "Scheduler.h"

void setup()
{
  // 初始化

  hardwareInit();

  Sch.init(); 

  Sch.addTask(emoHear, 0, 250, 1);
  Sch.addTask(emoSee, 40, 250, 1);
  Sch.addTask(emoTouch, 70, 250, 1);
  Sch.addTask(emoSay, 121, 100, 1);
  Sch.addTask(emoBlink, 13, 10, 0);

  Sch.start();
}

void loop()
{
  Sch.dispatchTasks();
}

