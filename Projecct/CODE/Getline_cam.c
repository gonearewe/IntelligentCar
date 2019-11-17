#include "headfile.h"
#include "Getline_cam.h"

/*
    ����ͷ���߲ο�
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
    //�����ʼ��
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
        //��һ������,���������߿ɲο�  imageΪ����ͷ�ɼ�����
        for (int j = Midpri; j >= 6; j--)  // column
        { //���м�����Ѱ��
            if ((image[i][j] - image[i][j - 5]) >= 30)
            { //�ҵ���߽磨����ͷ�Թ��ս�Ϊ���У�����ֵ�����ο���

                Left[0] = j;      //��¼��߽�
                Left_Flag[0] = 1; //�ҵ���߽��־λ
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

            Middle[i] = (Right[i] + Left[i]) / 2; //��ȡ�е�
        }
    }
}
