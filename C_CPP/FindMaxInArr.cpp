#include <iostream> //선행처리기,표준 입출력 라이브러리 포함
using namespace std;  // std 의 명칭공간을 사용선언하여 명칭공간 지정을 간소화

int main_FindMaxInArr() {// 메인함수
	int data[10] = { 10,23,5,9,22,48,12,10,55,31 }; // 정수형 배열이고, 크기가 10 인 data 생성하고, 10개의 값을 할당
	int max = data[0]; // data 배열 첫번째 인덱스[0] 값을 변수 max의 초기값으로 설정

	cout << " 데이터 : " << data[0]; // 첫번째 데이터 출력
	for (int i=1; i< 10; i++) { // max 값으로 설정된 data[0]값과, 나머지 배열의 값을 반복문으로 돌며 하나하나 값 비교
		cout << " " << data[i]; // for loop 현재 위치 i의 데이터값 출력
		if (max < data[i]) // max값보다 현재 i번째 데이터값이 큰지 비교하는 조건문
			max = data[i]; // 참이라면 max값에 현재 데이터값 할당
	}
	cout << endl << endl; // 줄바꿈
	cout << " 배열의 최대값 : " << max << endl; //모든 배열값 비교 후 최종 max값 출력
	return 0; // 함수 정상종료
}

