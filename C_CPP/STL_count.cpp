#include <iostream>  // ����� ��Ʈ���� ����ϱ� ���� ��� ����
#include <vector>    // ���� �����̳ʸ� ����ϱ� ���� ��� ����
#include <algorithm> // �˰����� ����ϱ� ���� ��� ���� (���⼭�� std::count)

int main() { // ���α׷��� ������
    std::vector<int> vec = { 1, 2, 3, 1, 4, 1, 5 }; // ������ ���� vec�� �����ϰ�, �ʱ�ȭ ����Ʈ�� ���� �ʱ�ȭ
    int value = 1; // ���Ϳ��� ������ ������ �ϴ� �� value�� 1�� ����

    // ���� ������ 'value'�� ��ġ�ϴ� ����� ������ ���� ���� std::count�� ���
    int countValue = std::count(vec.begin(), vec.end(), value);
    // std::count�� vec.begin()���� vec.end()���� �������� 'value'�� ��ġ�ϴ� ����� ������ ��ȯ

    // 'value'�� ������ ���
    std::cout << "�� " << value << "�� ����: " << countValue << std::endl;

    return 0; // ���α׷��� ���������� ������� �˸�
}

