#include <iostream>  // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>    // 벡터 컨테이너를 사용하기 위한 헤더 파일
#include <algorithm> // 알고리즘을 사용하기 위한 헤더 파일 (여기서는 std::remove)

int main() { 
    std::vector<int> vec = { 1, 2, 3, 1, 4, 1, 5 }; // 정수형 벡터 vec을 선언하고, 초기화 리스트로 값을 초기화
    int value = 1; // 벡터에서 제거할 값 value를 1로 설정

    // 벡터에서 value(1)를 제거하려고 시도. 
    // std::remove는 실제로 벡터에서 요소를 삭제하지 않고, 제거된 요소들을 "뒤로 밀어놓음".
    auto newEnd = std::remove(vec.begin(), vec.end(), value);
    // newEnd는 벡터에서 value(1)가 제거된 뒤, 남은 유효한 데이터 영역의 끝을 가리킴.
    // 이제 실제로 벡터에서 그 값을 삭제하기 위해 erase()를 사용하여 벡터 크기를 줄임.
    vec.erase(newEnd, vec.end()); // newEnd부터 vec.end()까지의 요소들을 벡터에서 제거 (크기 줄이기)

    // "제거 후 벡터: "라는 문자열을 출력
    std::cout << "제거 후 벡터: ";

    // 벡터의 각 요소를 출력하기 위해 반복문을 사용
    for (const int& val : vec) { // 벡터의 각 요소를 순차적으로 참조하며 반복
        std::cout << val << " "; // 각 요소를 출력 후, 공백을 추가
    }

    std::cout << std::endl; // 출력 후 줄 바꿈

    return 0; // 프로그램이 정상적으로 종료됨을 알림
}



