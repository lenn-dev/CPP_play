#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    int value = 3;

    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        std::cout << "값 " << value << "을(를) 찾았습니다." << std::endl;
    }
    else {
        std::cout << "값을 찾지 못했습니다." << std::endl;
    }

    return 0;
}

