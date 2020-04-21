#include <iostream>
#include "Pointer.h"

using namespace std;

namespace SOEN
{
	void AboutVariableAndPointer()
	{
		cout << "+------------------------------+" << endl;
		cout << "|  About Variable And Pointer  |" << endl;
		cout << "+------------------------------+" << endl;

		printf("* ������ ��� ��. \n");
		printf("1. ������ �����ؼ� ����Ҷ��� �޸� �ּҸ� ��� ����. \n");
		printf("2. ����Ҷ��� �ش� �޸��� �ּҸ� dereferancing(������) �Ͽ� value �� ������. \n");

		/*
		int *numPtr;                // ������. �����͸� ������ �� *
		printf("%d\n", *numPtr);    // ������. �����Ϳ� ����� �� *
		*/

		printf("����� �ۼ� code�� compiler �� ������ ��. \n");
		/*
		int var1 = 7;		// code
		int 0x1234 = 7;		// compiler
		*/

		/*
		var1 = var2;		// code
		0x1234 = 0x5678;	// compiler
		*/

		/*
		int *prt = &var1;		// code
		int 0x2345 = $0x1234;	// compiler
		*/
	}

	void Pointer()
	{
		cout << "+------------------------------+" << endl;
		cout << "|        Pointer Example       |" << endl;
		cout << "+------------------------------+" << endl;

		int num = 629;
		int *pi;
		int **ppi;

		pi = &num;
		ppi = &pi;

		printf("��� �� ��� > num : %d | *pi : %d | **ppi : %d \n", num, *pi, **ppi);

		printf("num�� �ּҴ� %p �Դϴ�.\n", &num);
		printf("num�� ���� %d �Դϴ�.\n", num);

		printf("pi �������� �ּҴ� %p �Դϴ�.\n", &pi);
		printf("pi �������� ���� %p �Դϴ�.\n", pi);

		printf("pi �����Ͱ� ������ �ִ� �ּ� ��ġ�� ���� %d �Դϴ�.\n", *pi);

		printf("ppi �����Ͱ� ������ �ִ� �ּҴ� %p �Դϴ�.\n", ppi);
		printf("ppi �����Ͱ� ������ �ִ� �ּ� ��ġ�� ���� %p �Դϴ�.\n", *ppi);
	}

	void ConstPointer()
	{
		cout << "" << endl;
		cout << "+------------------------------+" << endl;
		cout << "|     Const Pointer Example    |" << endl;
		cout << "+------------------------------+" << endl;
		cout << "" << endl;
		
		/*
		int a;
		int b;

		// �����Ͱ� ����Ű�� ������ ���ȭ : pa �����͸� �̿��� ������ ���� ���� �ϴ� ���� ����.
		const int* pa = &a;
		*pa = 3;
		pa = &b;
		
		// ������ ���ȭ : ������ ���� ��ü�� ���ȭ. �ּҰ��� ���� �� �� ����.
		int* const pb = &a;
		*pb = 3;
		pb = &b;

		// �����͸� ���� �� ���� �� �������� address ���浵 �� �� ����.
		const int* const pc = &a;
		*pc = 3;
		pc = &b;
		*/
	}

	void PointerArray()
	{
		// array subscript [] : �޸� �� ���ӵ� ������ ����.

		cout << "+------------------------------+" << endl;
		cout << "|     Pointer Array Example    |" << endl;
		cout << "+------------------------------+" << endl;

		// int* Ÿ���� ptrArr ������ heap ������ �������� �Ҵ�.
		int* ptrArr = (int*)(malloc(3 * sizeof(int)));
		ptrArr[0] = 10;
		ptrArr[1] = 20;
		ptrArr[2] = 30;

		for (int i = 0; i < 3; i++)
		{
			printf("address = %d , value = %d \n", (ptrArr + i), *(ptrArr + i));
		}
		cout << "" << endl;

		free(ptrArr);

		int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
		int* parr;
		parr = &arr[0];

		printf("array : sizeof(%d) \n", sizeof(arr));
		printf("array pointer type : sizeof(%d) \n", sizeof(parr));

		printf("arr[3] : %d \n", arr[3]);
		printf("*(arr+3) : %d \n", *(arr+3));

		int* firstparr = arr;
		printf("C ������ array �� ��ȯ �Ҷ�, �Ͻ��� �� ��ȯ(implict type conversion)�� ���� ������ �����ͷ� ��ȯ. : %d \n", *firstparr);

		int i;
		for (i = 0; i < 10; i++)
		{
			printf("arr[%d] �� ���� �ּ� : %p ", i, &arr[i]);
			printf("(parr + %d) �� �ּ� : %p ", i, (parr + i));

			if (&arr[i] == (parr + i))
			{
				printf(" >> equal \n");
			}
			else
			{
				printf(" >> not equal \n");
			}
		}

		printf("\n ���� 1 : int arr[3][3]; �� ���� �迭�� ���������� ��� ó���Ǵ��� ������ ������. \n");
		int arr2[3][3] = { {1,2,3}, {1,2,3}, {1,2,3} };

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("arr2[%d][%d] : %d , ", i, j, arr2[i][j]);
				printf("*(*(arr2+%d)+arr2+%d) : %d \n", i, j, *(*(arr2+i)+j));
			}
		}

		printf("\n ���� 2 : int* arr[3]; �� ���� �迭�� ������ �ǹ̴� �����ϱ��? \n");
		printf(" >> int* Ÿ���� array[3] �迭. \n");
	}

	void ArrayToPointerDecay()
	{
		/*
		 C ������ array �� �����ϸ� �Ͻ������� array pointer �� ĳ���� �Ǵ� ������ ����. C++ ������ std:array �� ����ϸ� ���� ����.
		 */

		// �迭�� ���� �ϰԵǸ� �����Ͻ� ù��° array subscript�� ���ؼ� *arr �� ���� ������ �������� ��ȯ.
		/*
		int arr[5];
		int *arr;

		int arr[2][3];
		int (*arr)[3];

		int arr[2][3][4];
		int (*arr)[3][4];*/

		int array[100];

		printf("original array sizeof(array) = %d \n", sizeof(array));

		ArrayDecay1(array);
		ArrayDecay2(array);
	}

	void ArrayDecay1(int* array)
	{
		printf("ArrayDecay1 >> sizeof(array) = %d \n", sizeof(array));
	}

	void ArrayDecay2(int array[])
	{
		printf("ArrayDecay2 >> sizeof(array) = %d \n", sizeof(array));
	}

	void plusref(int* a)
	{
		*a = *a + 1;
	}
}
