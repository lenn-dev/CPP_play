//class 종합문제
// 다음 프로그램의 출력 결과는?

#include <iostream>

using namespace std;

int n = 0;
namespace A {
	int n = 0;
	namespace B {
		void set() { n = 10; }
		int n = 0;
	}
}
// set() 함수 선언,정의 분리되어 있음
namespace C {
	void set();
	int n = 0;
}
void C::set() { n = 20; }

int main_namespace() {
	using namespace A::B;

	// 아래 실행 된 후에 어떻게 출력되는지 알기
	// A에 속해 있는 B안에서 set() 함수 찾음.
	// n 을 10으로 하라고 되어 있음.
	// 위로 올라가 n값을 찾음. 
	// 위의 int n = 0 이 10으로 바뀜
	set(); //A::B::set()
	
	// C에 속한 set() 함수 찾음
	// 찾았는데 선언,정의 분리되어 있어서 정의부분 찾아감
	// n을 20으로 하라고 되어 있음
	// C에 n이 있는지 찾아봄 
	// C안에 int n = 0 값을 20으로 바꿈.
	C::set(); // C:: set()
	

	//=======================================================================
	// ::n은 using namespace A::B; 를 썼으므로 
	// A::B::n을 말함 
	// B안에 있는 n 은 0
	cout << ::n << endl; //0
	
	// 명시적으로 A에 있는 n 은 위의 set()으로 인해 10으로 바뀌어 있음.
	cout << A::n << endl; //10


	cout << A::B::n << endl; //0
	
	// C 에 있는 n은 C::set() 으로 인해 20으로 바뀌어 있음.
	cout << C::n << endl; //20

	return 0;
}