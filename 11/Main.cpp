// 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

void arDump(void* array, int length);
void arDump(void* array, int length)
{
    int i;

    for (i = 0; i < length; i++)
    {
        printf("%02X ", *(unsigned char*)array + i);
    }
    printf("\n");
}

void SubArray();
void SubArray()
{
    // SubArray
    unsigned char ari[2][3] = { {1,2,3}, {4,5,6} };

    arDump(ari, sizeof(ari));
    arDump(ari[0], sizeof(ari[0]));
    arDump(ari[1], sizeof(ari[1]));

    // SubArray2
    char ar[] = "한국을 빛낸 사람들";
    char ars[2][3][10] = {
        {"이순신", "강감찬", "강감찬"},
        {"유관순", "을지문덕", "신사임당"}
    };

    printf("ar 배열 = %s\n", ar);
    printf("ars[1][1] = %s\n", ars[1][1]);
    printf("*(*(ars+1)+1) = %s\n", *(*(ars + 1) + 1));
}

void ArrayPointer();
void ArrayPointer()
{
    char arps[5][9] = { "고양이", "개", "오랑우탄", "돼지", "지렁이" };
    char(*ps)[9];
    ps = arps;

    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%s\n", *ps++);
    }
}

int GetTotalForWeek(int(*pa)[7]);
int GetTotalForWeek(int(*pa)[7])
{
    int i, sum = 0;

    for (i = 0; i < 7; i++)
    {
        sum += pa[0][i];
    }

    return sum;
}

void ArrayArgument();
void ArrayArgument()
{
    int ari[][7] =
    {
        {1,2,3,4,5,6,7},
        {8,9,10,11,12,13,14},
        {15,16,17,18,19,20,21}
    };

    int i;

    for (i = 0; i < 3; i++)
    {
        printf("%d주의 판매량 = %d\n", i + 1, GetTotalForWeek(&ari[i]));
    }
}

//void OutArray(int *ar)
//void OutArray(int ar[])
void OutArray(int ar[5])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%d번째 = %d\n", i, ar[i]);
    }
}

//int GetArSum(int* ar, int size);
//int GetArSum(int ar[], int size);
int GetArSum(int ar[], int size);
int GetArSum(int ar[], int size)
{
    int i, sum = 0;

    for (i = 0; i < size; i++)
    {
        sum += ar[i];
    }
    return sum;
}

void ArrayPameter();
void ArrayPameter()
{
    int ar[] = { 1,2,3,4,5 };
    OutArray(ar);

    int ar1[] = { 1,2,3,4,5 };
    int ar2[] = { 6,7,8,9,10,11 };

    printf("ar1 총합 = %d\n", GetArSum(ar1, sizeof(ar) / sizeof(ar[0])));
    printf("ar2 총합 = %d\n", GetArSum(ar2, sizeof(ar2) / sizeof(ar2[0])));
}

void StaticMallocArray();
void StaticMallocArray()
{
    int i;

    char(*p)[4] = (char(*)[4])malloc(3 * 4 * sizeof(char));
    strcpy(p[0], "dog");
    strcpy(p[1], "cow");
    strcpy(p[2], "cat");

    for (i = 0; i < 3; i++)
    {
        puts(p[i]);
    }
    free(p);
}

void DynamicMallocArray();
void DynamicMallocArray()
{
    int n = 3, m = 4;
    int i;

    char** p;
    p = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        p[i] = (char*)malloc(m * sizeof(char));
    }
    strcpy(p[0], "dog");
    strcpy(p[1], "cow");
    strcpy(p[2], "cat");

    for (i = 0; i < n; i++)
    {
        puts(p[i]);
    }

    for (i = 0; i < n; i++)
    {
        free(p[i]);
    }
    free(p);
}

void AmpersaneArray();
void AmpersaneArray()
{
    int ar[5] = { 1,2,3,4,5 };
    int* p1;
    int(*p2)[5];

    p1 = ar;
    p2 = &ar;

    printf("before = %p\n", p1);
    printf("before = %p\n", p2);

    p1++;
    p2++;

    printf("after = %p\n", p1);
    printf("after = %p\n", p2);
}

int main()
{
    std::cout << "11. array and pointer\n";

    SubArray();
    ArrayPointer();
    ArrayArgument();
    ArrayPameter();
    StaticMallocArray();
    DynamicMallocArray();
    AmpersaneArray();
}
