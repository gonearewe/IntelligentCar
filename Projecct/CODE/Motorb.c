#include "Motorb.h" 
#include "headfile.h"
/*
    ������ƺ����������б�д�ٶȿ����㷨
*/
extern float Errorcam;
int MotorPWM;

int PWM_Limit(int PWM,int Max,int Min)   //�޷�����
{
    if(PWM > Max)
        PWM = Max;
    if(PWM < Min)
        PWM = Min;
    return PWM;
}

void Motor_Output(void)
{
    // TEST
    MotorPWM = PWM_Limit(500,800,200);  //�޷�PWM

    ctimer_pwm_duty(TIMER1_PWMCH0_A18, 80);
    ctimer_pwm_duty(TIMER1_PWMCH1_A20, 80);
    ctimer_pwm_duty( TIMER2_PWMCH1_B4, 80);
    ctimer_pwm_duty( TIMER2_PWMCH0_B5, 80);
    
}


     
/**********************************************************************************************************/
void Motor_ctrl()
{
  
  Motor_Output();
  
}  