// warning C4267: '=': 'size_t'에서 'int'(으)로 변환하면서 데이터가 손실될 수 있습니다.
// 에러메세지가 계속 나오고 len값이 제대로 변환되지 않아서 동작하지 않는데 해결 못함...
// 얕은 복사: 주소값만 복사
// 깊은 복사: 주소가 가리키는 값까지 복사
// 복사 생성자


#include <iostream>

using namespace std;

class String {
public:
	String() {
		cout << "String() 생성자 호출" << endl;
		// 선언만 되어 있을 경우 동적할당하지 않는게 좋음
		// 포인터 쓸때는 0보다는 NULL 로 많이 씀
		// 지금은 아무것도 가리키고 있지 않다는 뜻
		strData = NULL; 
		len = 0;
	}
	String(const char* str) {
		cout << "String(const char*) 생성자 호출" << endl;
		// 길이를 반환하는 함수 사용해서 들어오는 char의 길이를 len에 저장해줌
		//에러발생 '=':'size_t에서 'int'로 변환하면서 데이터가 손실될 수 있습니다.
		len = strlen(str);
		cout << len << endl;

		// 복사전에 동적할당을 해주어야 함
		// 저장된 char의 길이 len을 이용해 배열 동적할당해줌
		// 모든 문자열 맨 끝에 NULL문자(\0) 있기 때문에 1 더해줌
		strData = new char[len + 1];
		cout << strData << endl;

		// 여기서 strData 출력하려고 하면 컴파일러가 char인지 문자열인지 모름
		// strData가 문자열로 인식되는 것을 방지해야 함.
		// char포인터는 배열처럼 인식하지만, strData값이 NULL인 경우엔 에러 날 수 있음
		// 앞에 void*를 넣어줌으로서 (형변환을 해준으로써) 해결가능
		// char 포인터를 가리키는 strData를 void 포인터에 넣어 사용하는 방법
		// void* ptr = strData;	
		// 이 void 포인터는 주소값만 가지고 있고 자료형에 대한 정보는 없어서  값을 바꿀 수 없음
		//cout << "strData 할당 :" << strData << endl;
		cout << "strData 할당 :" << (void*)strData << endl;
		//strData = str; // 얕은 복사 이렇게 하면 안됨
		// iostream 안에 들어있는 함수 strcpy() 쓸 것
		// char* strcpy(char* _Destination, const char* _Source)
		// 매개변수 _Destination 덮어씌어질 문자열,   _Source 원본 문자열
		
		//strcpy(strData, str); // 깊은 복사
		strcpy_s(strData, len, str);
	}
	// 복사 생성자 설명용도
	// 메인함수 안에 String s2(s1); 복사생성자를 보면
	// String 타입 객체를 매개변수로 전달하고 있음.
	// &레퍼런스 형식으로 받아야 함. 왜냐하면 String의 정의에 String이 포함되기 때문
	// 복사 생성자 외의 다른 생성자나 멤버 메서드에서는 가능함.
	String(String& rhs) {
		cout << "String(String &rhs) 생성자 호출" << endl;
		strData = new char[rhs.len + 1];
		cout << "strData 할당 :" << (void*)strData << endl;
		//strcpy(strData, rhs.strData);
		strcpy_s(strData, len, rhs.strData);
		//내부적으로 자신이 가진 멤버변수를 매개변수로 받은 객체의 멤버변수로 바꿔버림
		//즉 복사를 한다는 것
		strData = rhs.strData; // 얕은 복사 일어남. 
		// 즉 s1에 들어있는 strData는 포인터이고 예를들어 100이라면, s2 의 strData에도 100이 복사가 됨.
		len = rhs.len; // 깊은 복사 // len 자료형이 int형이라 값도 복사됨.
	}
	~String() {
		cout << "~String() 소멸자 호출" << endl;
		delete[] strData;
		cout << "strData 해제됨 : " << (void*)strData << endl;
		//해제된 데이터의 접근을 막기 위해 NULL로 대입을 해주는게 관습임.
		strData = NULL;
 	}
	// 반환형이 char 포인터임
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
	String s2(s1); //복사생성자 //String s2 = s1; 와 같음

	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;

 
  //int *a = new int(5);
  //int *b = new int(3);
 
  //a = b; // 얕은 복사(참조만 복사)
  //*a = *b; // 깊은 복사 (값을 복사)
 
  //delete a;
  //delete b;

	return 0;
 
 
}