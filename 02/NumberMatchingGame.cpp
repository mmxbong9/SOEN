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
			printf("\n 제가 만든 숫자를 맞춰 보세요.\n");

			do
			{
				printf("숫자를 입력하세요(끝낼 때는 999) : ");
				scanf("%d", &input);

				if (input == 999)
				{
					exit(0);
				}

				if (input == num)
				{
					printf("맞췄습니다.");
				}
				else if (input > num)
				{
					printf("입력한 숫자보다 작습니다.");
				}
				else
				{
					printf("입력한 숫자보다 큽니다.");
				}

			} while (input != num);
		}
	}
}
