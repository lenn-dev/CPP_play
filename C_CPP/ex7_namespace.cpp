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

// ��ø namespace 
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
	::n = 10; // ������ �ִ� n �� 10
}
namespace doodle {
	void set() {
		doodle::n = 20; //�ε� ���ӽ����̽� �ȿ� n �� 20
	}
}
// ���� ����� �ؿ�ó�� ǥ���ص� ��
void google::set() {
		doodle::n = 30;
	}



