#pragma once

template <typename T> struct Element {
    T value;
    Element* next;
};

template <class T> class StackList
{
private:
    //Массив для хранения данных
    Element<T>* head;
    //Указатель на вершину стека
    int count;
    unsigned int FULL;
public:
    //Конструктор
    StackList();
    //Добавление элемента
    void Push(T c);
    void Push(Element<T> c);
    //Извлечение элемента
    Element<T>* Pop();
    //Очистка стека
    void Clear();
    //Проверка существования элементов в стеке
    bool IsEmpty();
    bool IsFull();
    //Количество элементов в стеке
    int GetCount();
    int GetFull();
    Element<T>* GetTop();

    void Print();
};