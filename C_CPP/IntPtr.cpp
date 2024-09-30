#include <iostream> // 선행처리기, 표준입출력 라이브러리 포함
using namespace std;  // std 의 명칭공간을 사용선언하여 명칭공간 지정을 간소화


int main_IntPtr() { //메인함수
	int a = 10, b = 100; // 정수형 변수 a,b 선언후 각각 10, 100 할당
	int* ptr = &a; // 인트형 포인터 ptr선언 후 변수 a 의 주소값 할당

	cout << "ptr이 가리키는 곳의 값 :" << *ptr << endl; // ptr포인터가 가리키는 메모리에 저장된 값을 출력 : 10
	*ptr = 20; // ptr포인터가 가리키는 메모리에 저장되어 있는 값을 20으로 바꿈
	cout << " 변수 a의 값 :" << a << endl; // 20 출력
	ptr = &b; // 포인터 ptr에 b변수의 주소를 저장하여 가리키게 함
	cout << "변수 b 의 값 : " << *ptr << endl; // 포인터의 변경된 주소값으로 인해 변수 b값인 100 출력
	return 0; // 함수 정상종료
}

