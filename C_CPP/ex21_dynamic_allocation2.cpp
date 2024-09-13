//배열의 할당 : 원하는 길이만큼 동적할당
// arr = &arr[0]
#include <iostream>

using namespace std;

int main_dynamic2() {
	int* arr;
	int len;

	cout << "동적할당할 배열 길이 입력 :";
	cin >> len; 
	
	// int형의 배열을 len길이만큼 만드는데 
	// 이 배열의 0번째 주소값을 반환해서
	// 포인터 arr 에 할당
	// *************************************
	// 이제 arr 를 배열처럼 쓸 수 있음
	//**************************************
	arr = new int[len];

	for (int i = 0; i < len; i++) {
		arr[i] = len - i;
	}
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}
	
	// 여기서 문제는 arr 는 포인터라서 0번째만 삭제하고 나머지는 남아있음
	// delete arr;

	// 배열 없애줄때는 이렇게
	delete[] arr;

	return 0;
}