// Ŭ���� ��ü ����

// ������: ��ü�� ������ �� �ڵ����� ȣ��Ǵ� �Լ�
// �Ҹ���: ��ü�� �Ҹ�� �� �ڵ����� ȣ��Ǵ� �Լ�

#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass() { // ������
		cout << "�����ڰ� ȣ���" << endl;
	}
	~MyClass() { // �Ҹ���
		cout << "�Ҹ��ڰ� ȣ���" << endl;
	}
};

//MyClass globalobj;

void testLocalObj() {
	cout << "testLocalObj �Լ�����" << endl;
	MyClass localObj;
	cout << "testLocalObj �Լ� ��" << endl;
}

int main_contruct() {
	cout << " main�Լ� ����" << endl;
	testLocalObj();
	cout << " main�Լ� ��" << endl;
	
	return 0;
}

// ������,�Ҹ��� ������������ ��� �ǳ�?
// ����Ʈ�� �ۼ��� ������ �Ҹ��� ����


// ���� ������, �Ҹ��� ���ϱ�?
// ������: ��� ���� �ʱ�ȭ
// �Ҹ���: �޸� ����


