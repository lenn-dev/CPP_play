#include <iostream> // ����ó����, ǥ�� ����� ���̺귯�� ����
using namespace std;  // std �� ��Ī������ ��뼱���Ͽ� ��Ī���� ������ ����ȭ

int main_reference() { // �����Լ�
	int a = 10, b = 20; //������ ���� a,b �� ���� 10,20 �Ҵ�
	int& aRef = a; // ��Ʈ���� a ������ �����ϴ� �������� aRef ����,�����Ϳ� ����
	cout << "a�� �� : " << a << endl; // a�� ���
	cout << "aRef�� �����ϴ� �� : " << aRef << endl << endl; // aRef������ ���
	aRef = 100; // aRef�� �����ϴ� ���� ���� 100���� �Ҵ�
	cout << "a�� �� : " << a << endl; // a�� ���, 100
	aRef = b; // aRef�� �����ϴ� ���� b �� �Ҵ�
	cout << "a�� �� : " << a << endl << endl; //20
	return 0; // �Լ� ���� ����
}

