
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class Person {
    char* name; // �̸��� �����ϱ� ���� ���� �޸� ������
    char* addr; // �ּҸ� �����ϱ� ���� ���� �޸� ������
public:
    Person(const char* name, const char* addr); // ������
    ~Person(); // �Ҹ���
    Person(const Person& p); // ���� ������
    Person(Person&& p); // �̵� ������
    Person& operator=(const Person& p); // ���� ������
    Person& operator=(Person&& p); // �̵� ���� ������
    void print() const; // ��� �Լ�
    void chAddr(const char* newAddr); // �ּ� ���� �Լ�
};

#endif
