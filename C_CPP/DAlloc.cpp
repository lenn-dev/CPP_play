#include <iostream> // ����ó����
using namespace std;  // std �� ��Ī������ ��뼱���Ͽ� ��Ī���� ������ ����ȭ

int main_DAlloc() { // �����Լ�
	int* intPtr; // ��Ʈ�� �����ͺ��� intPtr����
	intPtr = new int[4];  // 4�� ��Ʈ���� ������ �޸� �����Ҵ�
	*intPtr = 10; // intPtr �����Ͱ� ����Ű�� �޸𸮿� 10�� �Ҵ�
	*(intPtr + 1) = 20; // intPtr�� ����Ű�� �޸� �ּ��� ���� �޸𸮿� 20�� �Ҵ�
	intPtr[2] = 30; // ������ intPtr �� �ε���[2] �� �޸𸮿� 30����
	intPtr[3] = 40; // ������ intPtr �� �ε���[3] �� �޸𸮿� 40����
	for (int* p = intPtr, i = 0; i < 4; i++) // intPtr �����Ͱ� ����Ű�� �ּ� �������� �����͸� �ϳ��� �Űܰ��� ����
		cout << p[i] << " "; // ���� ��ġ�� ����Ű�� ���� ���� ���
	cout << endl; // �ٹٲ�
	delete[] intPtr; // �޸� �����Ҵ��� intPtr�� �޸� ��ȯ
	return 0; // �Լ� ��������
}

