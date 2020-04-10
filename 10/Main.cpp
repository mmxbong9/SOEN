// 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

namespace SOEN
{
    void PointerSum();
    void PointerSum()
    {
        int ar[] = { 10, 20, 30, 40, 50, 0 };
        int* ptr = ar;
        int sum = 0;

        while (*ptr)
        {
            sum += *ptr++;
            printf("sum = %d\n", sum);
        }
    }

    void VoidPointer();
    void VoidPointer()
    {
        int i = 1234;
        void* vp;

        vp = &i;
        printf("%d\n", *(int *)vp);
    }

    void VoidPointer2();
    void VoidPointer2()
    {
        int ar[] = { 1, 2, 3, 4, 5 };
        void* vp;

        vp = ar;
        vp = (int *)vp + 1;
        printf("%d\n", *(int *)vp);
    }

    void UsingVoidPointer();
    void UsingVoidPointer()
    {
        int ari[10];
        char arc[20];
        double ard[30];

        memset(ari, 0, sizeof(ari));
        memset(arc, 0, sizeof(arc));
        memset(ard, 0, sizeof(ard));
    }

    void ArrayDump(void* array, int length);
    void ArrayDump(void* array, int length)
    {
        int i;
        for (i = 0; i < length; i++)
        {
            printf("%02X ", *((unsigned char*)array + i));
        }
        printf("\n\n");
    }

    void VoidDump()
    {
        int ari[] = { 1, 2, 3, 4, 5 };
        char arc[] = "Pointer";

        ArrayDump(ari, sizeof(ari));
        ArrayDump(arc, sizeof(arc));
    }

    void DynamicAllocation();
    void DynamicAllocation()
    {
        int* arScore;
        int i, stNum;
        int sum;

        printf("�л����� �Է��ϼ��� : ");
        scanf("%d", &stNum);
        arScore = (int*)malloc(stNum * sizeof(int));
        if (arScore == NULL)
        {
            printf("�޸𸮰� �����մϴ�.\n");
            exit(0);
        }

        for (i = 0; i < stNum; i++)
        {
            printf("%d �� �л��� ������ �Է��ϼ��� : ", i + 1);
            scanf("%d", &arScore[i]);
        }

        sum = 0;
        for (i = 0; i < stNum; i++)
        {
            sum += arScore[i];
        }

        printf("\n ������ %d ���̰� ����� %d ���Դϴ�.\n", sum, sum / stNum);
        free(arScore);
    }

    void DynamicReAllocation();
    void DynamicReAllocation()
    {
        int* ar;

        ar = (int*)malloc(5 * sizeof(int));
        ar[4] = 1234;

        ar = (int*)realloc(ar, 10 * sizeof(int));
        ar[9] = 5678;

        printf("ar[4] = %d, ar[9] = %d", ar[4], ar[9]);
        free(ar);
    }

    void PointerToPointer();
    void PointerToPointer()
    {
        int i;
        int* pi;
        int** ppi;

        i = 1234;
        pi = &i;
        ppi = &pi;

        printf("%d\n ", **ppi);
    }

    void InputName(char** pName);
    void InputName(char** pName)
    {
        *pName = (char*)malloc(12);
        strcpy(*pName, "Cabin");
    }

    void UsingDoublePointer();
    void UsingDoublePointer()
    {
        char* name;

        InputName(&name);
        printf("�̸��� %s �Դϴ�. \n", name);
        free(name);
    }

    void NotWorkingInputName(char* pName);
    void NotWorkingInputName(char* pName)
    {
        pName = (char*)malloc(12);
        strcpy(pName, "Cabin");
    }

    void NotworkingPointer()
    {
        /*
        char* name;

        // NotWorkingInputeName ���� name�� �ְ� �Ǹ�, name ������ value �� �Ѿ�� �ǹǷ� ������ ����.
        NotWorkingInputName(name);
        printf("�̸��� %s �Դϴ�. \n", name);
        free(name);
        */
    }
}

using namespace SOEN;

int main()
{
    std::cout << "10. Pointer\n";

    PointerSum();
    VoidPointer();
    VoidPointer2();
    UsingVoidPointer();
    VoidDump();

    //DynamicAllocation();
    DynamicReAllocation();

    PointerToPointer();
    UsingDoublePointer();

    //NotworkingPointer();
}
