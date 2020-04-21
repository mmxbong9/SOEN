// 03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pointer.h"

using namespace SOEN;

int main()
{
    AboutVariableAndPointer();
    Pointer();
    ConstPointer();
    PointerArray();
    ArrayToPointerDecay();

    int i = 5;
    plusref(&i);
    printf("결과 = %d\n", i);

    int ar[] = { 1,2,3,4,5 };
    int* p1, * p2, * p3;

    p1 = &ar[0];
    p2 = &ar[4];
    p3 = p1 + (p2 - p1) / 2;

    printf("중간의 요소 = %d | %d + ( %d - %d ) / 2\n", *p3, *p1, *p2, *p1);
}
