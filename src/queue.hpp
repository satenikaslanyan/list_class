#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "list.hpp"


template <class T>
class Queue : public List<T>
{
    public:
        T& q_front();
        T& q_back();
        void push(T item);
        void pop();
};

#endif

template <class T>
void Queue<T>::push(T item)
{
    List<T>::push_back(item);
}

template <class T>
void Queue<T>::pop()
{
    List<T>::remove(0);
}

template <class T>
T& Queue<T>::q_front()
{
    if(List<T>::is_empty()) {
        throw "Empty queue hasn't front element";
    }
    return List<T>::front();
}

template <class T>
T& Queue<T>::q_back()
{
    if(List<T>::is_empty()) {
        throw "Empty queue hasn't back element";
    }
    return List<T>::back();
}

