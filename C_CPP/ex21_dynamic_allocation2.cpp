//�迭�� �Ҵ� : ���ϴ� ���̸�ŭ �����Ҵ�
// arr = &arr[0]
#include <iostream>

using namespace std;

int main_dynamic2() {
	int* arr;
	int len;

	cout << "�����Ҵ��� �迭 ���� �Է� :";
	cin >> len; 
	
	// int���� �迭�� len���̸�ŭ ����µ� 
	// �� �迭�� 0��° �ּҰ��� ��ȯ�ؼ�
	// ������ arr �� �Ҵ�
	// *************************************
	// ���� arr �� �迭ó�� �� �� ����
	//**************************************
	arr = new int[len];

	for (int i = 0; i < len; i++) {
		arr[i] = len - i;
	}
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}
	
	// ���⼭ ������ arr �� �����Ͷ� 0��°�� �����ϰ� �������� ��������
	// delete arr;

	// �迭 �����ٶ��� �̷���
	delete[] arr;

	return 0;
}