//// 연산자 오버로딩 - 을 알기위해 벡터, 멤버 메서드를 알아야함
//// 벡터: 내적(도트곱), 외적 곱
//// 멤버 메서드 : 선언, 정의 분리하기
//// 메서드를 포함한 클래스는 네임스페이스 역할을 할 수 있음
//
//#include <iostream>
//
//using namespace std;
//
////성분이 2개인 벡터 클래스
//class Vector2 {
//public:
//	// 매개변수 없을 때 생성자, 초기화
//	//Vector2() : x(0), y(0) {}
//	// 멤버 메서드 선언, 정의 분리를 위해
//	//선언만 하고, 정의는 클래스 바깥에서
//	// why?
//	Vector2();
//
//
//	// 매개변수 있을 때 생성자
//	//Vector2(float x, float y): x(x), y(y){}
//	// 멤버 메서드 선언, 정의 분리
//	Vector2(float x, float y);
//
//
//	// getter
//	// const 함수로 만들 수 있는 건 모두 const로 하는게 좋음
//	//float GetX() const { return x; }
//	// getter함수도 선언, 정의 분리
//	// const 까지 컴파일러가 알고 있어야 하기 때문에 선언에 포함
//	float GetX() const;
//
//
//	//float GetY() const { return y; }
//	float GetY() const;
//
//
//	// 이 경우에는 setter가 없는 편이 나음
//	// 하나의 변수의 값만 변할 때 변경시키는 것보다
//	// 아예 하나의 객체를 다시 생성해서 대입하는 것이 낫기 때문
//
//
//	// 연산자 오버로딩으로 객체끼리 연산 배우기전에 
//	// 함수를 만들어서 대체해서 사용하는 방법, 반환형이 Vector2
//	// Vector2 타입을 반환하고 매개변수로 두 개의 Vector2를 받는 Sum 이라는 함수 
//	// 클래스 안에 함수선언하려면 static 선언 해야 함.
//	// ***********************************************************************
//	// static 메서드는 전역함수로 쓰고 싶고, class 와 밀접한 연관이 있으면서도
//	// 클래스 안에 private 변수에 접근하고 싶을때 클래스에 넣고 사용함.
//	// 그럼으로 인해서 객체 찍어낼때마다 그 객체에 포함되는 것이 아니라
//	// 클래스에 포함된 하나뿐인 메서드가 되는 것임 
//	// *********************************************************************** 
//	// 정적메서드 : 클래스에 속하고 어떤 객체에도 속하지 않음
//	// 따라서 구체적으로 더해야할 요소를 알려줘야 함.
//	static Vector2 Sum(Vector2 a, Vector2 b) {
//		// Vector2의 객체를 만들고 아래의 수식을 연산한 후 반환해라
//		//return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
//		// 클래스 안에 들어왔으니 private 접근 가능해서 메서드이름 쓸필요 없어짐
//		return Vector2(a.x + b.x, a.y + b.y);
//	}
//	
//	// 연산자 오버로딩의 개념과 비슷한 Add 함수 만들기
//	// 기본 개념은 객체안의 동적메서드를 이용해 자기자신과 매개변수를 더하는 함수
//	//rhs = right hand side 우변 : 연산자 우측에 있는 것, lhs = 좌변
//	// 동적 메서드 : 모든 객체에 소속됨
//	// 특정 개체에 포함되어 있을 수 있기 때문에, 내 객체와 매개변수로 받은 것을 연산해라.
//	// Add 함수 이름을 operator+ 로 바꿈 예약어인데 함수처럼 사용 가능.
//	Vector2 Add(Vector2 rhs) {
//		//x 는 자기자신의 x
//		return Vector2(x + rhs.x, y + rhs.y);
//	}
//
//private:
//	float x;
//	float y;
//};
//
//
//
//int main_vector() {
//	Vector2 a(2, 3);
//	Vector2 b(-1, 4);
//	// 벡터끼리의 연산을 하고 싶은데 객체끼리의 연산은 어떻게 할까?
//	// 그것이 연산자 오버로딩이라는 것
//	//Vector2 c = a + b;
//
//	// Sum 함수를 새로 만들어 사용 : 정적메서드 이용
//	Vector2 c1 =  Vector2::Sum(a, b);
//	// a라는 객체 안에 Add와 매개변수 b를 합한 값을 반환 : 동적메서드 이용
//	Vector2 c2 = a.Add(b);
//
//	
//	cout << a.GetX() << ", " << a.GetY() << endl;
//	cout << b.GetX() << ", " << b.GetY() << endl;
//	cout << c1.GetX() << ", " << c1.GetY() << endl;
//	cout << c2.GetX() << ", " << c2.GetY() << endl;
//	
//
//
//	return 0;
//}
//
//// 멤버 메서드의 선언과 정의 분리
//// 클래스 밖에서 정의 할때 Vector2 클래스 안에 Vector2 메서드를 명시하기 위해
//// 네임스페이스처럼 사용함
//Vector2 :: Vector2() : x(0), y(0) {}
//Vector2 :: Vector2(float x, float y) : x(x), y(y) {}
//
//// 반환타입 - 함수가 속한 네임스페이스- 함수 - const - 정의
//float Vector2 :: GetX() const { return x; }
//float Vector2 :: GetY() const { return y; }