#ifndef DATA2_LIST_H
#define DATA2_LIST_H

#include <iostream>
#include <string>





template<class T>
struct Node
{
    T value;
    Node<T> *pnext = 0;
    Node(T value, Node* pnext)
    {
        this->value = value;
        this->pnext = pnext;
    }



};

template<class T>
struct List
{
    Node<T>* head = 0;
    int size = 0;
    void push_front(T value);
    void push_back(T value);
    void delete_elem(int index);
    void clear();
    void print();
};

template<class T>
void List<T>::push_front(T value)
{
    head = new Node<T>(value, head);
    size ++;

}

template<class T>
void List<T>::push_back(T value)
{
    Node<T>* current = head;
    if (size == 0)
    {
        head = new Node<T>(value, head);

    }else
    {
        for (int i = 0; i < size-1; i++)
        {
            current = current -> pnext;
        }
        current -> pnext = new Node<T>(value,0);
    }
    size ++;
}

template<class T>
void List<T>::delete_elem(int index)
{
    if (index <= size-1) {


        if (index == 0) {
            Node<T> *tmp_head = head->pnext;
            delete head;
            head = nullptr;
            head = tmp_head;
        } else if (index == size - 1) {
            Node<T> *current = head;
            for (int i = 0; i < size - 2; i++) {
                current = current->pnext;
            }
            delete current->pnext;
            current->pnext = nullptr;

        } else {
            Node<T> *previous_elem = 0;
            Node<T> *next_elem = 0;
            Node<T> *current = 0;
            for (int i = 0; i <= index; i++) {
                if (i == index - 1) {
                    previous_elem = current;
                } else if (i == index) {
                    next_elem = current->pnext;
                }
                current = current->pnext;
            }
            delete current;
            previous_elem->pnext = next_elem;

        }
        size--;
    }
}

template<class T>
void List<T>::clear()
{
    for (int i = 0; i < size; i++)
    {
        Node<T> *tmp_head = head->pnext;
        delete head;
        head = nullptr;
        head = tmp_head;
    }
}

template<class T>
void List<T>::print()
{
    Node<T> *current = head;
    for (int i = 0; i < size; i++)
    {
        std::cout<<current -> value<<std::endl;
        current = current -> pnext;

    }
}


#endif //DATA2_LIST_H
