#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 1, 4, 1, 5 };
    int value = 1;

    auto newEnd = std::remove(vec.begin(), vec.end(), value);
    vec.erase(newEnd, vec.end()); // 실제로 벡터 크기 줄이기

    std::cout << "제거 후 벡터: ";
    for (const int& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

