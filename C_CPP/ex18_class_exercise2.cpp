/*
* �⺻ �����ڷ� 800x600 ������ȭ�� �⺻�����ϰ�, 
ResizeWindow()�� ���� �Է¹��� �Ű������� �ش��ϴ� ������ ȭ������� �������ϴ� ���α׷� 


* 1. �Ʒ��� GameWindow Ŭ������ �ڵ忡�� â �ʺ�� ���̸� �Ű������� �޴� ResizeWindow �Լ��� �߰��Ͽ�
* ���� ���ǰ� ���� width�� height�� ���� �ٲٽÿ�. 
* - ���� �Ű������� ���� ��ġ�ϵ��� â ũ�⸦ ������ ��
* - �ʺ� 800 ���� �۰ų� ���̰� 680���� ���� ���� ���� 800, 600���� ������ ��.
* 
* 2. GameWindow::GameWindow(int w, int h)�����ڵ� ���������� 2���� ������ �����ϵ��� ������ ��
* ResizeWindow�� �Ȱ����� �����ϴ� �� ���� �Լ���ü�� ȣ���ϴ� ���� ����. ���߿� ������ ����
* 
* 3. �ۼ��� �ڵ忡�� ���ȭ�� ������ �κ��� ��� ���ȭ �� ��. 
* ��� �Ű������� ������ ������ const
* ������ ���� get �Լ��� const ���̱�, ResizeWindow()�Լ��� ���� ����ǹǷ� const ���ϼ� ����.
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
