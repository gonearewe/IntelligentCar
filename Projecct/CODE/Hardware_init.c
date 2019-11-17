#include "Hardware_init.h"
#include "headfile.h"

/*
    硬件系统初始化
*/

void Hardware_init(void)
{
    get_clk();
    camera_init(); //初始化摄像头

    EnableInterrupts; //使能中断
    pit_init_ms(5);   //定时器中断时间设置

    /*****************************舵机初始化*************************************/

    ctimer_pwm_init(TIMER4_PWMCH0_A6, 300, 50);

    /*****************************电机初始化*************************************/

    // PWM 1,2,3,4 in order
    ctimer_pwm_init(TIMER1_PWMCH0_A18, 50, 50);
    ctimer_pwm_init(TIMER1_PWMCH1_A20, 50, 50);
    ctimer_pwm_init(TIMER2_PWMCH1_B4, 50, 50);
    ctimer_pwm_init(TIMER2_PWMCH0_B5, 50, 50);

    /*****************************编码器初始化**********************************/

    //    ctimer_count_init(CTIMER_COUNTCH_enum countch);
    //    gpio_init(PIN_enum pin, GPIODIR_enum dir, uint8 dat, uint32 pull);

    /*****************************电磁初始化**********************************/
    //  通道1              A10
    //  通道2              A15
    //  通道3              A16
    //  通道4              A31
    //  通道5              B0
    //  通道6              A23
    adc_init(ADC_CH0_A10);
    adc_init(ADC_CH3_A15);
    adc_init(ADC_CH4_A16);
    adc_init(ADC_CH5_A31);
}