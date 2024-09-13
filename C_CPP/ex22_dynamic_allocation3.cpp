// ex15,16 의 코드와 비슷
// 여러번 정의되었다고 해서 15,16 코맨트 처리함.
// 객체에 대한 동적 할당

#include <iostream>

using namespace std;

class Vector2 {
public:
	// 생성자
	Vector2() :x(0), y(0) {
		// this는 생성자가 호출된 객체의 주소값
		cout << this << " : Vector2()" << endl;
	}
	Vector2(const float x, const float y) : x(x), y(y) {
		cout << this << " : Vector2(const float x, const float y)" << endl;
	}
	//소멸자
	~Vector2() {
		// this는 소멸자가 호출된 객체의 주소값
		cout << this << " : ~Vector2()" << endl;
	}

	float GetX() const { return x; }
	float GetY() const { return y; }
private:
	float x; 
	float y;
};

int main_dynamic3() {
	Vector2 s1 = Vector2();
	Vector2 s2 = Vector2(3, 2);

	Vector2* d1 = new Vector2();
	Vector2* d2 = new Vector2(3, 2);

	// 화살표 표현은 구조체 할 때 했던 내용
	// 구조체 문법이 클래스에도 적용가능함
	// 객체 d1 이 가리키고 있는 그 클래스에 포함되어 있는 멤버의 함수를 호출함
	cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << endl;
	cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << endl;

	delete d1;
	delete d2;

	return 0;
}

// 출력값을 보면 d1,d2가 먼저 소멸되고, 
// 그 다음 정적할당한 s1,s2이 프로그램 종료되면서 소멸된다. 