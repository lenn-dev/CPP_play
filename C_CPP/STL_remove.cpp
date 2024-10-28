#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 1, 4, 1, 5 };
    int value = 1;

    auto newEnd = std::remove(vec.begin(), vec.end(), value);
    vec.erase(newEnd, vec.end()); // ������ ���� ũ�� ���̱�

    std::cout << "���� �� ����: ";
    for (const int& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

