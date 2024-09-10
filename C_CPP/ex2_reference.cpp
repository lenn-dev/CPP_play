#include <iostream>
#include <string>
using namespace std;



// 두개의 변수 값을 뒤바꾸는 swap 이란 함수이기 때문에 
// call by value로 하면 의미가 없음.  
void swapb(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}



int main_rvalue() {

	// 2. c++ basic grammer=======================================================

	int c = 10; // int a(10); same
	// a(5); cannot do this way, as we don't know it's function or variable
	int d(c + 5);
	cout << "c =" << c << endl;
	cout << "d =" << d << endl;


	// for loop (range base?)
	int arr[10] = { 3,2,3,4,5,6,6,7,8,4 };

	// normally do this way 
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

	// see each in array as a variable
	for (int n : arr) {
		cout << n << ' ';
		n++;
	}
	cout << endl;
	// but there is no change n value with n++;
	// n is like   int n = arr[6];
	// so it doesn't change the value of arr[6]
	for (int n : arr) {
		cout << n << ' ';
	}
	cout << endl;

	// when you add before n,, then it will change the value
	// using reference variable like pointer
	for (int& n : arr) {
		cout << n << ' ';
		n++;
	}
	cout << endl;
	for (int n : arr) {
		cout << n << ' ';
	}
	cout << endl;



	for (int n : arr) {
		cout << n + 1 << ' ';
	}
	cout << endl;

	// 포인터 *
	// int *p = &a;
	// *p =10;    
	// p가 가리키는 변수 a의 값을 10으로 바꿔줌.

	//레퍼런스 & 변수 reference
	// int &p = a;
	// p = 10; 
	// 이렇게만 적어도 p가 가리키는 변수 a의 값을 10으로 바꿔줌

	int g(5); // g 변수를 5로 초기화
	int& p = g; // 레퍼런스 변수 p 가 g를 가리킴
	p = 10; // p의 값을 10으로 대입하면, p가 가리키는 g의 값이 변함

	cout << p << endl;
	cout << g << endl;

	// 두개의 변수 값을 뒤바꾸는 swap 이란 함수이기 때문에 
	// call by value로 하면 의미가 없음.  
	int a(5), b(7);

	swap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;


	// r-value &&
	// 레퍼런스 밸류에 3이나 수식은 대입할 수 없음
	// 등호를 기준으로 오른쪽 r-value 변할수 없는 변수, 
	// 왼쪽ㅣ-value 변할 수 있는 밸류 
	// 변수에 레퍼런스 & 말고 && 붙이면 그것이 변할 수 없는 밸류가 되어서 
	// 수식이 뒤집힘
	//int a(5);
	//int&& r1 = a;
	int&& r2 = 3;
	int&& r3 = a * a;

	// 이걸 앞에 for 문에 적용한 것이 n 변수 앞에 & 붙이면
	// 실제로 가리키기 때문에 값을 변경 시킬 수 있었음.

	return 0;

}