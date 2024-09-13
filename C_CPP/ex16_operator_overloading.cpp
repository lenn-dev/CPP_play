// 연산자 오버로딩
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
	Vector2 operator+(const Vector2 rhs) const;
	Vector2 operator-(const Vector2 rhs) const;
	Vector2 operator*(const float rhs) const;
	Vector2 operator/(const float rhs) const;
	float operator*(const Vector2 rhs) const;

private:
	float x;
	float y;
};

// 실수, 더블형에 벡터를 곱하는 함수
Vector2 operator*(const float a, const Vector2 b) {
	return Vector2(a * b.GetX(), a * b.GetY());
}

int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	Vector2 c1 = a - b;
	// 벡터에 실수를 곱하는 연산, 실수 * 벡터로 순서 바꾸면 에러
	// double, float 은 객체가 아니기 때문에 여기에 operator 함수를 적용할 수 없음
	Vector2 c2 = a * 1.6;
	// operator 를 사용함으로 인해서 객체끼리의 연산이 가능해짐
	// 강의에서는 + 에 마우스 대면 Vector2 Vector2::operator+(Vector2 rhs) 라고 나오는데 나는 안나옴.
	Vector2 c3 = a / 2;
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