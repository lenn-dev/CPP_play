// 시간을 저장하는 클래스 만들기
// 시 분 초 
// 생성자에 집중하는 예제라서 getter setter 는 안쓸 예정

#include <iostream>

using namespace std;

class Time {
public:
	
	//Time() {
	//	h = 0;
	//	m = 0;
	//	s = 0;
	//}
	//Time(int s_) {
	//	s = s_;
	//}
	//Time(int m_, int s_) {
	//	m = m_;
	//	s = s_;
	//}
	//Time(int h_, int m_, int s_) {
	//	h = h_;
	//	m = m_; 
	//	s = s_;
	//}

	// 위의 표현을 생성자 목록으로 간단히 만들어 보자
	/*Time(): h(0),m(0),s(0){}
	Time(int s) : s(s) {}
	Time(int m, int s): m(m), s(s){}
	Time(int h, int m. int s): h(h), m(m), s(s){}*/


	//생성자 위임 : 클래스 안에서 특정 생성자가 다른 생성자를 호출할 수 있는 기능
	//생성자의 매개변수가 공통된 부분이 있는 경우 그 공통된 부분을 지우고
	// 그에 해당하는 생성자를 호출하는 방식
	Time() : h(0), m(0), s(0) {}
	Time(int s_) : Time() {
		s = s_;
	}
	Time(int m_, int s_): Time(s_) {
		m = m_;
	}
	Time(int h_, int m_, int s_) : Time(m_,s_) {
		h = h_;
	}
	// Time(2,34,20) 를 호출 했을때 실행순서
	// 먼저 Time(int h_, int m_, int s_) 이 호출되고, : 콜론 옆 호출함수 확인해서 이동
	// Time(int m_, int s_) 호출하고 : 콜론 옆 호출함수 확인 후 이동
	// Time(int s_) 호출 후 : 콜론 옆 호출함수 확인 후 이동
	// Time() 로 이동한 후 h, m, s에 초기값 0으로 세팅 h = 0; m = 0; s = 0;
	// Time(int s_)의 s =_s; 실행 즉, s = 20;
	// Time(int m_, int s_)의 m = m_; 실행 즉, m = 34;
	// Time(int h_, int m_, int s_)의 h = h_; 실행 즉, h = 2;  

	// 생성자 위임의 장점
	// 많은 오버로딩으로 함수가 적혀있는 상태에서 
	// 어떤 변수 하나 수정했을 때 수정이 간편함. 
	// 생성자 위임이 되지 않아 있다면 공통된 변수 부분을 모두 일일이 수정해야 하는 번거로움
	// 코드 짧아서 오류 적어짐.


// 지금은 getter setter 안만들어서 private 을 public으로 두겠음
// 원래 이렇게 하면 안됨
//private:
	int h;
	int m;
	int s;

};

int main_time() {

	Time t1;
	Time t2(5);
	Time t3(3, 16);
	Time t4(2, 42, 15);


	cout << "t1 : " << t1.h << " : " << t1.m << " : " << t1.s << endl;
	cout << "t2 : " << t2.h << " : " << t2.m << " : " << t2.s << endl;
	cout << "t3 : " << t3.h << " : " << t3.m << " : " << t3.s << endl;
	cout << "t4 : " << t4.h << " : " << t4.m << " : " << t4.s << endl;
	


	return 0;
}
