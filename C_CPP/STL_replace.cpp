#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 2, 4, 2, 5 };
    int oldValue = 2;
    int newValue = 99;

    std::replace(vec.begin(), vec.end(), oldValue, newValue);

    std::cout << "��ü �� ����: ";
    for (const int& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

