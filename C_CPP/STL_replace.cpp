#include <iostream>  // ����� ��Ʈ���� ����ϱ� ���� ��� ����
#include <vector>    // ���� �����̳ʸ� ����ϱ� ���� ��� ����
#include <algorithm> // �˰����� ����ϱ� ���� ��� ���� (���⼭�� std::replace)

int main() { // ���α׷��� ������
    std::vector<int> vec = { 1, 2, 3, 2, 4, 2, 5 }; // ������ ���� vec�� �����ϰ�, �ʱ�ȭ ����Ʈ�� ���� �ʱ�ȭ
    int oldValue = 2; // ���Ϳ��� ��ü�� �� oldValue�� 2�� ����
    int newValue = 99; // ��ü�� �� newValue�� 99�� ����

    // ���� vec���� oldValue(2)�� ã�� newValue(99)�� ��ü�ϴ� �۾�
    std::replace(vec.begin(), vec.end(), oldValue, newValue);

    // "��ü �� ����: "��� ���ڿ��� ���
    std::cout << "��ü �� ����: ";

    // ������ �� ��Ҹ� ����ϱ� ���� �ݺ����� ���
    for (const int& val : vec) { // ������ �� ��Ҹ� ���������� �����ϸ� �ݺ�
        std::cout << val << " "; // �� ��Ҹ� ��� ��, ������ �߰�
    }

    std::cout << std::endl; // ��� �� �� �ٲ�

    return 0; // ���α׷��� ���������� ������� �˸�
}


