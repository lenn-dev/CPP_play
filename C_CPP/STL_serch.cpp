#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 }; // 벡터 선언
    int value = 3; // 찾고자 하는 값

    // std::search는 서브 시퀀스를 찾는 함수이므로, 'value'를 하나의 요소로 구성된 벡터로 감싸서 전달
    auto it = std::search(vec.begin(), vec.end(), std::vector<int>{value}.begin(), std::vector<int>{value}.end());

    // 'value' 값이 벡터에서 존재하는지 확인
    if (it != vec.end()) { // 벡터에서 'value' 값을 찾은 경우
        std::cout << "값 " << value << "을(를) 찾았습니다." << std::endl; // 찾은 경우 메시지 출력
    }
    else { // 벡터에서 'value' 값을 찾지 못한 경우
        std::cout << "값을 찾지 못했습니다." << std::endl; // 찾지 못한 경우 메시지 출력
    }

    return 0; // 프로그램 종료
}

// search 는 find 와 다르게 서브 시퀀스를 찾는 함수임
// 단일값을 찾고자 할 때엔 find가 더 직관적임


