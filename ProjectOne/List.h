#pragma once
template <typename T> struct Element {
    T value;
    Element* next;
    Element* prev;
};

template <class T> class List
{
private:
    Element<T>* head;
    Element<T>* tail;
    int count;
public:
    Element<T>* GetHead() const {
        return this->head;
    }
    Element<T>* GetTail() const {
        return this->tail;
    }
    int GetCount() const {
        return this->count;
    }
    //�����������
    List(); //check
    //����������
    ~List(); //check
    //����������� �����������
    List(const List&); //check
    //�������� ����������
    int Count(); //check
    int GetCount(); //check
    //�������� ������� ������
    Element<T>* GetElem(int n); //check
    //������� ���� ������
    void Clear(); //check
    //�������� ��������, ���� ��������
    //�� �����������,
    //�� ������� ��� �����������
    void Delete(int pos = 0); //check
    void Insert(int pos = 0); //check
    //���������� � ����� ������
    void AddTail(T n); //check
    //���������� � ������ ������
    void AddHead(T n); //check
    //������ ������
    void Print(); //check
    //������ ������������� ��������
    void Print(int pos); //check

    List& operator = (const List& l); //check
    //�������� ���� ������� (�����������)
    List operator + (const List& l); //check
    //��������� �� ���������
    bool operator == (const List& l); //check
    bool operator != (const List& l); //check
    bool operator <= (const List& l); //check
    bool operator >= (const List& l); //check
    bool operator < (const List& l); //check
    bool operator > (const List& l); //check
    //��������������� ������
    List operator - (); //check
};

