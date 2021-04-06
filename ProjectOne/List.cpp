#include <iostream>
#include "List.h"

using namespace std;

template <typename T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template <typename T>
List<T>::~List()
{
    Clear();
}

template <typename T>
List<T>::List(const List& l)
{
    head = NULL;
    tail = NULL;
    count = 0;
    if (l.head != NULL && l.tail != NULL) {
        this->count = l.count;
        Element<T>* tmp = l.head;
        this->AddHead(tmp->value);
        for (int i = 1; i < count; i++)
        {
            tmp = tmp->next;
            this->AddTail(tmp->value);
        }
    }
}

template <typename T>
void List<T>::Delete(int pos)
{
    if (pos < 0 || pos >= count)
    {
        cout << "Not correct position" << endl;
        return;
    }
    if (pos == 0) {
        if (count != 1) {
            Element<T>* tmp = head->next;
            delete[] head;
            head = tmp;
            head->prev = NULL;
            count--;
            return;
        }
        delete[] head;
        head = NULL;
        tail = NULL;
        count--;
        return;
    }
    else if (pos == count - 1) {
        Element<T>* tmp = tail->prev;
        delete[] tail;
        tail = tmp;
        tail->next = NULL;
        count--;
        return;
    }
    int i = 0;
    Element<T>* ins = head;
    while (i < pos)
    {
        ins = ins->next;
        i++;
    }
    Element<T>* tmp1 = ins->prev, * tmp2 = ins->next;
    tmp1->next = tmp2;
    tmp2->prev = tmp1;
    count--;
    delete[] ins;
}

template <typename T>
void List<T>::Insert(int pos)
{
    T data;
    cout << "Enter data:" << endl;
    cin >> data;
    if (pos < 0 || pos > count)
    {
        cout << "Not correct position" << endl;
        return;
    }
    if (pos == 0)
    {
        count++;
        AddHead(data);
        return;
    }
    else if (pos == count)
    {
        count++;
        AddTail(data);
        return;
    }
    count++;
    int i = 0;
    Element<T>* ins = head;
    while (i < pos)
    {
        ins = ins->next;
        i++;
    }

    Element<T>* tmp = new Element<T>;

    tmp->value = data;

    tmp->next = ins;
    tmp->prev = ins->prev;
    ins->prev = tmp;
}

template <typename T>
void List<T>::AddTail(T n)
{
    Element<T>* temp = new Element<T>;
    temp->value = n;

    if (tail != NULL && head != NULL)
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        tail = temp;
        head = temp;
    }
}

template <typename T>
void List<T>::AddHead(T n)
{
    Element<T>* temp = new Element<T>;
    temp->value = n;

    if (tail != NULL && head != NULL)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        tail = temp;
        head = temp;
    }
}
/*Delete All*/
template <typename T>
void List<T>::Clear()
{
    while (head != NULL) //
    {
        Delete(0);
    }
    count = 0;
}

template <typename T>
int List<T>::Count()
{
    Element<T>* temp = head;
    count = 0;
    while (temp != tail->next)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

template <typename T>
int List<T>::GetCount()
{
    return count;
}

template<class T>
Element<T>* List<T>::GetElem(int n)
{
    int i = 0;
    Element<T>* ins = head;
    while (i < n)
    {
        ins = ins->next;
        i++;
    }
    return ins;
}

template <typename T>
void List<T>::Print()
{
    Element<T>* temp = head;
    if (temp == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (temp != tail->next && temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
void List<T>::Print(int pos)
{
    int i = 0;
    Element<T>* ins = head;
    while (i < pos)
    {
        ins = ins->next;
        i++;
    }
    cout << ins->value;
}

template<class T>
List<T>& List<T>::operator=(const List& l)
{
    this->Clear();
    head = NULL;
    tail = NULL;
    count = 0;
    if (l.head != NULL && l.tail != NULL) {
        this->count = l.count;
        Element<T>* tmp = l.head;
        this->AddHead(tmp->value);
        for (int i = 1; i < count; i++)
        {
            tmp = tmp->next;
            this->AddTail(tmp->value);
        }
    }
    return *this;
}

template<class T>
List<T> List<T>::operator+(const List& l)
{
    List<int> ins;
    Element<int>* temp = this->head;
    for (int i = 0; i < this->count; i++)
    {
        ins.AddTail(temp->value);
        ins.count++;
        temp = temp->next;
    }
    temp = l.head;
    for (int i = 0; i < l.count; i++)
    {
        ins.AddTail(temp->value);
        ins.count++;
        temp = temp->next;
    }
    return ins;
}

template<class T>
bool List<T>::operator==(const List& l)
{
    return this->count == l.count;
}

template<class T>
bool List<T>::operator!=(const List& l)
{
    return this->count != l.count;
}

template<class T>
bool List<T>::operator<=(const List& l)
{
    return this->count <= l.count;
}

template<class T>
bool List<T>::operator>=(const List& l)
{
    return this->count >= l.count;
}

template<class T>
bool List<T>::operator<(const List& l)
{
    return this->count < l.count;
}

template<class T>
bool List<T>::operator>(const List& l)
{
    return this->count > l.count;
}

template<class T>
List<T> List<T>::operator-()
{
    Element<int>* tmp1 = this->head, * tmp2 = this->tail;
    for (int i = 0; i < count / 2; i++)
    {
        T tmp = tmp1->value;
        tmp1->value = tmp2->value;
        tmp2->value = tmp;
        tmp1 = tmp1->next;
        tmp2 = tmp2->prev;
    }
    return *this;
}