#include <iostream>

using namespace std;

class MyClass {
public:
	void PrintThis() {
		cout << "My address is..." << this << endl; 
		// this�� �ڱ� �Ҽӵ� ��ü�� �ּ�
		// ��� Ŭ������ struct �ȿ� �ִ� ������� 
		// this ��� �����͸� ������ �ʴ� �Ű����� ���·� �޾Ƶ�.
		// ���� PrinThis �� a,b ��ü �� ��� ���ϴ��� �� �� �ִ� ����.
		// PrintThis() �Լ��� �� ��ü �ȿ� �����ϴ°��� �ƴ϶� �ۿ� ���� ����.
		// �� void PrintThis(*ptr){
		//		cout << "My address is.." << *ptr << end; �� ����
		// �����Լ� ������ �Լ�ȣ���� a.PrintThis(&ptr); �ϰ� �Ǹ� 
		// �Ű����� ���� this �������� ���� �ش� �ּҸ� ��ȯ��.		
	}
};


int main_this() {
	MyClass a, b; // ��ü ����

	cout << "Address of a is .." << &a << endl;
	cout << "Address of b is .." << &b << endl;

	a.PrintThis();
	b.PrintThis();

	return 0;
}