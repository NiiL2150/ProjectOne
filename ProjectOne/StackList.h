#pragma once

template <typename T> struct Element {
    T value;
    Element* next;
};

template <class T> class StackList
{
private:
    //������ ��� �������� ������
    Element<T>* head;
    //��������� �� ������� �����
    int count;
    unsigned int FULL;
public:
    //�����������
    StackList();
    //���������� ��������
    void Push(T c);
    void Push(Element<T> c);
    //���������� ��������
    Element<T>* Pop();
    //������� �����
    void Clear();
    //�������� ������������� ��������� � �����
    bool IsEmpty();
    bool IsFull();
    //���������� ��������� � �����
    int GetCount();
    int GetFull();
    Element<T>* GetTop();

    void Print();
};