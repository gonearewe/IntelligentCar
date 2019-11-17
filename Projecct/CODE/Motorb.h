#ifndef MOTOR_CTRL_H
#define MOTOR_CTRL_H
#include "headfile.h"

#include "common.h"

void Motor_Output(void);
void Motor_ctrl(void);
int PWM_Limit(int PWM,int Max,int Min);

#endif