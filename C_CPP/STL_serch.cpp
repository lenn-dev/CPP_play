#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    int value = 3;

    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        std::cout << "�� " << value << "��(��) ã�ҽ��ϴ�." << std::endl;
    }
    else {
        std::cout << "���� ã�� ���߽��ϴ�." << std::endl;
    }

    return 0;
}

