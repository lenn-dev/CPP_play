// 클래스 객체 생성

// 생성자: 객체가 생성될 때 자동으로 호출되는 함수
// 소멸자: 객체가 소멸될 때 자동으로 호출되는 함수

#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass() { // 생성자
		cout << "생성자가 호출됨" << endl;
	}
	~MyClass() { // 소멸자
		cout << "소멸자가 호출됨" << endl;
	}
};

//MyClass globalobj;

void testLocalObj() {
	cout << "testLocalObj 함수시작" << endl;
	MyClass localObj;
	cout << "testLocalObj 함수 끝" << endl;
}

int main_contruct() {
	cout << " main함수 시작" << endl;
	testLocalObj();
	cout << " main함수 끝" << endl;
	
	return 0;
}

// 생성자,소멸자 안적어줬을땐 어떻게 되나?
// 디폴트로 작성된 생성자 소멸자 있음


// 언제 생성자, 소멸자 쓰일까?
// 생성자: 멤버 변수 초기화
// 소멸자: 메모리 해제


