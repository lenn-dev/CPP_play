// 함수 오버로딩으로 세개의 이름이 같은 함수 만들기
// 64개의 슬롯이 있는 배열을 만들어 
// 64개의 아이템을 수집한 갯수만큼 카운트해서 저장
// 점수를 먹었을 때도 저장

// 첫번째 함수는 인자가 아이템
// 두번째 함수는 인자가 아이템과 갯수(여러개일때)
// 세번째 함수는 인자가 아이템, 갯수, 점수


#include <iostream>

using namespace std;

int inventory[64] = { 0 };
int score = 0;
//void getItem(int itemId) {
//	inventory[itemId]++;
//}
//void getItem(int itemId, int cnt) {
//	inventory[itemId]=+cnt;
//}
// [ 디폴트 매개변수 ]를 설정해주면 인자가 들어오지 않을때를 설정해줌으로써
// 앞쪽 함수가 다 필요 없음.
// 디폴트값을 줄 때 오른쪽 부터 주어야 하는걸로 약속(이유 이해 안됨).
void getItem(int itemId, int cnt = 1, int sc = 0) {
	inventory[itemId] = +cnt;
	score = +sc;
}

int main_getItem() {

	getItem(2);
	getItem(5, 22);
	getItem(6, 2, 6000);
	getItem(2, 3);


	cout << score << endl;
	//슬롯 16개까지만 출력해서 확인해봄
	for (int i = 0; i < 16; i++) {
		cout << inventory[i] << ' ';
	}
	cout << endl;

	return 0;
}