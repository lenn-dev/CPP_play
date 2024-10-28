#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 2, 4, 2, 5 };
    int oldValue = 2;
    int newValue = 99;

    std::replace(vec.begin(), vec.end(), oldValue, newValue);

    std::cout << "´ëÃ¼ ÈÄ º¤ÅÍ: ";
    for (const int& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

