//// ���� ����: �ּҰ��� ����
//// ���� ����: �ּҰ� ����Ű�� ������ ����
//
//#include <iostream>
//
//using namespace std;
//
//class String {
//public:
//	String() {
//		// ���� �Ǿ� ���� ��� �����Ҵ����� �ʴ°� ����
//		// ������ ������ 0���ٴ� NULL �� ���� ��
//		// ������ �ƹ��͵� ����Ű�� ���� �ʴٴ� ��
//		strData = NULL; 
//		len = 0;
//	}
//	String(const char* str) {
//		// ���̸� ��ȯ�ϴ� �Լ� ����ؼ� ������ char�� ���̸� len�� ��������
//		len = strlen(str);
//
//		// �������� �����Ҵ��� ���־�� ��
//		// ����� char�� ���� len�� �̿��� �迭 �����Ҵ�����
//		// ��� ���ڿ� �� ���� NULL����(\0) �ֱ� ������ 1 ������
//		strData = new char[len + 1];
//
//		//strData = str; // ���� ���� �̷��� �ϸ� �ȵ�
//		// iostream �ȿ� ����ִ� �Լ� strcpy() �� ��
//		// char* strcpy(char* _Destination, const char* _Source)
//		// �Ű����� _Destination ������� ���ڿ�,   _Source ���� ���ڿ�
//		// ���� ����
//		strcpy(strData, str);
//	}
//	~String() {
//		delete[] strData;
//	}
//	// ��ȯ���� char ��������
//	char* GetStrData() {
//		return strData;
//	}
//	int GetLen() {
//		return len;
//	}
//private:
//	char* strData;
//	int len;
//};
//
//int main_copy() {
//	String s;
//	return 0;
//}