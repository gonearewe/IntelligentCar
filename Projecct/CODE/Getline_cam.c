#include "headfile.h"
#include "Getline_cam.h"

/*
    摄像头提线参考
*/
// Height: 120
// Width:  188
uint16 Right[C_H];
uint16 Left[C_H];
uint16 Middle[C_H];
uint8 Right_Flag[C_H];
uint8 Left_Flag[C_H];  // Why 70 ?
int Midpri = 94;

void getline_others()
{
    //数组初始化
    for (int c = 0; c <= C_H - 1; c++)
    {

        Right[c] = 188;
        Left[c] = 0;
        Middle[c] = 94;

        Right_Flag[c] = 0;
        Left_Flag[c] = 0;
    }

    for (int i = MT9V032_H - 2; i > 0; i++) // row
    {
        //第一行提线,其余行提线可参考  image为摄像头采集数据
        for (int j = Midpri; j >= 6; j--)  // column
        { //从中间向左寻找
            if ((image[i][j] - image[i][j - 5]) >= 30)
            { //找到左边界（摄像头对光照较为敏感，该阈值仅供参考）

                Left[0] = j;      //记录左边界
                Left_Flag[0] = 1; //找到左边界标志位
                break;
            }
        }

        for (int j = Midpri; j <= MT9V032_W - 7; j++)
        {

            if ((image[i][j] - image[i][j + 5]) >= 30)
            {
                Right[0] = j;
                Right_Flag[0] = 1;
                break;
            }
        }

        if (Left_Flag[i] == 1 && Right_Flag[i] == 1)
        {

            Middle[i] = (Right[i] + Left[i]) / 2; //提取中点
        }
    }
}
