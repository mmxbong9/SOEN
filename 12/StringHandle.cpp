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
		// k �� ��ŭ ȸ���ϴ� Rotate �Լ��� �ۼ�.
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
