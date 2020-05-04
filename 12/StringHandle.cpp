#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <conio.h>

#include "StringHandle.h"

namespace SOEN
{
	void StringCopy()
	{
		char str1[10] = "abcdefghi";
		char str2[10] = "123456789";
		strncpy(str2, str1, 3);
		puts(str2);

		char str[] = "abcdefghi";
		strncpy(str+2, "+123+", 5);
		puts(str);

		printf("Array Length : %d , Array Size : %d\n", strlen(str), sizeof(str));
	}

	void StringConcatenate()
	{
		char si[] = "서울";
		char ku[] = "동대문";
		char dong[] = "회기";
		char juso[64];

		strcpy(juso, si);
		strcat(juso, "시 ");
		strcat(juso, ku);
		strcat(juso, "구 ");
		strcat(juso, dong);
		strcat(juso, "동");

		puts(juso);
	}

	void StringCompare()
	{
		char capital[16];
		printf("우리나라의 수도는 어디입니까? ");
		scanf("%s", capital);

		if (strcmp(capital, "서울") == 0)
		{
			printf("축하합니다. 정답입니다.\n");
		}
		else
		{
			printf("틀렸다. 넌 어떻게 그것도 모르니?\n");
		}
	}

	void StringSearch()
	{
		char str[256];
		char* ptr;
		int count = 0;

		printf("아무 문자나 입력하세요(공백없이 최대 255문자)");
		scanf("%s", str);

		for (ptr = str;;)
		{
			ptr = strchr(ptr, 'a');
			if (ptr == NULL)
			{
				break;
			}
			count++;
			ptr++;
		}

		printf("입력한 문자열에는 a가 %d 개 있습니다.\n", count);

		char str1[] = "I am a boy, are you a girl";
		char* p;

		p = strtok(str1, " ,");
		while (p != NULL)
		{
			puts(p);
			p = strtok(NULL, " ,");
		}
	}

	void StringInsert()
	{
		char str[32] = "You are beautiful";
		char str2[] = "very ";

		puts(str);
		memmove(str + 13, str + 8, 10);
		puts(str);
		memcpy(str + 8, str2, strlen(str2));
		puts(str);
	}

	void StringRightRotation()
	{
		char str[6] = "hello";

		StringRightRotate(str, 0, strlen(str));
	}

	void StringRightRotate(char arr[], int first, int end)
	{
		char lastValue = arr[end - 1];

		printf("last value : %c\n", lastValue);

		for (int i = end; i > first; i--)
		{
			arr[i] = arr[i - 1];
			//printf("%c", arr[i]);
		}
		arr[first] = lastValue;

		printf("result [ ");
		for (int i = 0; i < end; i++)
		{
			arr[i];
			printf("%c", arr[i]);
		}
		printf(" ]\n");
	}

	void IntegerRightRotation()
	{
		int intArray[] = { 1, 2, 3, 4, 5 };
		int arraySize = sizeof(intArray) / sizeof(int);

		IntegerRightRotate(intArray, 0, arraySize);
		IntegerRightRotate(intArray, 0, arraySize);
	}

	void IntegerRightRotate(int arr[], int first, int end)
	{
		int lastValue = arr[end - 1];

		for (int i = end - 1; i > first; i--)
		{
			arr[i] = arr[i - 1];
			//printf("index is %d = %d ", i, arr[i]);
		}
		arr[first] = lastValue;

		printf("\n");
		printf("Right Rotation Result : [ ");

		for (int i = 0; i < end; i++)
		{
			printf("index is %d = %d ", i, arr[i]);
		}

		printf(" ]\n");
	}

	void HangMan()
	{
		/* 기능 및 조건 정리.
		 1. 정답으로 사용할 단어 목록 작성.
		 2. 난수로 단어를 선택.
		 3. 사용자의 문자 입력 기능 : 사용 가능한 사용자의 문자 타입은 영문자.
		 4. 사용자가 입력한 문자의 정보를 보여주기.
		 5. 게임 종료 조건 : 7회 이상 틀린 글자를 입력 할 경우 게임 종료 처리.
		 6. 사용자 중복 문자 입력 방지 조건 : 영문자만 입력, 이미 찾았거나 한 번 틀린 문자는 입력 거부.
		*/

		// 1. 정답으로 사용할 단어 목록 작성.
		const int wordLength = 10;
		const int wordMax = 3;
		char words[wordMax][wordLength] = { "fine", "apple", "sweet" };

		// 2. 난수로 단어 선택.
		srand((unsigned int)time(NULL));

		for (int i = 0; i < wordMax; i++)
		{
			int num = rand();
			printf("random test > %d : %d\n", num, num % wordMax);
			Sleep(250);
		}

		int selectedIndex = rand() % wordMax;
		printf("seledted Index = %d\n", selectedIndex);

		char selectedWord[wordLength];
		strcpy(selectedWord, words[selectedIndex]);

		printf("seledted word = %s\n", selectedWord);

		// 3. 사용자의 문자 입력 기능 : 사용 가능한 사용자의 문자 타입은 영문자.
		char findWord[wordLength];
		strcpy(findWord, selectedWord);

		int findWorldLength = strlen(findWord);

		printf("findWorldLength = %d\n", findWorldLength);
		
		for (int i = 0; i < findWorldLength; i++)
		{
			findWord[i] = '*';
		}

		printf("initialize findWord = [ %s ]\n", findWord);

		int wrongInputCount = 0;

		char ch;
		for (;;)
		{
			ch = _getch();

			if (isalpha(ch))
			{
				char alpabet = tolower(ch);

				if (strchr(selectedWord, ch) != NULL)
				{
					printf("find word : %c\n", alpabet);

					int isfindChar = FALSE;

					for (int i = 0; i < findWorldLength; i++)
					{
						if (selectedWord[i] == alpabet && findWord[i] == '*')
						{
							isfindChar = TRUE;

							findWord[i] = alpabet;
						}
						else if (selectedWord[i] == alpabet)
						{
							printf("aleady find user input character : %c", alpabet);
						}
					}

					if (isfindChar == FALSE)
					{
						printf("not find word : %c\n", alpabet);
					}
				}
				else
				{
					wrongInputCount++;

					printf("not find word : %c , wrong input count [ %d ] \n", alpabet, wrongInputCount);
				}

				// 4. 사용자가 입력한 문자의 정보를 보여주기.
				printf("Display Word = [ %s ] , current wrong input count [ %d ] \n", findWord, wrongInputCount);

				// 게임 종료 체크.
				int isGameComplete = TRUE;

				for (int i = 0; i < findWorldLength; i++)
				{
					if (findWord[i] == '*')
					{
						isGameComplete = FALSE;
					}
				}

				if (isGameComplete)
				{
					printf("GameComplete. input Count [ %d ]\n", wrongInputCount);
					break;
				}
				else
				{
					int isGameOver = FALSE;

					if (wrongInputCount >= 7)
					{
						printf("GameOver. input Count [ %d ]\n", wrongInputCount);
						break;
					}
				}
			}
		}
	}
}
