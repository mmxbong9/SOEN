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

		// ���� 1 : int arr[3][3]; �� ���� �迭�� ���������� ��� ó���Ǵ��� ������ ������.
		int arr2[3][3] = { {1,2,3}, {1,2,3}, {1,2,3} };

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("arr2[%d][%d] : %d , ", i, j, arr2[i][j]);
				printf("*(*(arr2+%d)+arr2+%d) : %d \n", i, j, *(*(arr2+i)+j));
			}
		}

		// ���� 2 : int* arr[3]; �� ���� �迭�� ������ �ǹ̴� �����ϱ��?
		// int* type �� �ּҸ� ��� arr[3] �迭.
	}

	void ArrayToPointerDecay()
	{
		/*
		 array �� �����ϰ� ���� return ������ �Ͻ������� array pointer �� ĳ���� �Ǵ� ����.

		 C ���� array�� pointer �� implicit conversion �Ǵ� ���� decay.
		 Ȥ�� �ٸ� decay ��� ���� �ϱ����� array to pointer decay ��� �θ���.
		 */

		// todo : �׽�Ʈ �ڵ� �ۼ�.
	}
}
