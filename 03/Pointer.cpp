#include <iostream>
#include "Pointer.h"

using namespace std;

namespace SOEN
{
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
		cout << "+------------------------------+" << endl;
		cout << "|     Pointer Array Example    |" << endl;
		cout << "+------------------------------+" << endl;

		int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
		int* parr;
		parr = &arr[0];

		printf("array : sizeof(%d) \n", sizeof(arr));
		printf("array pointer : sizeof(%d) \n", sizeof(parr));

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

		// 문제 1 : int arr[3][3]; 과 같은 배열은 내부적으로 어떻게 처리되는지 생각해 보세요.
		int arr2[3][3] = { {1,2,3}, {1,2,3}, {1,2,3} };

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("arr2[%d][%d] : %d , ", i, j, arr2[i][j]);
				printf("*(*(arr2+%d)+arr2+%d) : %d \n", i, j, *(*(arr2+i)+j));
			}
		}

		// 문제 2 : int* arr[3]; 과 같은 배열이 가지는 의미는 무엇일까요?
		// int* type 의 주소를 담는 arr[3] 배열.
	}

	void ArrayToPointerDecay()
	{
		/*
		 array 를 선언하고 값을 return 받을때 암시적으로 array pointer 로 캐스팅 되는 문제.

		 C 에서 array가 pointer 로 implicit conversion 되는 것을 decay.
		 혹은 다른 decay 들과 구분 하기위해 array to pointer decay 라고 부른다.
		 */

		// todo : 테스트 코드 작성.
	}
}
