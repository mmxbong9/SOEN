// 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

/*
 SOEN URL : http://www.soen.kr

 C언어의 계보
 [ALGOL60] > [BCPL] > [B] > [C] > [C++]

 ANSI 83년 부터 표준 작업 시작. 89년에 표준안 완성. 90년에 ISO 에 의해 승인(ISO9899) 이때의 C 표준을 ANSI C(또는 C90), 그 이전의 C를 클래식 C(K&R C).
 ANSI C는 클래식 C에 비해 안전성을 높이고 애매한 기능을 정리.

 다음과 같은 기능을 추가.
 1. 표준 라이브러리 함수를 규격화했으며 헤더 파일도 통일.
 2. 함수의 원형 선언 기능이 추가되어 컴파일러가 함수 호출부에서 타입 체크 가능.
 3. 정수, 실수 상수의 타입을 지정할 수 있는 L, U, F 등의 접미어가 추가.
 4. enum, void 형과 const, volatile 제한자가 추가.
 5. 인접 문자열 상수를 합쳐 주고 확장열의 기능도 추가.
 6. 함수 내부에서 선언하는 지역 배열이나 구조체를 초기화 할 수 있다.
 7. 구조체끼리 대입 할 경우 구조체 크기만큼 메모리 복사를 한다.

 이후의 C표준.
 95년에 멀티바이트 문자 지원이 추가. C95. ANSI C에 비해 언어의 기능상 큰 변화는 없었음.
 이후 99년에 다양한 기능을 추가 한후 C++ 의 장점을 흡수하여 다시한번 개정. C99.
 2011년 ISO/IEC 9899:2011이 출간. C11.
 */