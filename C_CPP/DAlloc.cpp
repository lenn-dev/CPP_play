#include <iostream> // 선행처리기
using namespace std;  // std 의 명칭공간을 사용선언하여 명칭공간 지정을 간소화

int main_DAlloc() { // 메일함수
	int* intPtr; // 인트형 포인터변수 intPtr선언
	intPtr = new int[4];  // 4개 인트값을 저장할 메모리 동적할당
	*intPtr = 10; // intPtr 포인터가 가리키는 메모리에 10을 할당
	*(intPtr + 1) = 20; // intPtr가 가리키는 메모리 주소의 다음 메모리에 20을 할당
	intPtr[2] = 30; // 포인터 intPtr 의 인덱스[2] 인 메모리에 30저장
	intPtr[3] = 40; // 포인터 intPtr 의 인덱스[3] 인 메모리에 40저장
	for (int* p = intPtr, i = 0; i < 4; i++) // intPtr 포인터가 가리키는 주소 기준으로 포인터를 하나씩 옮겨가는 루프
		cout << p[i] << " "; // 현재 위치가 가리키는 곳의 값을 출력
	cout << endl; // 줄바꿈
	delete[] intPtr; // 메모리 동적할당한 intPtr의 메모리 반환
	return 0; // 함수 정상종료
}

