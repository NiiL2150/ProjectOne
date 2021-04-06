#include <iostream>
#include "StackList.h"

using namespace std;

template <typename T>
StackList<T>::StackList()
{
    count = 0;
    FULL = 0;
    head = nullptr;
}

template <typename T>
void StackList<T>::Push(T c)
{
    if (IsFull()) {
        FULL++;
    }
    Element<T>* tmp = new Element<T>{ c, this->head };
    this->head = tmp;
    count++;
}

template <typename T>
void StackList<T>::Push(Element<T> c)
{
    c->next = this->head;
    this->head = c;
    if (IsFull()) {
        FULL++;
    }
    count++;
}

template <typename T>
Element<T>* StackList<T>::Pop()
{
    if (!IsEmpty())
    {
        Element<T>* tmp = this->head;
        this->head = tmp->next;
        tmp->next = nullptr;
        count--;
        return tmp;
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
void StackList<T>::Clear()
{
    Element<char>* z = this->GetTop();
    for (int i = 0; i < count; i++)
    {
        z = this->Pop();
        delete z;
    }
    count = 0;
}

template <typename T>
bool StackList<T>::IsEmpty()
{
    return count == 0;
}

template <typename T>
bool StackList<T>::IsFull()
{
    return count == FULL;
}

template <typename T>
int StackList<T>::GetCount()
{
    return count;
}

template <typename T>
int StackList<T>::GetFull()
{
    return FULL;
}

template <typename T>
Element<T>* StackList<T>::GetTop()
{
    return this->head;
}

template <typename T>
void StackList<T>::Print() {
    Element<char>* z = this->GetTop();
    cout << count << endl;
    for (int i = 0; i < count; i++)
    {
        cout << z->value << " ";
        z = z->next;
    }
    cout << endl << FULL << endl;
}