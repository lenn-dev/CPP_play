// 동적 메모리 할당 - 프로그램 실행 중에 메모리에 할당하는 것
// 정적 할당 int a; 보통 변수들은 프로그램 시작/종료나 함수 시작/종료와 함께함
// 시간, 공간(메모리) 에 의한 성능이 좌우

#include <iostream>

using namespace std;

int main_dynamic1() {
	// new 가 반환하는 값은 int(5)의 주소값 
	// 이것을 포인터 a에 저장
	int *a = new int(5);

	cout << a << endl; // a의 주소값 출력
	cout << *a << endl; // 포인터니까 a가 가리키는 int 5가 출력

	*a = 10; // a가 가리키는 공간의 숫자 5를 10으로 바꿈
	cout << a << endl; // 같은 주소값 출력
	cout << *a << endl; // 변경된 값 10 출력

	delete a; //메모리 해제

	return 0;
}