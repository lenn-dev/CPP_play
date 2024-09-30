#include <iostream> // 선행처리기, 표준 입출력 라이브러리 포함
using namespace std;  // std 의 명칭공간을 사용선언하여 명칭공간 지정을 간소화

int main_reference() { // 메인함수
	int a = 10, b = 20; //정수형 변수 a,b 에 각각 10,20 할당
	int& aRef = a; // 인트형의 a 변수를 참조하는 참조변수 aRef 선언,포인터와 유사
	cout << "a의 값 : " << a << endl; // a값 출력
	cout << "aRef가 참조하는 값 : " << aRef << endl << endl; // aRef참조값 출력
	aRef = 100; // aRef가 참조하는 곳의 값을 100으로 할당
	cout << "a의 값 : " << a << endl; // a값 출력, 100
	aRef = b; // aRef가 참조하는 곳에 b 값 할당
	cout << "a의 값 : " << a << endl << endl; //20
	return 0; // 함수 정상 종료
}

