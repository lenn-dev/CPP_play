#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 1, 4, 1, 5 };
    int value = 1;

    int countValue = std::count(vec.begin(), vec.end(), value);
    std::cout << "�� " << value << "�� ����: " << countValue << std::endl;

    return 0;
}

