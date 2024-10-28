
#include <iostream>
#include <cstring>
#include "Person.h"
using namespace std;

// 생성자 (매개변수 있는 생성자: 이름과 주소를 받아서 객체를 초기화)
Person::Person(const char* name, const char* addr) {
    this->name = new char[strlen(name) + 1]; // 이름을 저장할 메모리 할당
    strcpy(this->name, name); // 할당한 메모리에 이름 복사

    this->addr = new char[strlen(addr) + 1]; // 주소를 저장할 메모리 할당
    strcpy(this->addr, addr); // 할당한 메모리에 주소 복사
    cout << "Person 객체 생성함(" << name << ")" << endl; // 생성 로그 출력
}

// 소멸자 : 동적 메모리 해제
Person::~Person() {
    cout << "Person 객체 제거함(" << name << ")" << endl; // 소멸 로그 출력
    delete[] name; // 이름 메모리 해제
    delete[] addr; // 주소 메모리 해제
}

// 복사 생성자:  Person 객체로부터 깊은 복사 (메모리공간 공유방지)
Person::Person(const Person& p) {

    name = new char[strlen(p.name) + 1];
    strcpy(name, p.name);
    addr = new char[strlen(p.addr) + 1];
    strcpy(addr, p.addr);
    cout << "Person 객체 복사함(" << name << ")" << endl; // 복사 로그 출력
}

// 이동 생성자
Person::Person(Person&& p) : name(p.name), addr(p.addr) {
    // 다른 객체의 리소스를 가져오고, 다른 객체의 포인터를 null로 설정
    p.name = nullptr;
    p.addr = nullptr;
    cout << "Person 객체 이동함(" << name << ")" << endl; // 이동 로그 출력
}

// 복사 대입 연산자
Person& Person::operator=(const Person& p) {
    if (this != &p) { // 자기 대입 체크 자기자신과 매개변수로 받는 객체 p가 같지 않다면
        delete[] name; // 기존 리소스 해제
        delete[] addr; // 기존 리소스 해제


        // p객체크기에 맞는 새 메모리 할당 후  객체의 데이터를 복사
      // 이 경우 string 값이라 9장 대입연산자 예시코드와 다르게, strlen(), strcpy() 사용함
    //  강의 예시에서는 sizeof(), memcpy() 를 사용함.
        name = new char[strlen(p.name) + 1]; //문자열의 길이에 null 문자 포함하여 메모리 동적할당
        strcpy(name, p.name); // 새 메모리에 새로운 객체 데이터값 복사 
        addr = new char[strlen(p.addr) + 1];
        strcpy(addr, p.addr);
        cout << "Person 객체 대입함(" << name << ")" << endl; // 대입 로그 출력
    }
    return *this; // 자기자신 객체Person 참조반환
}

// 이동 대입 연산자
// rvalue 참조 데이터 이동시 우측피연산자 바뀌기 때문에 상수참조 받지 않음
Person& Person::operator=(Person&& p) {
    if (this != &p) { // 객체자신이 매개변수로 들어오는 객체와 같은지 체크
        delete[] name; // 기존 리소스 해제
        delete[] addr; // 기존 리소스 해제

        // 우측 피연산자의 내용을 이동함
        name = p.name;
        addr = p.addr;

        // 우측 피연산자 객체의 포인터를 null로 변경
        p.name = nullptr;
        p.addr = nullptr;
        cout << "Person 객체 이동 대입함(" << name << ")" << endl; // 이동 대입 로그 출력
    }
    return *this; // 객체 Person 참조 반환
}

// 출력 함수
void Person::print() const {
    cout << addr << "에 사는 " << name << "입니다." << endl; // 주소와 이름 출력
}

// 주소 변경 함수
void Person::chAddr(const char* newAddr) {
    delete[] addr; // 기존 주소 메모리 해제
    addr = new char[strlen(newAddr) + 1]; // 새 주소를 위한 메모리 할당
    strcpy(addr, newAddr); // 새 주소 복사
}


