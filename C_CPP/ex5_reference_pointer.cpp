//�ּ��ޱ� ctrl+k, ctrl+c
//�ּ����� ctrl+k, ctrl+u

//1. �̸��� ������ �Է¹ް�, ������ ���� ��µǴ� ���α׷��� �ۼ��Ͻÿ�.
//�̸��Է�: �ε鳫��
//�����Է�: 89
//�ε鳫������ ������ 89���Դϴ�.

//2. ������ �迭 ����غ���

#include <iostream>
#include <string>

using namespace std;


int main() {
	string name;
	int score;

	cout << " �̸��Է� :";
	cin >> name;
	cout << "���� �Է� : ";
	cin >> score;
	cout << name << "���� ������ " << score << " �� �Դϴ�." << endl;

	// ������� for �� ����ؼ� 2�����迭 ����ϱ�

	int arr[2][3] = { {1,2,3},{4,5,6} };

	//=========�������� �õ�==================================
	// �õ� 1 >> ���� : n�� int �����Ϳ��� ��.
	//for (int n : arr) {
	//	cout << n << endl;
	//}


	//�õ� 2 >>
	for (int* n : arr) {
		cout << *n << endl;
	}
	// ��°� 1 4  
	// �� ���� 0��° ��� ��µ�
	// �迭 �̸����� �� �ּҰ��� �� �迭�� 0��° ���


	// �õ�3 >> ���� Ʋ�� Ǯ��
	//for (int* n : arr) {
	//	for (int m : n) {
	//		cout << m << ' ';
	//	}
	//}


	// �õ� 4 >>
	// �̷��Դ� ����� ������ �츮�� ���ϴ°���
	// ���� ��� for ���� ����ϴ� ��
	//for (int* n : arr) {
	//	for (int i = 0; i < 3; i++) {
	//		cout << n[i] << ' ';
	//	}
	//}
	// �̰͵� ����� ���������� �ȵ�
	//========================================================


	// ������
	//===============1,2 for ���� ���������δ� ����� =====
	// 1. ������� for��: �迭�� ���� <<< ���۷��� >>>�� �����, 
	// �迭������ ���� ���� ���
	// 3��¥�� �迭�� ����Ű�� ��Ʈ�� ���� ln �� ����ڴ�.
	// ���۷��� ���� ����� ���� ���� �̸��� ��� ����Ű�� ����̶� 
	// ����� �� & �Ⱥ��̰� �̸��� �ᵵ �� ln
	for (int(&ln)[3] : arr) {
		for (int& col : ln) {
			cout << col << ' ';
		}
		cout << endl;
	}
	// auto �� �� �����ϰ� ���� �����
	for (auto& ln : arr) {
		for (auto& col : ln) {
			cout << col << ' ';
		}
		cout << endl;
	}
	// 2. �迭������ ����� 2���� �迭 �� ��Ҹ� ���� �����
	// 3�� ¥�� ��Ʈ�� �迭�� ����Ű�� ������ ln�� �����, arr ��������
	// �����͸� ����� ���� *����� ����� ����Ŵ *ln
	// �� ������ �迭 ������ŭ �����ϸ鼭 for loop
	for (int(*ln)[3] = arr; ln < arr + 2; ln++) {
		for (int* c = *ln; c < *ln + 3; c++) {
			cout << *c << ' ';
		}
		cout << endl;
	}
	//==========================================================================

	// 3. ������ ���� �Լ� ���ǿ��� ������ ������ ���� ������?
	// �� �Լ����� ���� main �Լ� �ۿ� ���� �Ǿ�� �ϴµ� �����Ƽ� �׳� 
	// �ڸ�Ʈ �ƿ��ϰ� �� �ȿ� ��....

	// ����1. ����Ʈ ������ �����ʺ��� ����� => ���������� �Ű����� ����
	// ����2. �ű����ν� �� �Լ��� ������ �������.
	// 
	// ���簢�� �׸��� �ΰ��� ���
	//1. ���簢�� �� ���� ��ǥ�� �Ű������� �޴´�.
	//void drawRectangle(int l, int r, int t, int b) {

	//}
	//2. ���簢�� �𼭸��� ��ǥ (x,y) �� �ʺ�, ���̸� �޴´�.
	//void drawRectangle(int w, int h, int x = 0, int y = 0) {

	//}





	return 0;

}