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
        printf("0 ~ 255 사이의 수를 입력하시요.(끝낼때 -1) : ");
        scanf("%d", &input);

        if (input == -1)
        {
            break;
        }

        hi = input >> 4;
        low = input & 0xf;

        char cHi  = hi + '0' + (hi > 9) * 7;
        char cLow = low + '0' + (low > 9) * 7;

        printf("입력한 수의 16진 표기 = %c%c\n", cHi, cLow);
    }
}
