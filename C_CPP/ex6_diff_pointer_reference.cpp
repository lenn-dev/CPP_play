#include <iostream>

using namespace std;

// 3. 다음과 같은 함수 정의에서 컴파일 오류가 나는 이유는?
	
	// 이유1. 디폴트 변수는 오른쪽부터 줘야함 => 오른쪽으로 옮겨져도 에러
	// 이유2. 옮김으로써 두 함수의 구분이 어려워짐.
	
	// 직사각형 그리는 두가지 방식
	//1. 직사각형 네 변의 좌표를 매개변수로 받는다.
	void drawRectangle(int l, int r, int t, int b) {

	}
	//2. 직사각형 모서리의 좌표 (x,y) 와 너비, 높이를 받는다.
	//void drawRectangle(int w, int h, int x = 0, int y = 0) {

	//}


	int main_rect() {

		drawRectangle(4, 2, 4, 5);

		return 0;
	}