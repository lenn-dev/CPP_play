// 다음 코드를 읽고 출력을 예상해보기
// 코드를 따라쳐도 출력이 같지 않음. 
// 강의에서는 매개변수 obj와 ptr 주소값이 같은 것을 이용하여 돌아가는 프로그램인데
// 강의 출력결과가 내 것과 다르게 나옴. 
// obj, ptr값은 for문 계속 돌아도 똑같이 000000D8DAEFF6B8로 나오고,
// num은 출력했을때 다 - 858993460
// cnt = 0 으로 나옴.....
// cnt++ 이 안되는 느낌. 
// 포인터 강의를 더 봐야 할것 같고, 64강도 다시 보기
// 앞으로 배울 동적할당에서 중요한 것이 포인터 개념임...

#include <iostream>

using namespace std;

class MyClass {
public:
	// MyClass 객체가 생성될때마다 num cnt넣고 1씩 증가시켜줌
	MyClass(): num(cnt++),ch('\0'){ }
	
	// 즉 ptr에는 &obj[0] = obj 주소값이 저장되는 것
	// 따라서 ptr = obj
	// for 문에서 계속 이 값만 매개변수로 넘겨주고 있음
	void Check(MyClass *ptr) {
		// ptr + num 은 &ptr[num]과 같음
		// 즉 여기선 &ptr[num] = &obj[num]
		//cout << " ptr address :" << ptr << endl;
		//cout << " num :" << num << endl; 

		// 포인터 + 정수의 연산에서는 형변환이 일어나지 않음
		// 단지 포인터 타입에 정수타입을 더한 결과값이 포인터 타입임? 
		// 25 강 참조
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
	// Myclass 의 객체 obj 배열생성
	// 이부분 동작이 안되는거 같지? 
	MyClass obj[5]; 
	//생성자가 호출됨 *5

	cout << "Test #1 : " << endl;
	//obj의 인덱스 0-4까지 돌면서 Check() 함수 돌리는데 매개변수가 obj
	for(int i = 0; i < 5; i++) {
		//매개변수의 obj 는 &obj[0] 과 똑같은 값, 
		// 즉 obj 0번째의 주소값을 매개변수로 넘겼다는 뜻
		
		obj[i].Check(obj);
		cout << "obj address" << obj << endl;
	}
	cout << "Test #2 : " << endl;
	//두번째 for문의 레퍼런스변수 i가 첫번째 for문의 obj[i]를 참조(가리키고)하고 있음.
	// 범위기반 for문 
	for(MyClass &i : obj) {
		i.Check(obj);
	}
	cout << "cnt = " << MyClass::cnt << endl;

	return 0;
}