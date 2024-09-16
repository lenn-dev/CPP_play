// warning C4267: '=': 'size_t'���� 'int'(��)�� ��ȯ�ϸ鼭 �����Ͱ� �սǵ� �� �ֽ��ϴ�.
// �����޼����� ��� ������ len���� ����� ��ȯ���� �ʾƼ� �������� �ʴµ� �ذ� ����...
// ���� ����: �ּҰ��� ����
// ���� ����: �ּҰ� ����Ű�� ������ ����
// ���� ������


#include <iostream>

using namespace std;

class String {
public:
	String() {
		cout << "String() ������ ȣ��" << endl;
		// ���� �Ǿ� ���� ��� �����Ҵ����� �ʴ°� ����
		// ������ ������ 0���ٴ� NULL �� ���� ��
		// ������ �ƹ��͵� ����Ű�� ���� �ʴٴ� ��
		strData = NULL; 
		len = 0;
	}
	String(const char* str) {
		cout << "String(const char*) ������ ȣ��" << endl;
		// ���̸� ��ȯ�ϴ� �Լ� ����ؼ� ������ char�� ���̸� len�� ��������
		//�����߻� '=':'size_t���� 'int'�� ��ȯ�ϸ鼭 �����Ͱ� �սǵ� �� �ֽ��ϴ�.
		len = strlen(str);
		cout << len << endl;

		// �������� �����Ҵ��� ���־�� ��
		// ����� char�� ���� len�� �̿��� �迭 �����Ҵ�����
		// ��� ���ڿ� �� ���� NULL����(\0) �ֱ� ������ 1 ������
		strData = new char[len + 1];
		cout << strData << endl;

		// ���⼭ strData ����Ϸ��� �ϸ� �����Ϸ��� char���� ���ڿ����� ��
		// strData�� ���ڿ��� �νĵǴ� ���� �����ؾ� ��.
		// char�����ʹ� �迭ó�� �ν�������, strData���� NULL�� ��쿣 ���� �� �� ����
		// �տ� void*�� �־������μ� (����ȯ�� �������ν�) �ذᰡ��
		// char �����͸� ����Ű�� strData�� void �����Ϳ� �־� ����ϴ� ���
		// void* ptr = strData;	
		// �� void �����ʹ� �ּҰ��� ������ �ְ� �ڷ����� ���� ������ ���  ���� �ٲ� �� ����
		//cout << "strData �Ҵ� :" << strData << endl;
		cout << "strData �Ҵ� :" << (void*)strData << endl;
		//strData = str; // ���� ���� �̷��� �ϸ� �ȵ�
		// iostream �ȿ� ����ִ� �Լ� strcpy() �� ��
		// char* strcpy(char* _Destination, const char* _Source)
		// �Ű����� _Destination ������� ���ڿ�,   _Source ���� ���ڿ�
		
		//strcpy(strData, str); // ���� ����
		strcpy_s(strData, len, str);
	}
	// ���� ������ ����뵵
	// �����Լ� �ȿ� String s2(s1); ��������ڸ� ����
	// String Ÿ�� ��ü�� �Ű������� �����ϰ� ����.
	// &���۷��� �������� �޾ƾ� ��. �ֳ��ϸ� String�� ���ǿ� String�� ���ԵǱ� ����
	// ���� ������ ���� �ٸ� �����ڳ� ��� �޼��忡���� ������.
	String(String& rhs) {
		cout << "String(String &rhs) ������ ȣ��" << endl;
		strData = new char[rhs.len + 1];
		cout << "strData �Ҵ� :" << (void*)strData << endl;
		//strcpy(strData, rhs.strData);
		strcpy_s(strData, len, rhs.strData);
		//���������� �ڽ��� ���� ��������� �Ű������� ���� ��ü�� ��������� �ٲ����
		//�� ���縦 �Ѵٴ� ��
		strData = rhs.strData; // ���� ���� �Ͼ. 
		// �� s1�� ����ִ� strData�� �������̰� ������� 100�̶��, s2 �� strData���� 100�� ���簡 ��.
		len = rhs.len; // ���� ���� // len �ڷ����� int���̶� ���� �����.
	}
	~String() {
		cout << "~String() �Ҹ��� ȣ��" << endl;
		delete[] strData;
		cout << "strData ������ : " << (void*)strData << endl;
		//������ �������� ������ ���� ���� NULL�� ������ ���ִ°� ������.
		strData = NULL;
 	}
	// ��ȯ���� char ��������
	char* GetStrData() const{
		return strData;
	}
	int GetLen() const{
		return len;
	}
private:
	char* strData;
	int len;
	
};

int main_copy() {
	String s1("hello");
	String s2(s1); //��������� //String s2 = s1; �� ����

	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;

 
  //int *a = new int(5);
  //int *b = new int(3);
 
  //a = b; // ���� ����(������ ����)
  //*a = *b; // ���� ���� (���� ����)
 
  //delete a;
  //delete b;

	return 0;
 
 
}