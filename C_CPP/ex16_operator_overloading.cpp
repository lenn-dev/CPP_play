// 62강.연산자 오버로딩
// ex15 의 코드를 그대로 가져와서 변형함

#include <iostream>

using namespace std;


class Vector2 {
public:
	Vector2();
	Vector2(float x, float y);

	float GetX() const;
	float GetY() const;

	// Add 함수 이름을 operator+ 로 바꾸기
	// 예약어 operator를 일반적인 함수로 쓸 수 있음.
	// 선언,정의 분리해주고, 함수,매개변수 const 선언하기 
	// (자기자신의 값에 매개변수를 연산하는 것이라 자기자신은 변하지 않음)
	// **클래스 멤버함수에 const 붙이는 이유는 
	// 멤버함수가 클래스 안의 멤버변수의 값을 바꾸지 못하도록 하기 위해서 이므로
	// 클래스 바깥에 선언,정의된 함수는 const 붙일 수 없음.
	// 멤버연산자(공식적인 이름 아님), 멤버메서드 역할을 하기 때문. 
	// 멤버연산자는 자신의 값에 우변으로 하는 새로운 매개변수만을 받음
	Vector2 operator+(const Vector2 rhs) const;
	Vector2 operator-(const Vector2 rhs) const;
	Vector2 operator*(const float rhs) const;
	Vector2 operator/(const float rhs) const;
	float operator*(const Vector2 rhs) const;

private:
	float x;
	float y;
};

// 비멤버연산자(공식적인 이름 아님): 클래스 바깥에서 쓰이는 전역 연산자.
// 비멤버연산자는 자기자신의 개념이 없어
// 매개변수(좌변,우변) 두개를 동시에 받아 연산하게 됨.
// 실수, 더블형에 벡터를 곱하는 함수
// 클래스에 포함안되는 전역함수이기 때문에 메서드 GetX(), GetY()적어줘야 함
Vector2 operator*(const float a, const Vector2 b) {
	return Vector2(a * b.GetX(), a * b.GetY());
}

int main_operator() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);

	// 연산자 - 만 적어두어도 연산자를 호출하고 있음.일종의 함수역할도 함
	// 즉, 연산자도 일반메서드와 비슷하게 볼 수 있는데 
	// 다만 연산자로 간단하게 표현하고 호출할 수 있다는 것이 다름.
	Vector2 c1 = a - b;
	// 벡터에 실수를 곱하는 연산, 실수 * 벡터로 순서 바꾸면 에러
	// double, float 은 객체가 아니기 때문에 여기에 operator 함수를 적용할 수 없음
	Vector2 c2 = a * 1.6;
	// operator 를 사용함으로 인해서 객체끼리의 연산이 가능해짐
	// 강의에서는 + 에 마우스 대면 Vector2 Vector2::operator+(Vector2 rhs) 라고 나오는데 나는 안나옴.
	
	// 객체 c3 는 실수 * 객체 (좌변,우변)를 매개변수로 받기 때문에 
	// 클래스 바깥에 정의한 Vector2 operator*(const float a, const Vector2 b) 가 호출됨
	// 바깥에 정의한 이유는 객체가 아닌 실수에 
	// 연산자 오버로딩(자기자신 값에 받은 매개변수 연산하는 것)을 할 수 없기 때문에 
	// (연산자 operator는 일종의 함수처럼 쓰임) 클래스 밖에 선언,정의 
	// ???
	// c 에서 제공되는 기본적 자료형 (double, float..등)은 연산자 오버로딩 불가능
	// 즉,Vector2 c3 = 1.6 * a; 는 1.6.operator*(a) 가 가능해야 하는데 
	// .operator* 이 period를 찍고 메서드를 호출하는 방식이 어떤 객체대상에 속해야 하는 것인데,
	// 1.6은 객체가 아니라 불가능한 것임
	// 만일 가능하다고 하면 Vector2 의 Vector2 operator* (const Vector2 rhs) const; 를 호출해서 연산할텐데
	// 1.6은 객체가 아니기 때문에 불가능.
	Vector2 c3 = 1.6 * a;
	// 벡터*벡터의 결과는 실수
	float c4 = a * b;

	cout << a.GetX() << ", " << a.GetY() << endl;
	cout << b.GetX() << ", " << b.GetY() << endl;
	cout << c1.GetX() << ", " << c1.GetY() << endl;
	cout << c2.GetX() << ", " << c2.GetY() << endl;
	cout << c3.GetX() << ", " << c3.GetY() << endl;
	cout << c4 << endl;

	return 0;
}


Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}


float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }

//Vector2 자료형을 반환하는 Vector2 클래스의 상수형 operator+함수, 상수형 매개변수 Vector2 rhs를 받음
Vector2 Vector2::operator+(const Vector2 rhs) const {
	// x, y 는 자기 자신을 말함
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2 rhs) const {
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const {
	return Vector2(x * rhs, y * rhs);
}

Vector2 Vector2::operator/(const float rhs) const {
	return Vector2(x / rhs, y / rhs);
}

float Vector2::operator*(const Vector2 rhs) const {
	return x * rhs.x, y* rhs.y;
}