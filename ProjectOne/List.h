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
    //Конструктор
    List(); //check
    //Деструктор
    ~List(); //check
    //Конструктор копирования
    List(const List&); //check
    //Получить количество
    int Count(); //check
    int GetCount(); //check
    //Получить элемент списка
    Element<T>* GetElem(int n); //check
    //Удалить весь список
    void Clear(); //check
    //Удаление элемента, если параметр
    //не указывается,
    //то функция его запрашивает
    void Delete(int pos = 0); //check
    void Insert(int pos = 0); //check
    //Добавление в конец списка
    void AddTail(T n); //check
    //Добавление в начало списка
    void AddHead(T n); //check
    //Печать списка
    void Print(); //check
    //Печать определенного элемента
    void Print(int pos); //check

    List& operator = (const List& l); //check
    //сложение двух списков (дописывание)
    List operator + (const List& l); //check
    //сравнение по элементам
    bool operator == (const List& l); //check
    bool operator != (const List& l); //check
    bool operator <= (const List& l); //check
    bool operator >= (const List& l); //check
    bool operator < (const List& l); //check
    bool operator > (const List& l); //check
    //переворачивание списка
    List operator - (); //check
};

