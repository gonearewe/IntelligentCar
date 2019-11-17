#ifndef RUDDER_CTRL_H
#define RUDDER_CTRL_H
#include "headfile.h"

#include "common.h"

void Rudder_ctrl(void);
extern int PWM_Limit(int PWM,int Max,int Min);
#endif