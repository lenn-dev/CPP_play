#include <iostream>

using namespace std;

// ������ : ��� ���� �ʱ�ȭ
// ���Ҽ�complex (�Ǽ�real+ ���imaginary?) �����ϴ� Ŭ���� �����ϱ�

class Complex {
public:

	// ������ : ��� ���� �ʱ�ȭ
	/*Complex() {
		real = 0; 
		imag = 0;
	}*/
	// �ʱ�ȭ���: ��ȣ ����ؼ� �ʱⰪ�ִ� ������ ǥ��
	Complex() : real(0), imag(0) {}
	// �����ڵ� �Լ��̴� �����ε� ����
	// ������ �ʱ�ȭ�� ������ �Ű������� �����尪�� �ָ� 
	// ���� �����ε� ���� ���� �� ����
	// �Ű������� _ ����� ���� ������ 
	// real ��������� real_�Ű������� ������ ������ �Ѵ� �Ű������� �ν��ؼ� �ȵ�.
	// �ʱ�ȭ��� ǥ������ �ϸ� _����� ��� �����ȶ�
	// ������ real(real) ��ȣ ���ʿ��� ��������� ���� ��ȣ�ȿ��� �Ű������� ���� ��Ģ���� 
	/*Complex(double real_,double imag_) {
		real = real_;
		imag = imag_;
	}*/
	//�ʱ�ȭ���: ���� �����ڸ� ������ ǥ���� ���
	Complex(double real_,double imag_): real(real_), imag(imag_){}
	



	//�Ǽ� getter setter
	double getReal() {
		return real;
	}
	void setReal(double real) {
		real = real;
	}
	//��� getter setter 
	double getImag() {
		return imag;
	}
	void setImag(double imag) {
		imag = imag;
	}
private:
	double real;
	double imag;
};

int main_construct1() {

	// �Լ��� �ƴ����� �Լ�ó�� �����ε��Ѵ��� 
	// ������ ������ ���� ��������� �� ����.
	Complex c1; // Complex Ŭ������ ��ü c1 ����, ù��° ������ �����
	Complex c2 = Complex(2,3); // �ι�° ������ �����
	Complex c3(2, 3); // �ι�°���� ������ ��ü�������
	Complex c4 = { 2,3 }; 
	Complex c5 = Complex{ 2,3 };
	Complex c6{ 2,3 };


	cout << "c1 = " << c1.getReal() << ", " << c1.getImag() << endl;
	cout << "c2 = " << c2.getReal() << ", " << c2.getImag() << endl;
	cout << "c3 = " << c3.getReal() << ", " << c3.getImag() << endl;
	cout << "c4 = " << c4.getReal() << ", " << c4.getImag() << endl;
	cout << "c5 = " << c5.getReal() << ", " << c5.getImag() << endl;
	cout << "c6 = " << c6.getReal() << ", " << c6.getImag() << endl;

	return 0;
}