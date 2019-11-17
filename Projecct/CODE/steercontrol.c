#include "steercontrol.h"
#include "headfile.h"

/*
  方向控制函数，需自行编写转向策略
*/

int   Rudder_Min;
int   Rudder_Max;
int32  RudderPWM;
extern float Errorcam;

void Rudder_ctrl(void)
{
  
  RudderPWM = PWM_Limit(int PWM,int Max,int Min);
  ctimer_pwm_duty(CTIMER_PWMCH_enum pwmch, uint32 duty);
}