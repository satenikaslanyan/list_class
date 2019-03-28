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
    return List<T>::push_back(item);
}

template <class T>
void Queue<T>::pop()
{
    return List<T>::remove(0);
}

template <class T>
T& Queue<T>::q_front()
{
    return List<T>::front();
}

template <class T>
T& Queue<T>::q_back()
{
    return List<T>::back();
}

