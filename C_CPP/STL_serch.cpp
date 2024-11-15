#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 }; // ���� ����
    int value = 3; // ã���� �ϴ� ��

    // std::search�� ���� �������� ã�� �Լ��̹Ƿ�, 'value'�� �ϳ��� ��ҷ� ������ ���ͷ� ���μ� ����
    auto it = std::search(vec.begin(), vec.end(), std::vector<int>{value}.begin(), std::vector<int>{value}.end());

    // 'value' ���� ���Ϳ��� �����ϴ��� Ȯ��
    if (it != vec.end()) { // ���Ϳ��� 'value' ���� ã�� ���
        std::cout << "�� " << value << "��(��) ã�ҽ��ϴ�." << std::endl; // ã�� ��� �޽��� ���
    }
    else { // ���Ϳ��� 'value' ���� ã�� ���� ���
        std::cout << "���� ã�� ���߽��ϴ�." << std::endl; // ã�� ���� ��� �޽��� ���
    }

    return 0; // ���α׷� ����
}

// search �� find �� �ٸ��� ���� �������� ã�� �Լ���
// ���ϰ��� ã���� �� ���� find�� �� ��������


