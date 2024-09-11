

//struct : c와 cpp 의 struct 는 큰 차이
//class : cpp 에서 추가됨


//클래스 = 자료저장 + 자료 처리 = 변수 + 함수
//클래스(타입): 특정한 용도를 수행하기 위한 변수와 함수를 모아둔 틀
//객체(오브젝트): 그 틀을 이용하여 찍어낸 객체(변수, 메모리 상의 공간)

//int a, b, c;  // int는 붕어빵 틀, a,b,c는 붕어빵
//클래스도 붕어빵 틀, 객체는 붕어빵

#include <iostream>

using namespace std;


// 캡슐화 : OOP 속성 중 하나, 내부속성들은 보호하면서 private, 외부 사용자에게 속성들에 접근할 수 있는 인터페이스를 만드는 것
// struct 와 클래스의 차이는? 
// struct 는 private 접근 제어 지시자를 따로 적어주어야 하는데,
// struct를 class 로 바꾸면 모든 속성에 대해 private 이 default 라서 public 을 따로 선언해줘야 함. 
struct TV {

private: // 외부접근 못하게 하는 접근제어지시자
	bool powerOn;
	int channel;
	int volume;

public: // 외부접근 가능하게 하는 접근제어지시자
	
	void on() {
		powerOn = true;
		cout << "Power is on." << endl;
	}
	void off() {
		powerOn = false;
		cout << "Power is off." << endl;
	}
	void setChannel(int cnl) {
		if (cnl >= 1 && cnl <= 999) {
			channel = cnl;
			cout << "Channel is on " << cnl << ". " << endl;
		}
	}
	void setVolume(int vol) {
		if (vol >= 0 && vol <= 100) {
			volume = vol;
			cout << "Voluem is now " << vol << ". " << endl;
		}
	}


};

int main_struct() {
	TV lg;
	lg.on();
	lg.setChannel(10);
	lg.setVolume(50);
	lg.setChannel(-73); // 실행안됨
	//lg.volume = 400; 
	// setVolume을 통해 볼륨제한을 뒀지만 아직도 volume 사용가능
	//어떻게 못쓰게 하나? => 접근 제어 지시자 (CPP): private, protected, public
	// struct 안에서는 접근 가능하면서 밖에서는 접근 못하게

	
	return 0;
}