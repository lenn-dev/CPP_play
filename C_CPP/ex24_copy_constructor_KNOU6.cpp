// KNOU���� 6��  ���������
// ���� ������ ������
// VecF Ŭ���� ����� 
// VecF��ü�� ������ �� �ִ� float���� ���� �μ��� ������ �����Ǹ�,
// ������ ���� �迭�� ������ ��� �� ������ �ʱ�ȭ �Ѵ�. (�����Ҵ��ʿ�)
// �μ��� ���޵� VecF ��ü�� ������ ����� ��ȯ�� �� ������, 
// ��ü�� ����� ���͸� ����� �� �ִ�.

#include <iostream> // �����
#include <cstring> //c ���� string.h�� �����°� (�׷����� �տ� c����) �޸� ���� �뵵

using namespace std; // std��Ī������ �����ϰ� ����ϱ� ����

class VecF {
	int n; // ������ dimension
	float* arr; //���� ������� ������ // n���� �����͸� ������ �� �ִ� ������ arr
public:
	// ������
	// ���Ͱ� ���� ������ ���� d, float�� ���� a �� ����Ʈ �Ű����� nullptr (�Ű����� ���޾ȵǸ� nullptr)
	// ����Ʈ �����ڴ� �������� ����.
	// n �� d�� �ʱ�ȭ
	VecF(int d, const float* a = nullptr) : n{ d } {
		
		arr = new float[d];
		// a �� ���� �ƴϸ� �� => ����
		// a �� ���̸� ����
		//arr: ������, a: source, sizeof(float)* n: �޸�ũ��
		if (a) memcpy(arr, a, sizeof(float)* n);
	}
	// ������ ���� ������=================================================
	// �����͸� �Ҵ���� �޸𸮸� ������ �Ҵ�ޱ�
	// ���� ���� : ���� ������ �޸𸮸� �Ҵ�޾� �״�� ������
	VecF(const VecF& fv) : n{ fv.n } {
		// �޸𸮸� ������ �Ҵ����
		arr = new float[n];
		memcpy(arr, fv.arr, sizeof(float) * n);
	}
	//=================================================
	
	// �Ҹ���
	// �Ҵ���� �޸� �ݳ�
	~VecF(){
		delete[] arr;
	}

	// add ����Լ�
	// ���� ��ü�� ���� ����
	VecF add(const VecF& fv) const {
		VecF tmp(n); //n���� ������ ������ �� �ִ� tmp��ü // tmp(a, nullptr);�� ����
		for (int i = 0; i < n; i++)
			tmp.arr[i] = arr[i] + fv.arr[i];
		return tmp;
	}

	// ���� ���� ������ const
	void print() const {
		// ����Ǿ� �ִ� �޸��� ���� �������
		cout << "[";
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << "]";
	}
	
};
int main() {
	float a[3] = { 1,2,3 };
	//3���� ��ü ����, �ʱⰪ�� a�迭
	VecF v1(3, a); //1,2,3�� �����ϴ� ����
	VecF v2(v1); // v1�� �����Ͽ� v2�� ����
	// ������ ��������ڰ� ���ٸ� ������ ��������ڷ� �����ϰ� �Ǵµ�,
	// v2�� v1�� ���� �����͸� ������ �Ȱ��� �޸𸮸� ����Ű�� ������.
	// �Ҹ��ڰ� �۵��Ҷ� v1�� �������µ�, v2�� �ٽ� ���� �޸𸮸� ������� �õ��ϸ�,
	// �̹� �ݳ��� �޸𸮸� �ǵ帮�� �����ν� ������ �߻� (���� ������ ������)
	// ���� �����ڸ� ���������� ����� �־� �ذᰡ��

	float b[3] = { 2,4,6 };
	VecF v3(3, b);

	// �̵�������
	// add�Լ��� �̿��� v1,v3�� ��ҵ��� ���� ����� tmp�� v4��ü�� ���簡 ���ٵ�,
	// tmp�� ���� �Ŀ� ������ ����(�޸𸮹ݳ�)�� ���̱� ������ 
	// �� ��� �����ؼ� tmp�����ϴ� �ͺ��� ����� �״�� v4�� �̵���Ű�� �� ȿ����.
	// rvalue ������ �̿��� �̵������ڷ� ȿ������ ����
	VecF v4(v1.add(v3));


	v1.print();
	cout << endl;
	v2.print();
	cout << endl;


	// �̵�������
	





	return 0;
}