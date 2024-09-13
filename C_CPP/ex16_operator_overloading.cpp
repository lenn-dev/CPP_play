// 62��.������ �����ε�
// ex15 �� �ڵ带 �״�� �����ͼ� ������

#include <iostream>

using namespace std;


class Vector2 {
public:
	Vector2();
	Vector2(float x, float y);

	float GetX() const;
	float GetY() const;

	// Add �Լ� �̸��� operator+ �� �ٲٱ�
	// ����� operator�� �Ϲ����� �Լ��� �� �� ����.
	// ����,���� �и����ְ�, �Լ�,�Ű����� const �����ϱ� 
	// (�ڱ��ڽ��� ���� �Ű������� �����ϴ� ���̶� �ڱ��ڽ��� ������ ����)
	// **Ŭ���� ����Լ��� const ���̴� ������ 
	// ����Լ��� Ŭ���� ���� ��������� ���� �ٲ��� ���ϵ��� �ϱ� ���ؼ� �̹Ƿ�
	// Ŭ���� �ٱ��� ����,���ǵ� �Լ��� const ���� �� ����.
	// ���������(�������� �̸� �ƴ�), ����޼��� ������ �ϱ� ����. 
	// ��������ڴ� �ڽ��� ���� �캯���� �ϴ� ���ο� �Ű��������� ����
	Vector2 operator+(const Vector2 rhs) const;
	Vector2 operator-(const Vector2 rhs) const;
	Vector2 operator*(const float rhs) const;
	Vector2 operator/(const float rhs) const;
	float operator*(const Vector2 rhs) const;

private:
	float x;
	float y;
};

// ����������(�������� �̸� �ƴ�): Ŭ���� �ٱ����� ���̴� ���� ������.
// ���������ڴ� �ڱ��ڽ��� ������ ����
// �Ű�����(�º�,�캯) �ΰ��� ���ÿ� �޾� �����ϰ� ��.
// �Ǽ�, �������� ���͸� ���ϴ� �Լ�
// Ŭ������ ���ԾȵǴ� �����Լ��̱� ������ �޼��� GetX(), GetY()������� ��
Vector2 operator*(const float a, const Vector2 b) {
	return Vector2(a * b.GetX(), a * b.GetY());
}

int main_operator() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);

	// ������ - �� ����ξ �����ڸ� ȣ���ϰ� ����.������ �Լ����ҵ� ��
	// ��, �����ڵ� �Ϲݸ޼���� ����ϰ� �� �� �ִµ� 
	// �ٸ� �����ڷ� �����ϰ� ǥ���ϰ� ȣ���� �� �ִٴ� ���� �ٸ�.
	Vector2 c1 = a - b;
	// ���Ϳ� �Ǽ��� ���ϴ� ����, �Ǽ� * ���ͷ� ���� �ٲٸ� ����
	// double, float �� ��ü�� �ƴϱ� ������ ���⿡ operator �Լ��� ������ �� ����
	Vector2 c2 = a * 1.6;
	// operator �� ��������� ���ؼ� ��ü������ ������ ��������
	// ���ǿ����� + �� ���콺 ��� Vector2 Vector2::operator+(Vector2 rhs) ��� �����µ� ���� �ȳ���.
	
	// ��ü c3 �� �Ǽ� * ��ü (�º�,�캯)�� �Ű������� �ޱ� ������ 
	// Ŭ���� �ٱ��� ������ Vector2 operator*(const float a, const Vector2 b) �� ȣ���
	// �ٱ��� ������ ������ ��ü�� �ƴ� �Ǽ��� 
	// ������ �����ε�(�ڱ��ڽ� ���� ���� �Ű����� �����ϴ� ��)�� �� �� ���� ������ 
	// (������ operator�� ������ �Լ�ó�� ����) Ŭ���� �ۿ� ����,���� 
	// ???
	// c ���� �����Ǵ� �⺻�� �ڷ��� (double, float..��)�� ������ �����ε� �Ұ���
	// ��,Vector2 c3 = 1.6 * a; �� 1.6.operator*(a) �� �����ؾ� �ϴµ� 
	// .operator* �� period�� ��� �޼��带 ȣ���ϴ� ����� � ��ü��� ���ؾ� �ϴ� ���ε�,
	// 1.6�� ��ü�� �ƴ϶� �Ұ����� ����
	// ���� �����ϴٰ� �ϸ� Vector2 �� Vector2 operator* (const Vector2 rhs) const; �� ȣ���ؼ� �������ٵ�
	// 1.6�� ��ü�� �ƴϱ� ������ �Ұ���.
	Vector2 c3 = 1.6 * a;
	// ����*������ ����� �Ǽ�
	float c4 = a * b;

	cout << a.GetX() << ", " << a.GetY() << endl;
	cout << b.GetX() << ", " << b.GetY() << endl;
	cout << c1.GetX() << ", " << c1.GetY() << endl;
	cout << c2.GetX() << ", " << c2.GetY() << endl;
	cout << c3.GetX() << ", " << c3.GetY() << endl;
	cout << c4 << endl;

	return 0;
}


Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}


float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }

//Vector2 �ڷ����� ��ȯ�ϴ� Vector2 Ŭ������ ����� operator+�Լ�, ����� �Ű����� Vector2 rhs�� ����
Vector2 Vector2::operator+(const Vector2 rhs) const {
	// x, y �� �ڱ� �ڽ��� ����
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2 rhs) const {
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const {
	return Vector2(x * rhs, y * rhs);
}

Vector2 Vector2::operator/(const float rhs) const {
	return Vector2(x / rhs, y / rhs);
}

float Vector2::operator*(const Vector2 rhs) const {
	return x * rhs.x, y* rhs.y;
}