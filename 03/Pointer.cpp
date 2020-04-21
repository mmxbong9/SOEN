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

		printf("* 연산자 사용 법. \n");
		printf("1. 변수를 선언해서 사용할때는 메모리 주소를 담는 공간. \n");
		printf("2. 사용할때는 해당 메모리의 주소를 dereferancing(역참조) 하여 value 를 가져옴. \n");

		/*
		int *numPtr;                // 포인터. 포인터를 선언할 때 *
		printf("%d\n", *numPtr);    // 역참조. 포인터에 사용할 때 *
		*/

		printf("사용자 작성 code가 compiler 를 거쳤을 때. \n");
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

		printf("모든 값 출력 > num : %d | *pi : %d | **ppi : %d \n", num, *pi, **ppi);

		printf("num의 주소는 %p 입니다.\n", &num);
		printf("num의 값은 %d 입니다.\n", num);

		printf("pi 포인터의 주소는 %p 입니다.\n", &pi);
		printf("pi 포인터의 값은 %p 입니다.\n", pi);

		printf("pi 포인터가 가지고 있는 주소 위치의 값은 %d 입니다.\n", *pi);

		printf("ppi 포인터가 가지고 있는 주소는 %p 입니다.\n", ppi);
		printf("ppi 포인터가 가지고 있는 주소 위치의 값은 %p 입니다.\n", *ppi);
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

		// 포인터가 가리키는 변수를 상수화 : pa 포인터를 이용해 변수의 값을 변경 하는 것을 제한.
		const int* pa = &a;
		*pa = 3;
		pa = &b;
		
		// 포인터 상수화 : 포인터 변수 자체가 상수화. 주소값을 변경 할 수 없다.
		int* const pb = &a;
		*pb = 3;
		pb = &b;

		// 포인터를 통해 값 변경 및 포인터의 address 변경도 할 수 없음.
		const int* const pc = &a;
		*pc = 3;
		pc = &b;
		*/
	}

	void PointerArray()
	{
		// array subscript [] : 메모리 상에 연속된 공간을 뜻함.

		cout << "+------------------------------+" << endl;
		cout << "|     Pointer Array Example    |" << endl;
		cout << "+------------------------------+" << endl;

		// int* 타입의 ptrArr 변수를 heap 영역에 동적으로 할당.
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
		printf("C 에서는 array 를 반환 할때, 암시적 형 변환(implict type conversion)을 통해 강제로 포인터로 반환. : %d \n", *firstparr);

		int i;
		for (i = 0; i < 10; i++)
		{
			printf("arr[%d] 의 시작 주소 : %p ", i, &arr[i]);
			printf("(parr + %d) 의 주소 : %p ", i, (parr + i));

			if (&arr[i] == (parr + i))
			{
				printf(" >> equal \n");
			}
			else
			{
				printf(" >> not equal \n");
			}
		}

		printf("\n 문제 1 : int arr[3][3]; 과 같은 배열은 내부적으로 어떻게 처리되는지 생각해 보세요. \n");
		int arr2[3][3] = { {1,2,3}, {1,2,3}, {1,2,3} };

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("arr2[%d][%d] : %d , ", i, j, arr2[i][j]);
				printf("*(*(arr2+%d)+arr2+%d) : %d \n", i, j, *(*(arr2+i)+j));
			}
		}

		printf("\n 문제 2 : int* arr[3]; 과 같은 배열이 가지는 의미는 무엇일까요? \n");
		printf(" >> int* 타입의 array[3] 배열. \n");
	}

	void ArrayToPointerDecay()
	{
		/*
		 C 에서는 array 를 선언하면 암시적으로 array pointer 로 캐스팅 되는 문제가 있음. C++ 에서는 std:array 를 사용하면 문제 없음.
		 */

		// 배열을 선언 하게되면 컴파일시 첫번째 array subscript에 한해서 *arr 와 같은 포인터 형식으로 변환.
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
