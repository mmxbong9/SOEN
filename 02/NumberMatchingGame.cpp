#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "NumberMatchingGame.h"

namespace SOEN
{
	void NumberMatchingGame()
	{
		int num;
		int input;
		
		randomize();

		for (;;)
		{
			num = random(100) + 1;
			printf("\n ���� ���� ���ڸ� ���� ������.\n");

			do
			{
				printf("���ڸ� �Է��ϼ���(���� ���� 999) : ");
				scanf("%d", &input);

				if (input == 999)
				{
					exit(0);
				}

				if (input == num)
				{
					printf("������ϴ�.");
				}
				else if (input > num)
				{
					printf("�Է��� ���ں��� �۽��ϴ�.");
				}
				else
				{
					printf("�Է��� ���ں��� Ů�ϴ�.");
				}

			} while (input != num);
		}
	}
}
