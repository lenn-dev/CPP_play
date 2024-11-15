#include <iostream>  // 입출력 스트림을 사용하기 위한 헤더 파일
#include <vector>    // 벡터 컨테이너를 사용하기 위한 헤더 파일
#include <algorithm> // 알고리즘을 사용하기 위한 헤더 파일 (여기서는 std::count)

int main() { // 프로그램의 시작점
    std::vector<int> vec = { 1, 2, 3, 1, 4, 1, 5 }; // 정수형 벡터 vec을 선언하고, 초기화 리스트로 값을 초기화
    int value = 1; // 벡터에서 개수를 세고자 하는 값 value를 1로 설정

    // 벡터 내에서 'value'와 일치하는 요소의 개수를 세기 위해 std::count를 사용
    int countValue = std::count(vec.begin(), vec.end(), value);
    // std::count는 vec.begin()부터 vec.end()까지 범위에서 'value'와 일치하는 요소의 개수를 반환

    // 'value'의 개수를 출력
    std::cout << "값 " << value << "의 개수: " << countValue << std::endl;

    return 0; // 프로그램이 정상적으로 종료됨을 알림
}

