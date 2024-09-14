//// 얕은 복사: 주소값만 복사
//// 깊은 복사: 주소가 가리키는 값까지 복사
//
//#include <iostream>
//
//using namespace std;
//
//class String {
//public:
//	String() {
//		// 선언만 되어 있을 경우 동적할당하지 않는게 좋음
//		// 포인터 쓸때는 0보다는 NULL 로 많이 씀
//		// 지금은 아무것도 가리키고 있지 않다는 뜻
//		strData = NULL; 
//		len = 0;
//	}
//	String(const char* str) {
//		// 길이를 반환하는 함수 사용해서 들어오는 char의 길이를 len에 저장해줌
//		len = strlen(str);
//
//		// 복사전에 동적할당을 해주어야 함
//		// 저장된 char의 길이 len을 이용해 배열 동적할당해줌
//		// 모든 문자열 맨 끝에 NULL문자(\0) 있기 때문에 1 더해줌
//		strData = new char[len + 1];
//
//		//strData = str; // 얕은 복사 이렇게 하면 안됨
//		// iostream 안에 들어있는 함수 strcpy() 쓸 것
//		// char* strcpy(char* _Destination, const char* _Source)
//		// 매개변수 _Destination 덮어씌어질 문자열,   _Source 원본 문자열
//		// 깊은 복사
//		strcpy(strData, str);
//	}
//	~String() {
//		delete[] strData;
//	}
//	// 반환형이 char 포인터임
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