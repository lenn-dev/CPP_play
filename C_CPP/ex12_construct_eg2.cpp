// �ð��� �����ϴ� Ŭ���� �����
// �� �� �� 
// �����ڿ� �����ϴ� ������ getter setter �� �Ⱦ� ����

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

	// ���� ǥ���� ������ ������� ������ ����� ����
	/*Time(): h(0),m(0),s(0){}
	Time(int s) : s(s) {}
	Time(int m, int s): m(m), s(s){}
	Time(int h, int m. int s): h(h), m(m), s(s){}*/


	//������ ���� : Ŭ���� �ȿ��� Ư�� �����ڰ� �ٸ� �����ڸ� ȣ���� �� �ִ� ���
	//�������� �Ű������� ����� �κ��� �ִ� ��� �� ����� �κ��� �����
	// �׿� �ش��ϴ� �����ڸ� ȣ���ϴ� ���
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
	// Time(2,34,20) �� ȣ�� ������ �������
	// ���� Time(int h_, int m_, int s_) �� ȣ��ǰ�, : �ݷ� �� ȣ���Լ� Ȯ���ؼ� �̵�
	// Time(int m_, int s_) ȣ���ϰ� : �ݷ� �� ȣ���Լ� Ȯ�� �� �̵�
	// Time(int s_) ȣ�� �� : �ݷ� �� ȣ���Լ� Ȯ�� �� �̵�
	// Time() �� �̵��� �� h, m, s�� �ʱⰪ 0���� ���� h = 0; m = 0; s = 0;
	// Time(int s_)�� s =_s; ���� ��, s = 20;
	// Time(int m_, int s_)�� m = m_; ���� ��, m = 34;
	// Time(int h_, int m_, int s_)�� h = h_; ���� ��, h = 2;  

	// ������ ������ ����
	// ���� �����ε����� �Լ��� �����ִ� ���¿��� 
	// � ���� �ϳ� �������� �� ������ ������. 
	// ������ ������ ���� �ʾ� �ִٸ� ����� ���� �κ��� ��� ������ �����ؾ� �ϴ� ���ŷο�
	// �ڵ� ª�Ƽ� ���� ������.


// ������ getter setter �ȸ��� private �� public���� �ΰ���
// ���� �̷��� �ϸ� �ȵ�
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
