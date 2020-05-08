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

	// 표준 함수 구현.
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

	// 확장 함수 구현.
	/*
	 1. stradd() : 문자열 뒤에 문자를 연결 하는 함수.
	 2. stristr() : 문자열 비교 함수인 strstr 은 대소문자 까지 정확하게 구분 한다. stristr 은 대소문자 구분없이 일치 여부를 확인 하는 함수.
	 3. strreplace() : 문자열을 찾아, 다른 문자열로 대체 하는 함수.
	 4. strrevcase()
	    : 문자열 전체를 대문자로, 또는 소문자로 바꾸는 strupr strlwr 함수는 있지만, 반대로 뒤집는 함수는 없다.
		  주어진 대소문자를 반대로 바꾸는 함수 strrevcase 함수를 작성 하라, 
		  예를들면 "Case" 문자열을 주면 "cASE" 로 바뀌어 돌아와야 하며 영문자 이외의 문자는 건드리지 말아야 한다.
	 5. strtrim()
	    : 문자열의 앞쪽과 뒤쪽에 있는 공백은 보통 큰 의미가 없는 빈 문자인 경우가 많다.
		  주어진 문자열의 왼쪽 공백을 잘라내는 strltrim 함수와 오른쪽 공백을 잘라내는 strrtrim 함수를 작성하라.
		  잘라낼 공백에는 스페이스 문자 (0x20) 뿐만 아니라 탭 ('\t') 도 포함된다.
	 6. hstrrev()
	    : 표준 함수 중에 문자열을 반대로 뒤집는 strrev 함수가 있는데 이 함수는 바이트 단위로 문자를 직접 교체하기 때문에
		  2바이트 문자인 한글에 대해서는 동작 하지 않는다.
		  한글에 대해서도 뒤집기를 할 수 있는 hstrrev 함수를 작성하라, 예를 들어 "피노키오" 문자열을 주면 "오키노피"가 리턴되어야 한다.
		  한글 코드는 0x80 이상의 값을 가지므로 특정 문자 c가 한글인지는 ((c & 0x80) != 0) 조건문으로 간단하게 조사 할 수 있다.
	 */

	void stradd(char* dest, int c);
	char* stradd_b(char* dest, int c);

	char* stristr(const char* string, const char* const subString);
}
