#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "list.hpp"


template <class T>
class Queue : public List<T>
{
    private:
        List<T> m_list;
    public:
        bool q_is_empty();
        T& q_front();
        T& q_back();
        void push(T item);
        void pop();
};

#endif

template <class T>
bool Queue<T>::q_is_empty()
{
    return m_list.is_empty();
}

template <class T>
void Queue<T>::push(T item)
{
    m_list.push_back(item);
}

template <class T>
void Queue<T>::pop()
{
    if (m_list.is_empty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    m_list.remove(0);
}

template <class T>
T& Queue<T>::q_front()
{
    if(q_is_empty()) {
        throw "Empty queue hasn't front element";
    }
    return m_list.front();
}

template <class T>
T& Queue<T>::q_back()
{
    if(q_is_empty()) {
        throw "Empty queue hasn't back element";
    }
    return m_list.back();
}

