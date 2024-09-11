#include <iostream>

using namespace std;

class MyClass {
public:
	void PrintThis() {
		cout << "My address is..." << this << endl; 
		// this는 자기 소속된 객체의 주소
		// 모든 클래스와 struct 안에 있는 멤버들은 
		// this 라는 포인터를 보이지 않는 매개변수 형태로 받아둠.
		// 따라서 PrinThis 가 a,b 객체 중 어디에 속하는지 알 수 있는 것임.
		// PrintThis() 함수는 각 객체 안에 존재하는것이 아니라 밖에 따로 있음.
		// 즉 void PrintThis(*ptr){
		//		cout << "My address is.." << *ptr << end; 와 같음
		// 메인함수 내에서 함수호출은 a.PrintThis(&ptr); 하게 되면 
		// 매개변수 없이 this 썼을때와 같이 해당 주소를 반환함.		
	}
};


int main_this() {
	MyClass a, b; // 객체 생성

	cout << "Address of a is .." << &a << endl;
	cout << "Address of b is .." << &b << endl;

	a.PrintThis();
	b.PrintThis();

	return 0;
}