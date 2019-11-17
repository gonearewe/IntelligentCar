#include <stdlib.h>

#include "headfile.h"
#include "Getline_ele.h"
/*
    电磁采值思路参考
      由于电感采集的信号为交流信号，所以可以多次采值覆盖一个信号周期(sensor[][SampleNum],其中SampleNum为采集次数，可自行设定)
    提取其中最大值和最小值并作差，得到峰峰值(peak[])
*/

uint16 sensor[5][SampleNum] = {0};
uint8 peak[5] = {0};
int AD = 0;

void peak_calc()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < SampleNum; j++)
        {
            sensor[i][j] = adc_convert(ADCCH_enum ch, ADCRES_enum resolution); //电感的一次采值
        }

        uint16 tmp[SampleNum] = {0};
        for (int c = 0; c < SampleNum; c++)
        {
            tmp[c] = sensor[i][c];
        }

        // void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
        qsort(tmp, SampleNum, sizeof(uint16), cmpfunc);

        peak[i] = (tmp[SampleNum - 1] - tmp[0]) / 2;
    }
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}