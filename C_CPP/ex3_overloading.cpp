// 함수 overloading 함수다중정의
#include <iostream>

//using namespace std;
// swap 함수 사용할 건데 using namespace std; 안에 들어가 있음.
// 그래서 이번에는 제거하고 연습

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
// 더블이 인트를 인자로 받는스왑함수에 들어가면 에러니
//더블형을 받는 스왑함수 또 만듦
void swap(double& a, double& b) {
	double tmp = a;
	a = b;
	b = tmp;
}
//두 포인터 (안에 들어 있는 주소값) 뒤바꾸는 함수
void swap(int* (&a), int* (&b)) { // 레퍼런스변수 a 중 인트형 포인터를 가진 변수
	int* tmp = a; //a 레퍼런스에 저장된 주소값을 tmp 에 저장함.
	a = b;
	b = tmp;
}

int main_overload() {

	int a = 20, b = 30;
	double da = 2.222, db = 3.333;
	int* pa = &a, * pb = &b; // 포인터가 가리키는 대상을 뒤바꿀 것임.

	swap(a, b);
	swap(da, db);
	swap(pa, pb);


	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;

	std::cout << "da : " << da << std::endl;
	std::cout << "db : " << db << std::endl;

	std::cout << "*pa : " << *pa << std::endl;
	std::cout << "*pb : " << *pb << std::endl;


	// 이렇게 자료형마다 다른 함수를 사용해야 하면 사용자 입장에서 불편함.
	// 함수이름을 다르게 한것을 모두 swap 으로 똑같이 변경해도 동작함.
	// 컴파일러가 매개변수의 형을 자동으로 인식해서 가장 적합한 것을 찾아줌.
	// 각각의 swap함수에 커서 올려보면 각각 인식하는 함수가 다름을 알 수 있음.

	return 0;
}