#include "Hardware_init.h"
#include "headfile.h"

/*
    Ӳ��ϵͳ��ʼ��
*/

void Hardware_init(void)
{
    get_clk();
    camera_init(); //��ʼ������ͷ

    EnableInterrupts; //ʹ���ж�
    pit_init_ms(5);   //��ʱ���ж�ʱ������

    /*****************************�����ʼ��*************************************/

    ctimer_pwm_init(TIMER4_PWMCH0_A6, 300, 50);

    /*****************************�����ʼ��*************************************/

    // PWM 1,2,3,4 in order
    ctimer_pwm_init(TIMER1_PWMCH0_A18, 50, 50);
    ctimer_pwm_init(TIMER1_PWMCH1_A20, 50, 50);
    ctimer_pwm_init(TIMER2_PWMCH1_B4, 50, 50);
    ctimer_pwm_init(TIMER2_PWMCH0_B5, 50, 50);

    /*****************************��������ʼ��**********************************/

    //    ctimer_count_init(CTIMER_COUNTCH_enum countch);
    //    gpio_init(PIN_enum pin, GPIODIR_enum dir, uint8 dat, uint32 pull);

    /*****************************��ų�ʼ��**********************************/
    //  ͨ��1              A10
    //  ͨ��2              A15
    //  ͨ��3              A16
    //  ͨ��4              A31
    //  ͨ��5              B0
    //  ͨ��6              A23
    adc_init(ADC_CH0_A10);
    adc_init(ADC_CH3_A15);
    adc_init(ADC_CH4_A16);
    adc_init(ADC_CH5_A31);
}