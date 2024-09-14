
#include <iostream>

using namespace std;

int main() {
	// 변수는 메모리 공간에 대한 이름
	int a = 123;

	// C++에서 변수 주소 보고 싶을 때 앞에 &만 붙이면 됨
	// address of 주소 연산자 & ampersand
	// a는 변수 a 값인 123
	// &a 는 인트형변수 a의 주소값
	cout << a << "  " << &a << endl;

	//참고 : 파이썬 id()와 비교

	// 인트타입 변수 a의 주소값을 저장할때는 int*을 사용함
	// int* : 인트타입의 데이터가 저장될 수 있는 메모리공간의 주소
	// int타입이 저장될 수 있는 메모리 공간의 주소
	// int형의 포인터 b , 
	int* b = &a; // b에 a의 주소 대입

	// dereference operator (역참조 연산자)
	// b는 a의 주소값
	// *b는 a가 가리키는 주소로 가서 값을 가져오는데 몇바이트를 가져옴?
	// b 자체의 자료형이 int* (인트포인터) 이기 때문에 
	// int형 만큼의 데이터인, 4바이트만 가져와서 다시 인트로 해석해서 출력함 123
	cout << b << " " <<  *b << endl;

	// 역참조를 이용해 값을 바꿔줄 수도 있음
	// b가 가리키는 주소에 있는 값을 567 로 바꿔줌
	*b = 567;

	// a = 567 , b = 주소값, *b = 567
	cout << a << " " << b << " " << *b << endl; 

	// 포인터 자체의 주소크기와 자료형의 크기(주소의 크기는 항상 동일)
	// 아무 주소도 가리키고 있지 않다는 의미로 널 포인터로 초기화, 
	// 0도 많이 사용함
	double* c = nullptr;
	double* c = 0;

	cout << sizeof(int) << " " << sizeof(double) << endl; // 4 8
	cout << sizeof(int*) << "  " << sizeof(double*) << endl; // 8 8 주소의 규격은 동일
	cout << sizeof(b) << " " << sizeof(c) << endl;

	//포인터 연산과 배열

	//size_t 안내(여기서는 주소를 16진수에서 10진수로 변환 용도)
	cout << sizeof(size_t)  << endl; // 8
	// 포인터의 자료형 크기만큼 늘어남
	// 인트형 포인터 10진수로 출력하면 어떤 주소값이 10진수로 나오는데,
	// 그 주소에 1과 2를 더한값이 인트형자료의 크기 4바이트만큼씩 늘어남을 확인할 수 있음.
	cout << size_t(b) << "  " << size_t(b + 1) << "  " << size_t(b + 2) << endl;
	// 더블형도 마찬가지로 더블형의 크기 8만큼씩 늘어남 , c는 0으로 초기화 해둬서 확인쉬움
	cout << size_t(c) << "  " << size_t(c + 1) << "  " << size_t(c + 2) << endl;


	// sizeof(char) == 1입니다. char* e = 0; e+15는 몇일까요?

	// 문자열, 배열 연결시키기
	// 포인터를 배열처럼 사용하는 예시
	int my_array[] = { 23,38,56,69,74 };

	char my_str[] = { 'h', 'e', 'l','l','o' }; // "Hello"
	
	char* ptr = my_str; //배열의 이름은 포인터

	//모두 동일한 결과
	cout << *(my_str + 4) << endl; // o
	cout << *(ptr + 4) << endl; // o
	cout << ptr[4] << endl; // 0


	return 0;
}