
#include <iostream>
#include <cstring>
#include "Person.h"
using namespace std;

// ������ (�Ű����� �ִ� ������: �̸��� �ּҸ� �޾Ƽ� ��ü�� �ʱ�ȭ)
Person::Person(const char* name, const char* addr) {
    this->name = new char[strlen(name) + 1]; // �̸��� ������ �޸� �Ҵ�
    strcpy(this->name, name); // �Ҵ��� �޸𸮿� �̸� ����

    this->addr = new char[strlen(addr) + 1]; // �ּҸ� ������ �޸� �Ҵ�
    strcpy(this->addr, addr); // �Ҵ��� �޸𸮿� �ּ� ����
    cout << "Person ��ü ������(" << name << ")" << endl; // ���� �α� ���
}

// �Ҹ��� : ���� �޸� ����
Person::~Person() {
    cout << "Person ��ü ������(" << name << ")" << endl; // �Ҹ� �α� ���
    delete[] name; // �̸� �޸� ����
    delete[] addr; // �ּ� �޸� ����
}

// ���� ������:  Person ��ü�κ��� ���� ���� (�޸𸮰��� ��������)
Person::Person(const Person& p) {

    name = new char[strlen(p.name) + 1];
    strcpy(name, p.name);
    addr = new char[strlen(p.addr) + 1];
    strcpy(addr, p.addr);
    cout << "Person ��ü ������(" << name << ")" << endl; // ���� �α� ���
}

// �̵� ������
Person::Person(Person&& p) : name(p.name), addr(p.addr) {
    // �ٸ� ��ü�� ���ҽ��� ��������, �ٸ� ��ü�� �����͸� null�� ����
    p.name = nullptr;
    p.addr = nullptr;
    cout << "Person ��ü �̵���(" << name << ")" << endl; // �̵� �α� ���
}

// ���� ���� ������
Person& Person::operator=(const Person& p) {
    if (this != &p) { // �ڱ� ���� üũ �ڱ��ڽŰ� �Ű������� �޴� ��ü p�� ���� �ʴٸ�
        delete[] name; // ���� ���ҽ� ����
        delete[] addr; // ���� ���ҽ� ����


        // p��üũ�⿡ �´� �� �޸� �Ҵ� ��  ��ü�� �����͸� ����
      // �� ��� string ���̶� 9�� ���Կ����� �����ڵ�� �ٸ���, strlen(), strcpy() �����
    //  ���� ���ÿ����� sizeof(), memcpy() �� �����.
        name = new char[strlen(p.name) + 1]; //���ڿ��� ���̿� null ���� �����Ͽ� �޸� �����Ҵ�
        strcpy(name, p.name); // �� �޸𸮿� ���ο� ��ü �����Ͱ� ���� 
        addr = new char[strlen(p.addr) + 1];
        strcpy(addr, p.addr);
        cout << "Person ��ü ������(" << name << ")" << endl; // ���� �α� ���
    }
    return *this; // �ڱ��ڽ� ��üPerson ������ȯ
}

// �̵� ���� ������
// rvalue ���� ������ �̵��� �����ǿ����� �ٲ�� ������ ������� ���� ����
Person& Person::operator=(Person&& p) {
    if (this != &p) { // ��ü�ڽ��� �Ű������� ������ ��ü�� ������ üũ
        delete[] name; // ���� ���ҽ� ����
        delete[] addr; // ���� ���ҽ� ����

        // ���� �ǿ������� ������ �̵���
        name = p.name;
        addr = p.addr;

        // ���� �ǿ����� ��ü�� �����͸� null�� ����
        p.name = nullptr;
        p.addr = nullptr;
        cout << "Person ��ü �̵� ������(" << name << ")" << endl; // �̵� ���� �α� ���
    }
    return *this; // ��ü Person ���� ��ȯ
}

// ��� �Լ�
void Person::print() const {
    cout << addr << "�� ��� " << name << "�Դϴ�." << endl; // �ּҿ� �̸� ���
}

// �ּ� ���� �Լ�
void Person::chAddr(const char* newAddr) {
    delete[] addr; // ���� �ּ� �޸� ����
    addr = new char[strlen(newAddr) + 1]; // �� �ּҸ� ���� �޸� �Ҵ�
    strcpy(addr, newAddr); // �� �ּ� ����
}


