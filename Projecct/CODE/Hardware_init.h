#ifndef _HARDWARE_INIT_H
#define _HARAWARE_INIT_H
#include "headfile.h"
#define SPEEDL_PIN  TIMER0_COUNT1_A2
#define SPEEDR_PIN  TIMER3_COUNT0_A4

//定义方向引脚
#define SPEEDL_DIR  A3
#define SPEEDR_DIR  A5
void Hardware_init(void);


#endif