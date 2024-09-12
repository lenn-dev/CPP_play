#include <iostream>

using namespace std;

// 생성자 : 멤버 변수 초기화
// 복소수complex (실수real+ 허수imaginary?) 저장하는 클래스 생성하기

class Complex {
public:

	// 생성자 : 멤버 변수 초기화
	/*Complex() {
		real = 0; 
		imag = 0;
	}*/
	// 초기화목록: 괄호 사용해서 초기값주는 간단한 표현
	Complex() : real(0), imag(0) {}
	// 생성자도 함수이니 오버로딩 가능
	// 하지만 초기화를 생성자 매개변수를 디폴드값을 주면 
	// 구지 오버로딩 하지 않을 수 있음
	// 매개변수에 _ 언더바 넣지 않으면 
	// real 멤버변수와 real_매개변수의 구분이 없어져 둘다 매개변수로 인식해서 안됨.
	// 초기화목록 표현으로 하면 _언더바 없어도 에러안뜸
	// 이유는 real(real) 괄호 왼쪽에는 멤버변수만 오고 괄호안에는 매개변수만 오는 규칙때문 
	/*Complex(double real_,double imag_) {
		real = real_;
		imag = imag_;
	}*/
	//초기화목록: 위의 생성자를 간단히 표현한 방법
	Complex(double real_,double imag_): real(real_), imag(imag_){}
	



	//실수 getter setter
	double getReal() {
		return real;
	}
	void setReal(double real) {
		real = real;
	}
	//허수 getter setter 
	double getImag() {
		return imag;
	}
	void setImag(double imag) {
		imag = imag;
	}
private:
	double real;
	double imag;
};

int main_construct1() {

	// 함수는 아니지만 함수처럼 오버로딩한다음 
	// 변수에 갯수에 따라 실행시켜줄 수 있음.
	Complex c1; // Complex 클래스의 객체 c1 생성, 첫번째 생성자 실행됨
	Complex c2 = Complex(2,3); // 두번째 생성자 실행됨
	Complex c3(2, 3); // 두번째보다 간단한 객체생성방법
	Complex c4 = { 2,3 }; 
	Complex c5 = Complex{ 2,3 };
	Complex c6{ 2,3 };


	cout << "c1 = " << c1.getReal() << ", " << c1.getImag() << endl;
	cout << "c2 = " << c2.getReal() << ", " << c2.getImag() << endl;
	cout << "c3 = " << c3.getReal() << ", " << c3.getImag() << endl;
	cout << "c4 = " << c4.getReal() << ", " << c4.getImag() << endl;
	cout << "c5 = " << c5.getReal() << ", " << c5.getImag() << endl;
	cout << "c6 = " << c6.getReal() << ", " << c6.getImag() << endl;

	return 0;
}