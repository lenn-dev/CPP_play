// static ���� ��� �޼���
// ����ü�� ����� ��� ��������� ���� : 
// �� �ؾ Ʋ���� �ؾ�� �������� ��ü�� ���ԵǴ� ���
// ��������� �ؾ Ʋ�� �ش�Ǵ� ����� Ŭ���� �ϳ��� ��������� �ϳ��� �ο���.

# include <iostream>

using namespace std;

// ���� �����ϴ� ���α׷� �ۼ�
// float���� 0-1 ������ ���� �ο��� RGB �����غ���


class Color {
public:
	// Color ��ü ������ ������ ��ȣ�� �ο��ϰ� ����
	// ���� ������� ��ü�� ���̵� ���� 1�� ������ �� id�� 1�� ���� : ��������
	// �ʱ�ȭ ��Ͽ� �־���. ++ �̷� ǥ�� ���� ��
	Color() : r(0), g(0), b(0), id(idCounter++) { } // rgb ��� 0�� �� ��
	Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) { }

	// getter setter ������ �ϴµ� ��������� ���� �����ϴϱ� 
	// �������� ����� �����ϴ� �� ���ٴ� �ƿ� ���ο� ��ü ���� �����ϴ°� �����Ƿ�
	// setter�� ������ �ʰ� getter �� ���� ����

	float getR() { return r; }
	float getG() { return g; }
	float getB() { return b; }

	int GetId() { return id; }

	// static �޼���� �����Լ��� ���� �Ͱ�, class �� ������ ������ �����鼭��
	// Ŭ���� �ȿ� private ������ �����ϰ� ������ Ŭ������ �ְ� �����.
	// �׷����� ���ؼ� ��ü �������� �� ��ü�� ���ԵǴ� ���� �ƴ϶�
	// Ŭ������ ���Ե� �ϳ����� �޼��尡 �Ǵ� ����
	// 
	// 
	// MixColor �Լ��� Color �ȿ� �־��� ��, main�Լ����� ȣ���ϱ� �ָ�����.
	// purple ���� ���鶧 red.MixColor, blue.MixColor���� ǥ���� �����
	// �׳��� purple.MixColor �� ���� ���������� ������ ����� ǥ��
	// �� �� Color Ŭ���� ��������� �� MixColors �Լ� �տ� static �� ���ָ� �����������
	// ȣ������ ���ӽ����̽�ó�� :: ���, Color Ŭ���� �ȿ� MixColors �Լ� �̷���
	/*static Color MixColors(Color a, Color b) {
		Color result = Color((a.getR() + b.getR()) / 2, (a.getG() + b.getG()) / 2, (a.getB() + b.getB()) / 2);
		return result;
	}*/
	
	
	// ���⼭ MixColors�� ���� Class �ȿ� �־ ������ �������� �����ڸ�
	// Ŭ���� �ȿ� ���Ա� ������ private ��� ������ ���������� ������
	// �ڵ带 �Ʒ��� ���� �ٲ��� �� ����
	// �� setter�Լ��� ȣ������ �ʰ� r,g,b �� �����ؼ� ���
	static Color MixColors(Color a, Color b) {
		Color result = Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
		return result;
	}


	// Color ��ü ������ ������ ��ȣ�� �ο��ϰ� ����
	// static ���� Ŭ���� �ȿ��� �ʱⰪ�� �� �� ����, 
	// Ŭ���� �ٱ����� �ʱⰪ �־�� ��
	//static int idCounter = 1;
	static int idCounter;

private:
	float r;
	float g;
	float b;

	// ��������� ��ü�� ��ȣ�� �ο�
	int id;

};

// �������� ���·� ����� ���� Ŭ���� �ȿ� �������·� ���� ���� �Ŀ�
// Ŭ���� �ۿ��� ���ӽ����̽� ������ �ؼ� ����� ���Ǹ� �и��� ������� �ʱⰪ ��
int Color::idCounter = 1;

// �ΰ��� ���� �޾� ���� �Լ�
// ��ȯ ���´� Color (class �� �����Ѱ��� �ڷ����·� �� �� �ֳ�?)
// a �� ���� rgb ��, b �� ���� rgb �� �̶�� �ϴ� ���� ���� class�� �ڷ��������� ���� �� ����.
// �� rgb���� ������ �ΰ��� �÷��� ���´ٰ� �ϸ� 
// r,g,b ���� ���� ���� ��� �� ���� ��ȯ�ϸ� ���� ������ ��.
//Color MixColors(Color a, Color b) {
	// Ŭ���� Color ��ü result����� ������ �ٷ� ȣ�� 
	//Color result = Color((a.getR() + b.getR())/ 2, (a.getG() + b.getG())/ 2, (a.getB() + b.getB())/ 2);
	//���� ǥ��
	//Color result((a.getR() + b.getR()) / 2, (a.getG() + b.getG()) / 2, (a.getB() + b.getB()) / 2);
	//return result;
//}


int main() {
	Color blue(0, 0, 1);
	Color red(1, 0, 0);

	// static ��� �ҷ����� ��� 
	Color purple = Color:: MixColors(blue, red);
	
	// Color purple = blue.MixColors(blue, red);
	// �̷������� �ص� �����ϴµ� static �޼���� � ��ü�� ���Ե� ���·ε� ����
	// �̷��� ������ ����������ٴ� ǥ���� �� �� ����


	cout << " r = " << purple.getR() << " g = " << purple.getG() << " b = " << purple.getB() << endl;

	
	cout << "blue.GetId() = " << blue.GetId() << endl;
	cout << "red.GetId() = " << red.GetId() << endl;
	cout << "purple.GetId() = " << purple.GetId() << endl;
}