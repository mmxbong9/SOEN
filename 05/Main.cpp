// 05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

int main()
{
    int input;
    int hi;
    int low;

    for (;;)
    {
        printf("0 ~ 255 ������ ���� �Է��Ͻÿ�.(������ -1) : ");
        scanf("%d", &input);

        if (input == -1)
        {
            break;
        }

        hi = input >> 4;
        low = input & 0xf;

        char cHi  = hi + '0' + (hi > 9) * 7;
        char cLow = low + '0' + (low > 9) * 7;

        printf("�Է��� ���� 16�� ǥ�� = %c%c\n", cHi, cLow);
    }
}
