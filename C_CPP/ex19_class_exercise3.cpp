// ���� �ڵ带 �а� ����� �����غ���
// �ڵ带 �����ĵ� ����� ���� ����. 
// ���ǿ����� �Ű����� obj�� ptr �ּҰ��� ���� ���� �̿��Ͽ� ���ư��� ���α׷��ε�
// ���� ��°���� �� �Ͱ� �ٸ��� ����. 
// obj, ptr���� for�� ��� ���Ƶ� �Ȱ��� 000000D8DAEFF6B8�� ������,
// num�� ��������� �� - 858993460
// cnt = 0 ���� ����.....
// cnt++ �� �ȵǴ� ����. 
// ������ ���Ǹ� �� ���� �Ұ� ����, 64���� �ٽ� ����
// ������ ��� �����Ҵ翡�� �߿��� ���� ������ ������...

#include <iostream>

using namespace std;

class MyClass {
public:
	// MyClass ��ü�� �����ɶ����� num cnt�ְ� 1�� ����������
	MyClass(): num(cnt++),ch('\0'){ }
	
	// �� ptr���� &obj[0] = obj �ּҰ��� ����Ǵ� ��
	// ���� ptr = obj
	// for ������ ��� �� ���� �Ű������� �Ѱ��ְ� ����
	void Check(MyClass *ptr) {
		// ptr + num �� &ptr[num]�� ����
		// �� ���⼱ &ptr[num] = &obj[num]
		//cout << " ptr address :" << ptr << endl;
		//cout << " num :" << num << endl; 

		// ������ + ������ ���꿡���� ����ȯ�� �Ͼ�� ����
		// ���� ������ Ÿ�Կ� ����Ÿ���� ���� ������� ������ Ÿ����? 
		// 25 �� ����
		if (ptr + num == this) {
			cout << num << endl;
		}
	}
	static int cnt;
	
private:
	int num;
	char ch;
};
int MyClass::cnt = 0;

int main_ex() {
	// Myclass �� ��ü obj �迭����
	// �̺κ� ������ �ȵǴ°� ����? 
	MyClass obj[5]; 
	//�����ڰ� ȣ��� *5

	cout << "Test #1 : " << endl;
	//obj�� �ε��� 0-4���� ���鼭 Check() �Լ� �����µ� �Ű������� obj
	for(int i = 0; i < 5; i++) {
		//�Ű������� obj �� &obj[0] �� �Ȱ��� ��, 
		// �� obj 0��°�� �ּҰ��� �Ű������� �Ѱ�ٴ� ��
		
		obj[i].Check(obj);
		cout << "obj address" << obj << endl;
	}
	cout << "Test #2 : " << endl;
	//�ι�° for���� ���۷������� i�� ù��° for���� obj[i]�� ����(����Ű��)�ϰ� ����.
	// ������� for�� 
	for(MyClass &i : obj) {
		i.Check(obj);
	}
	cout << "cnt = " << MyClass::cnt << endl;

	return 0;
}