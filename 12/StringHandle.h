#pragma once

#define FALSE 0
#define TRUE 1

namespace SOEN
{
	void StringCopy();
	void StringConcatenate();
	void StringCompare();
	void StringSearch();
	void StringInsert();
	void StringRightRotation();
	void StringRightRotate(char arr[], int first, int end);
	void IntegerRightRotation();
	void IntegerRightRotate(int arr[], int first, int end);
	void HangMan();

	// ǥ�� �Լ� ����.
	void StrFunc();

	void my_puts(const char* str);
	void my_puts2(const char* str);

	char* my_strcpy(char* dest, const char* src);

	size_t my_strlen(const char* str);
	size_t my_strlen2(const char* str);
		
	char* my_strcat(char *dest, const char* src);
	
	char* my_strchr(const char* string, int c);
	char* my_strstr(const char* string, const char* strSearch);

	int my_strcmp(const char* str1, const char* str2);
	int my_stricmp(const char* str1, const char* str2);

	char* my_strncpy(char* dest, const char* src, size_t count);
	char* my_strncat(char* dest, const char* src, size_t count);

	// Ȯ�� �Լ� ����.
	/*
	 1. stradd() : ���ڿ� �ڿ� ���ڸ� ���� �ϴ� �Լ�.
	 2. stristr() : ���ڿ� �� �Լ��� strstr �� ��ҹ��� ���� ��Ȯ�ϰ� ���� �Ѵ�. stristr �� ��ҹ��� ���о��� ��ġ ���θ� Ȯ�� �ϴ� �Լ�.
	 3. strreplace() : ���ڿ��� ã��, �ٸ� ���ڿ��� ��ü �ϴ� �Լ�.
	 4. strrevcase()
	    : ���ڿ� ��ü�� �빮�ڷ�, �Ǵ� �ҹ��ڷ� �ٲٴ� strupr strlwr �Լ��� ������, �ݴ�� ������ �Լ��� ����.
		  �־��� ��ҹ��ڸ� �ݴ�� �ٲٴ� �Լ� strrevcase �Լ��� �ۼ� �϶�, 
		  ������� "Case" ���ڿ��� �ָ� "cASE" �� �ٲ�� ���ƿ;� �ϸ� ������ �̿��� ���ڴ� �ǵ帮�� ���ƾ� �Ѵ�.
	 5. strtrim()
	    : ���ڿ��� ���ʰ� ���ʿ� �ִ� ������ ���� ū �ǹ̰� ���� �� ������ ��찡 ����.
		  �־��� ���ڿ��� ���� ������ �߶󳻴� strltrim �Լ��� ������ ������ �߶󳻴� strrtrim �Լ��� �ۼ��϶�.
		  �߶� ���鿡�� �����̽� ���� (0x20) �Ӹ� �ƴ϶� �� ('\t') �� ���Եȴ�.
	 6. hstrrev()
	    : ǥ�� �Լ� �߿� ���ڿ��� �ݴ�� ������ strrev �Լ��� �ִµ� �� �Լ��� ����Ʈ ������ ���ڸ� ���� ��ü�ϱ� ������
		  2����Ʈ ������ �ѱۿ� ���ؼ��� ���� ���� �ʴ´�.
		  �ѱۿ� ���ؼ��� �����⸦ �� �� �ִ� hstrrev �Լ��� �ۼ��϶�, ���� ��� "�ǳ�Ű��" ���ڿ��� �ָ� "��Ű����"�� ���ϵǾ�� �Ѵ�.
		  �ѱ� �ڵ�� 0x80 �̻��� ���� �����Ƿ� Ư�� ���� c�� �ѱ������� ((c & 0x80) != 0) ���ǹ����� �����ϰ� ���� �� �� �ִ�.
	 */

	void stradd(char* dest, int c);
	char* stradd_b(char* dest, int c);

	char* stristr(const char* string, const char* const subString);
}
