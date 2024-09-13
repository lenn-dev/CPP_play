// ex15,16 �� �ڵ�� ���
// ������ ���ǵǾ��ٰ� �ؼ� 15,16 �ڸ�Ʈ ó����.
// ��ü�� ���� ���� �Ҵ�

#include <iostream>

using namespace std;

class Vector2 {
public:
	// ������
	Vector2() :x(0), y(0) {
		// this�� �����ڰ� ȣ��� ��ü�� �ּҰ�
		cout << this << " : Vector2()" << endl;
	}
	Vector2(const float x, const float y) : x(x), y(y) {
		cout << this << " : Vector2(const float x, const float y)" << endl;
	}
	//�Ҹ���
	~Vector2() {
		// this�� �Ҹ��ڰ� ȣ��� ��ü�� �ּҰ�
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

	// ȭ��ǥ ǥ���� ����ü �� �� �ߴ� ����
	// ����ü ������ Ŭ�������� ���밡����
	// ��ü d1 �� ����Ű�� �ִ� �� Ŭ������ ���ԵǾ� �ִ� ����� �Լ��� ȣ����
	cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << endl;
	cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << endl;

	delete d1;
	delete d2;

	return 0;
}

// ��°��� ���� d1,d2�� ���� �Ҹ�ǰ�, 
// �� ���� �����Ҵ��� s1,s2�� ���α׷� ����Ǹ鼭 �Ҹ�ȴ�. 