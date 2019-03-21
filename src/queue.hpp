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
        T& s_front();
        T& s_back();
        void s_push(T item);
        void s_pop();
        bool s_is_empty();
};

#endif

template <class T>
bool Queue<T>::s_is_empty()
{
    return m_list.m_size == 0;
}

template <class T>
void Queue<T>::s_push(T item)
{
    m_list.push_back(item);
}

template <class T>
void Queue<T>::s_pop()
{
    if (s_is_empty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    m_list.remove(0);
}

template <class T>
T& Queue<T>::s_front()
{
    if(s_is_empty()) {
        throw "Empty queue hasn't front element";
    }
    return m_list.front();
}
/*
template <class T>
T& Queue<T>::back()
{
    if(is_empty()) {
        throw "Empty queue hasn't back element";
    }
    return m_list.back();
}
*/
