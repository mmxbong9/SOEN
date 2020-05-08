#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <conio.h>

#include "StringHandle.h"

#define putch _putch

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
		 4-1. ����� �ߺ� ���� �Է� ���� ���� : �����ڸ� �Է�.
		 4-2. ����� �ߺ� ���� �Է� ���� ���� : �̹� ã�Ұų� �� �� Ʋ�� ���ڴ� �Է� �ź�.
		 5. ����ڰ� �Է��� ������ ������ �����ֱ�.
		 6. ���� ���� ���� : 7ȸ �̻� Ʋ�� ���ڸ� �Է� �� ��� ���� ���� ó��.
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

			// 4-1. ����� �ߺ� ���� �Է� ���� ���� : �����ڸ� �Է�.
			if (isalpha(ch))
			{
				char alpabet = tolower(ch);

				if (strchr(selectedWord, ch) != NULL)
				{
					printf("find word : %c\n", alpabet);

					// 4-2. ����� �ߺ� ���� �Է� ���� ���� : �� �� Ʋ�� ���ڴ� �Է� �ź�.
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

				// 5. ����ڰ� �Է��� ������ ������ �����ֱ�.
				printf("Display Word = [ %s ] , current wrong input count [ %d ] \n", findWord, wrongInputCount);

				// 6. ���� ���� ���� : 7ȸ �̻� Ʋ�� ���ڸ� �Է� �� ��� ���� ���� ó��.
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

	void my_puts(const char* str)
	{
		while (*str)
		{
			putch(*str++);
		}

		putch('\n');
	}

	void my_puts2(const char* str)
	{
		int i;

		for (i = 0; str[i]; i++)
		{
			putch(str[i]);
		}

		putch('\n');
	}
		
	char* my_strcpy(char* dest, const char* src)
	{
		char* d = dest;
		while (*dest++ = *src++)
		{
			;
		}

		return d;
	}
	
	size_t my_strlen(const char* str)
	{
		const char* p;

		for (p = str; *p; p++)
		{
			//printf("current address = %d\n", p);
		}

		//printf("  p address = %d\n", p);
		//printf("str address = %d\n", str);

		//printf("string length = %d\n", p - str);

		return p - str;
	}

	size_t my_strlen2(const char* str)
	{
		int i;

		for (i = 0; str[i]; i++)
		{
			;
		}

		//printf("string length = %d\n", i);

		return i;
	}

	char* my_strcat(char *dest, const char* src)
	{
		my_strcpy(dest + my_strlen(dest), src);

		//printf("my_strcat() result = %s\n", dest);

		return dest;
	}

	char* my_strchr(const char* string, int c)
	{
		while (*string)
		{
			if (*string == c)
			{
				return (char*)string;
			}
			string++;
		}

		return NULL;
	}

	char* my_strstr(const char* string, const char* strSearch)
	{
		const char* s;
		const char* sub;

		for (; *string; string++)
		{
			//printf("looping string = %c , strSearch = %c\n", *string, *strSearch);

			for (sub = strSearch, s = string; *sub && *s && *s == *sub; sub++, s++)
			{
				//printf("  >> searching : string = %c , strSearch = %c\n", *s, *sub);
			}

			if (*sub == 0)
			{
				printf("find string\n");
				return (char*)string;
			}
		}

		return NULL;
	}

	int my_strcmp(const char* str1, const char* str2)
	{
		//printf("compare string value = %s , %s\n", str1, str2);

		char c1, c2;
		
		while (1)
		{
			c1 = *str1++;
			c2 = *str2++;

			//printf("c1 value = %d ", c1);
			//printf("c2 value = %d\n", c2);

			if (c1 != c2)
			{
				return c1 < c2 ? -1 : 1;
			}

			if (c1 == 0)
			{
				//printf("c1, c2 value is equal.\n while loop break.\n");
				break;
			}
		}

		return 0;
	}

	int my_stricmp(const char* str1, const char* str2)
	{
		char c1, c2;

		while (1)
		{
			c1 = tolower(*str1++);
			c2 = tolower(*str2++);

			if (c1 != c2)
			{
				return c1 < c2 ? -1 : 1;
			}

			if (c1 == 0)
			{
				break;
			}
		}

		return 0;
	}

	char* my_strncpy(char* dest, const char* src, size_t count)
	{
		char* d = dest;

		while (*dest++ = *src++)
		{
			//printf("now count = %d\n", count);

			if (count-- <= 0)
			{
				//printf("count is zero or under value. break loop\n");
				break;
			}
		}

		//printf("return value = %s\n", d);
		return d;
	}

	char* my_strncat(char* dest, const char* src, size_t count)
	{
		int destLength = my_strlen(dest);

		my_strncpy(dest + destLength, src, count);

		//printf("my_strncat() count = %d\n", count);

		dest[destLength + count] = '\0';

		return dest;
	}

	void stradd(char* dest, int c)
	{
		int len = strlen(dest);

		dest[len] = c;
		dest[len + 1] = 0;
	}

	char* stradd_b(char* dest, int c)
	{
		while (*dest++)
		{
			//printf("dest = %s\n", dest);

			if (*dest == 0)
			{
				//printf("here is null value.\n");
				*dest = c;
				*++dest = 0;
			}
		}

		return dest;
	}

	char* stristr(const char* string, const char* const subString)
	{
		// ���ڿ� �� �Լ��� strstr �� ��ҹ��� ���� ��Ȯ�ϰ� ���� �Ѵ�. stristr �� ��ҹ��� ���о��� ��ġ ���θ� Ȯ�� �ϴ� �Լ�.
		// todo : �ҹ��ڷ� ��ȯ �ؼ� �� �ϵ��� �ڵ� ����.

		/*
		const char* s;
		const char* sub;

		for (; *string; string++)
		{
			for (sub = subString, s = string; *sub && *s == *sub; sub++, s++)
			{
				;
			}

			if (*sub == 0)
			{
				return (char*)string;
			}
		}
		*/

		return NULL;
	}

	void StrFunc()
	{
		const char srcStr[7] = "source";
		char destStr[7];

		my_strcpy(destStr, srcStr);

		printf("my string copy result : %s\n", destStr);

		my_puts(destStr);
		my_puts2(destStr);

		my_strlen(destStr);
		my_strlen2(destStr);

		const char srcStr1[7] = "strcat";
		char destStr1[14] = "source2";

		my_strcat(destStr1, srcStr1);

		char* findChr = my_strchr(destStr1, 't');
		printf("findChr = %c , addrsss = %d\n", *findChr, findChr);

		const char* keyString = "2";

		printf("source string[ %s ] finding [ %s ]\n", destStr1, keyString);
		char* findString = my_strstr(destStr1, keyString);

		if (findString != NULL)
		{
			printf("finished find string = %s\n", findString);
		}

		const char* compString1 = "Abc";
		const char* compString2 = "abc";

		printf("Compare Source String : A = %s , B = %s\n", compString1, compString2);

		int stringCompareResult = my_strcmp(compString1, compString2);
		if (stringCompareResult == 0)
		{
			printf("strcmp() : A == B\n");
		}
		else if (stringCompareResult < 0)
		{
			printf("strcmp() : A < B\n");
		}
		else if (stringCompareResult > 0)
		{
			printf("strcmp() : A > B\n");
		}

		int stringCompareResult2 = my_stricmp(compString1, compString2);
		if (stringCompareResult2 == 0)
		{
			printf("stricmp() : A == B\n");
		}
		else if (stringCompareResult2 < 0)
		{
			printf("stricmp() : A < B\n");
		}
		else if (stringCompareResult2 > 0)
		{
			printf("stricmp() : A > B\n");
		}

		char destStr2[10];
		const char srcStr2[10] = "abcdefg";

		strncpy(destStr2, srcStr2, 3);
		printf("   strncpy() result = %s\n", destStr2);

		my_strncpy(destStr2, srcStr2, 2);
		printf("my_strncpy() result = %s\n", destStr2);

		char destStr3[10] = "abcd";
		const char srcStr3[10] = "1234";

		my_strncat(destStr3, srcStr3, 2);
		printf("my_strncat() result = %s\n", destStr3);

		char destStr4[10] = "abcd";
		int srcChar = 'z';

		stradd(destStr4, srcChar);
		printf("stradd() result = %s\n", destStr4);

		char destStr5[10] = "abcd";
		int srcChar1 = 'b';

		stradd_b(destStr5, srcChar1);
		printf("stradd_b() result = %s\n", destStr5);

		char targetStr[] = "targetString";
		char targetSubStr[] = "get";

		printf(" strstr() result = %s\n", strstr(targetStr, targetSubStr));
		printf("stristr() result = %s\n", stristr(targetStr, targetSubStr));
	}
}
