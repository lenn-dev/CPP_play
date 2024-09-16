// KNOU강의 6강  복사생성자
// 얕은 복사의 문제점
// VecF 클래스 만들기 
// VecF객체는 저장할 수 있는 float값의 수를 인수로 지정해 생성되며,
// 저장할 값의 배열이 제공될 경우 그 값으로 초기화 한다. (동적할당필요)
// 인수로 전달된 VecF 객체와 덧셈한 결과를 반환할 수 있으며, 
// 객체에 저장된 벡터를 출력할 수 있다.

#include <iostream> // 입출력
#include <cstring> //c 언어에서 string.h를 가져온것 (그런것은 앞에 c붙임) 메모리 복사 용도

using namespace std; // std명칭공간을 편리하게 사용하기 위함

class VecF {
	int n; // 벡터의 dimension
	float* arr; //벡터 저장공간 포인터 // n개의 데이터를 저장할 수 있는 포인터 arr
public:
	// 생성자
	// 벡터가 가질 차원의 갯수 d, float형 벡터 a 에 디폴트 매개변수 nullptr (매개변수 전달안되면 nullptr)
	// 디폴트 생성자는 존재하지 않음.
	// n 을 d로 초기화
	VecF(int d, const float* a = nullptr) : n{ d } {
		
		arr = new float[d];
		// a 가 널이 아니면 참 => 복사
		// a 가 널이면 거짓
		//arr: 목적지, a: source, sizeof(float)* n: 메모리크기
		if (a) memcpy(arr, a, sizeof(float)* n);
	}
	// 명시적 복사 생성자=================================================
	// 데이터를 할당받을 메모리를 별도로 할당받기
	// 깊은 복사 : 서로 별개된 메모리를 할당받아 그대로 복사함
	VecF(const VecF& fv) : n{ fv.n } {
		// 메모리를 별도로 할당받음
		arr = new float[n];
		memcpy(arr, fv.arr, sizeof(float) * n);
	}
	//=================================================
	
	// 소멸자
	// 할당받은 메모리 반납
	~VecF(){
		delete[] arr;
	}

	// add 멤버함수
	// 동일 객체에 대한 참조
	VecF add(const VecF& fv) const {
		VecF tmp(n); //n개의 데이터 저장할 수 있는 tmp객체 // tmp(a, nullptr);과 같음
		for (int i = 0; i < n; i++)
			tmp.arr[i] = arr[i] + fv.arr[i];
		return tmp;
	}

	// 내용 변경 없으니 const
	void print() const {
		// 저장되어 있는 메모리의 값을 출력해줌
		cout << "[";
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << "]";
	}
	
};
int main() {
	float a[3] = { 1,2,3 };
	//3개의 객체 생성, 초기값은 a배열
	VecF v1(3, a); //1,2,3을 저장하는 벡터
	VecF v2(v1); // v1을 복사하여 v2를 만듦
	// 명시적 복사생성자가 없다면 묵시적 복사생성자로 복사하게 되는데,
	// v2가 v1의 값과 포인터를 복사해 똑같은 메모리를 가리키고 공유함.
	// 소멸자가 작동할때 v1이 지워졌는데, v2가 다시 같은 메모리를 지우려고 시도하면,
	// 이미 반납된 메모리를 건드리게 됨으로써 에러가 발생 (얕은 복사의 문제점)
	// 복사 생성자를 명시적으로 만들어 주어 해결가능
	v1.print();
	cout << endl;
	v2.print();
	cout << endl;
	return 0;
}