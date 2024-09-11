

//struct : c�� cpp �� struct �� ū ����
//class : cpp ���� �߰���


//Ŭ���� = �ڷ����� + �ڷ� ó�� = ���� + �Լ�
//Ŭ����(Ÿ��): Ư���� �뵵�� �����ϱ� ���� ������ �Լ��� ��Ƶ� Ʋ
//��ü(������Ʈ): �� Ʋ�� �̿��Ͽ� �� ��ü(����, �޸� ���� ����)

//int a, b, c;  // int�� �ؾ Ʋ, a,b,c�� �ؾ
//Ŭ������ �ؾ Ʋ, ��ü�� �ؾ

#include <iostream>

using namespace std;


// ĸ��ȭ : OOP �Ӽ� �� �ϳ�, ���μӼ����� ��ȣ�ϸ鼭 private, �ܺ� ����ڿ��� �Ӽ��鿡 ������ �� �ִ� �������̽��� ����� ��
// struct �� Ŭ������ ���̴�? 
// struct �� private ���� ���� �����ڸ� ���� �����־�� �ϴµ�,
// struct�� class �� �ٲٸ� ��� �Ӽ��� ���� private �� default �� public �� ���� ��������� ��. 
struct TV {

private: // �ܺ����� ���ϰ� �ϴ� ��������������
	bool powerOn;
	int channel;
	int volume;

public: // �ܺ����� �����ϰ� �ϴ� ��������������
	
	void on() {
		powerOn = true;
		cout << "Power is on." << endl;
	}
	void off() {
		powerOn = false;
		cout << "Power is off." << endl;
	}
	void setChannel(int cnl) {
		if (cnl >= 1 && cnl <= 999) {
			channel = cnl;
			cout << "Channel is on " << cnl << ". " << endl;
		}
	}
	void setVolume(int vol) {
		if (vol >= 0 && vol <= 100) {
			volume = vol;
			cout << "Voluem is now " << vol << ". " << endl;
		}
	}


};

int main_struct() {
	TV lg;
	lg.on();
	lg.setChannel(10);
	lg.setVolume(50);
	lg.setChannel(-73); // ����ȵ�
	//lg.volume = 400; 
	// setVolume�� ���� ���������� ������ ������ volume ��밡��
	//��� ������ �ϳ�? => ���� ���� ������ (CPP): private, protected, public
	// struct �ȿ����� ���� �����ϸ鼭 �ۿ����� ���� ���ϰ�

	
	return 0;
}