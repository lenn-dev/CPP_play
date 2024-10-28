
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class Person {
    char* name; // 이름을 저장하기 위한 동적 메모리 포인터
    char* addr; // 주소를 저장하기 위한 동적 메모리 포인터
public:
    Person(const char* name, const char* addr); // 생성자
    ~Person(); // 소멸자
    Person(const Person& p); // 복사 생성자
    Person(Person&& p); // 이동 생성자
    Person& operator=(const Person& p); // 대입 연산자
    Person& operator=(Person&& p); // 이동 대입 연산자
    void print() const; // 출력 함수
    void chAddr(const char* newAddr); // 주소 변경 함수
};

#endif
