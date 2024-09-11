#include <iostream>

using namespace std;

int n; 

void set();

namespace doodle {
	int n;
	void set();
}
namespace google {
	int n; 
	void set();
}

// 중첩 namespace 
namespace roogle {
	int n;
	void set() {
		n = 20;
	}
	namespace noogle {
		int n;
		void set() {
			n = 70;
		}
	}
}

int main_namespace() {
	::set();
	doodle::set();
	google::set();
	roogle::set();
	roogle::noogle::set();

	cout << ::n << endl;
	cout << doodle::n << endl;
	cout << google::n << endl;
	cout << roogle::n << endl;
	cout << roogle::noogle::n << endl;

	return 0;
}

void ::set() {
	::n = 10; // 전역에 있는 n 이 10
}
namespace doodle {
	void set() {
		doodle::n = 20; //두들 네임스페이스 안에 n 이 20
	}
}
// 위의 방식을 밑에처럼 표현해도 됨
void google::set() {
		doodle::n = 30;
	}



