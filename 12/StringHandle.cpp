#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
		// k 번 만큼 회전하는 Rotate 함수를 작성.
	}

	void RightRotate(int arr[], int first, int end)
	{
		int last = arr[end];

		for (int i = end; i > first; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[first] = last;
	}
}
