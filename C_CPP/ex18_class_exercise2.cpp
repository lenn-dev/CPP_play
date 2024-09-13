/*
* 기본 생성자로 800x600 윈도우화면 기본설정하고, 
ResizeWindow()를 통해 입력받은 매개변수에 해당하는 값으로 화면사이즈 재조정하는 프로그램 


* 1. 아래의 GameWindow 클래스의 코드에서 창 너비와 높이를 매개변수로 받는 ResizeWindow 함수를 추가하여
* 다음 조건과 같이 width와 height의 값을 바꾸시오. 
* - 들어온 매개변수의 값과 일치하도록 창 크기를 설정할 것
* - 너비가 800 보다 작거나 높이가 680보다 작을 때는 각각 800, 600으로 설정할 것.
* 
* 2. GameWindow::GameWindow(int w, int h)생성자도 마찬가지로 2번의 조건을 만족하도록 수정할 것
* ResizeWindow와 똑같은데 복붙하는 것 보다 함수자체를 호출하는 편이 나음. 나중에 수정도 편함
* 
* 3. 작성한 코드에서 상수화가 가능한 부분을 모두 상수화 할 것. 
* 모든 매개변수는 변하지 않으니 const
* 생성자 빼고 get 함수도 const 붙이기, ResizeWindow()함수는 값이 변경되므로 const 붙일수 없음.
*/

#include <iostream>

using namespace std;

class GameWindow {
public:
	GameWindow();
	GameWindow(const int, const int);

	int GetWidth() const;
	int GetHeight() const;

	void ResizeWindow(const int, const int);

private:
	int width;
	int height;
};

GameWindow::GameWindow() : width(800), height(600) {}
GameWindow::GameWindow(const int w,const int h) {
	ResizeWindow(w,h);
}

int GameWindow::GetWidth() const { return width; }
int GameWindow::GetHeight() const { return height;}

void GameWindow::ResizeWindow(const int w, const int h) {
	if (w < 800) width = 800;
	else width = w;
	
	if (h < 600) height = 600;
	else height = h;
}

int main_windowSize() {

	GameWindow mainWindow(500,768);
	//mainWindow.ResizeWindow(1366, 768);
	cout << mainWindow.GetWidth() << "x" << mainWindow.GetHeight() << endl;

	return 0;
}
