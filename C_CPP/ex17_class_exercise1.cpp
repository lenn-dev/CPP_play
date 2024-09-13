//class ���չ���
// ���� ���α׷��� ��� �����?

#include <iostream>

using namespace std;

int n = 0;
namespace A {
	int n = 0;
	namespace B {
		void set() { n = 10; }
		int n = 0;
	}
}
// set() �Լ� ����,���� �и��Ǿ� ����
namespace C {
	void set();
	int n = 0;
}
void C::set() { n = 20; }

int main_namespace() {
	using namespace A::B;

	// �Ʒ� ���� �� �Ŀ� ��� ��µǴ��� �˱�
	// A�� ���� �ִ� B�ȿ��� set() �Լ� ã��.
	// n �� 10���� �϶�� �Ǿ� ����.
	// ���� �ö� n���� ã��. 
	// ���� int n = 0 �� 10���� �ٲ�
	set(); //A::B::set()
	
	// C�� ���� set() �Լ� ã��
	// ã�Ҵµ� ����,���� �и��Ǿ� �־ ���Ǻκ� ã�ư�
	// n�� 20���� �϶�� �Ǿ� ����
	// C�� n�� �ִ��� ã�ƺ� 
	// C�ȿ� int n = 0 ���� 20���� �ٲ�.
	C::set(); // C:: set()
	

	//=======================================================================
	// ::n�� using namespace A::B; �� �����Ƿ� 
	// A::B::n�� ���� 
	// B�ȿ� �ִ� n �� 0
	cout << ::n << endl; //0
	
	// ��������� A�� �ִ� n �� ���� set()���� ���� 10���� �ٲ�� ����.
	cout << A::n << endl; //10


	cout << A::B::n << endl; //0
	
	// C �� �ִ� n�� C::set() ���� ���� 20���� �ٲ�� ����.
	cout << C::n << endl; //20

	return 0;
}