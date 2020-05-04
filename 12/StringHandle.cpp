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
		char si[] = "����";
		char ku[] = "���빮";
		char dong[] = "ȸ��";
		char juso[64];

		strcpy(juso, si);
		strcat(juso, "�� ");
		strcat(juso, ku);
		strcat(juso, "�� ");
		strcat(juso, dong);
		strcat(juso, "��");

		puts(juso);
	}

	void StringCompare()
	{
		char capital[16];
		printf("�츮������ ������ ����Դϱ�? ");
		scanf("%s", capital);

		if (strcmp(capital, "����") == 0)
		{
			printf("�����մϴ�. �����Դϴ�.\n");
		}
		else
		{
			printf("Ʋ�ȴ�. �� ��� �װ͵� �𸣴�?\n");
		}
	}

	void StringSearch()
	{
		char str[256];
		char* ptr;
		int count = 0;

		printf("�ƹ� ���ڳ� �Է��ϼ���(������� �ִ� 255����)");
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

		printf("�Է��� ���ڿ����� a�� %d �� �ֽ��ϴ�.\n", count);

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
		/* ��� �� ���� ����.
		 1. �������� ����� �ܾ� ��� �ۼ�.
		 2. ������ �ܾ ����.
		 3. ������� ���� �Է� ��� : ��� ������ ������� ���� Ÿ���� ������.
		 4. ����ڰ� �Է��� ������ ������ �����ֱ�.
		 5. ���� ���� ���� : 7ȸ �̻� Ʋ�� ���ڸ� �Է� �� ��� ���� ���� ó��.
		 6. ����� �ߺ� ���� �Է� ���� ���� : �����ڸ� �Է�, �̹� ã�Ұų� �� �� Ʋ�� ���ڴ� �Է� �ź�.
		*/

		// 1. �������� ����� �ܾ� ��� �ۼ�.
		const int wordLength = 10;
		const int wordMax = 3;
		char words[wordMax][wordLength] = { "fine", "apple", "sweet" };

		// 2. ������ �ܾ� ����.
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

		// 3. ������� ���� �Է� ��� : ��� ������ ������� ���� Ÿ���� ������.
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

				// 4. ����ڰ� �Է��� ������ ������ �����ֱ�.
				printf("Display Word = [ %s ] , current wrong input count [ %d ] \n", findWord, wrongInputCount);

				// ���� ���� üũ.
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
