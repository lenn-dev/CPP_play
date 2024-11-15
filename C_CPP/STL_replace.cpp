#include <iostream>  // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>    // 벡터 컨테이너를 사용하기 위한 헤더 파일
#include <algorithm> // 알고리즘을 사용하기 위한 헤더 파일 (여기서는 std::replace)

int main() { // 프로그램의 시작점
    std::vector<int> vec = { 1, 2, 3, 2, 4, 2, 5 }; // 정수형 벡터 vec을 선언하고, 초기화 리스트로 값을 초기화
    int oldValue = 2; // 벡터에서 교체할 값 oldValue를 2로 설정
    int newValue = 99; // 교체할 값 newValue를 99로 설정

    // 벡터 vec에서 oldValue(2)를 찾아 newValue(99)로 교체하는 작업
    std::replace(vec.begin(), vec.end(), oldValue, newValue);

    // "대체 후 벡터: "라는 문자열을 출력
    std::cout << "대체 후 벡터: ";

    // 벡터의 각 요소를 출력하기 위해 반복문을 사용
    for (const int& val : vec) { // 벡터의 각 요소를 순차적으로 참조하며 반복
        std::cout << val << " "; // 각 요소를 출력 후, 공백을 추가
    }

    std::cout << std::endl; // 출력 후 줄 바꿈

    return 0; // 프로그램이 정상적으로 종료됨을 알림
}


