#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T> class List;

template<typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& v);

template <typename T>
struct Node
{
    Node* next;
    T data;
};

template <typename T>
class List
{
    protected:
        int m_size;
        Node<T>* first;
    public:
        List(): m_size(0), first(NULL) {}
        List(const List& list);
        List<T>& operator=(const List& list);
        ~List();
        void get_size();
        bool is_empty();
        void insert(int pos, T new_data); 
        void remove(int pos);
        void push_back(T data);
        void pop_back();
        void reverse();
        friend std::ostream& operator<< <>(std::ostream& out, const List& l);
        T& front();
        T& back();

};

#endif

template <typename T>
List<T>::List(const List<T>& list)
    : m_size(0)
      , first(NULL)
{
    Node<T>* new_node = list.first;
    while (new_node)
    {
        push_back(new_node->data);
        new_node = new_node->next;
    }
}

template <typename T>
List<T>& List<T>::operator=(const List& list)
{
    Node<T>* new_node = list.first;
    while (new_node)
    {
        push_back(new_node->data);
        new_node = new_node->next;
    }
    return *this;
}


template <typename T>
List<T>::~List()
{
    Node<T>* curr = first;
    while(curr) {
        Node<T>* next_node = curr->next;
        delete curr;
        curr = next_node;
    }
}

template <typename T>
void List<T>::get_size()
{
    std::cout << "Size is: " << m_size << std::endl;
}


template <typename T>
bool List<T>::is_empty()
{
    return first == NULL;
}

template <typename T>
void List<T>::insert(int pos, T data) 
{ 
    if (pos >= m_size) {
        std::cout << "Out of range" << std::endl;
        return;
    }
    Node<T>* new_node = new Node<T>;
    new_node->data = data;
    if (pos == 0) {
        new_node->next = first;
        first = new_node;
    } else {
        Node<T>* temp = first;
        for (int i = 1; i < pos; ++i) {
            temp = temp->next;
        }
        new_node->next  = temp->next ;
        temp->next  = new_node;
    }
    ++m_size;
} 

template <typename T>
void List<T>::remove(int pos) 
{
    if (is_empty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (pos > m_size) {
        std::cout << "Removing element's index is out of range" << std::endl;
        return;
    }
    if (pos == 0) {
        if(first->next != NULL){
            Node<T>* temp = first->next;
            delete first;
            first = temp;
        }
        else {
            delete first; 
            first = NULL;
        }
    } else {
        Node<T>* curr = first;;
        for (int i = 1; curr != NULL && i < pos; ++i) {
            curr = curr->next;
        }
        Node<T>* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    --m_size;
}

template <typename T>
void List<T>::pop_back()
{
    remove(--m_size);
}

template <typename T>
void List<T>::push_back(T data) 
{
    ++m_size;
    Node<T>* new_node = new Node<T>;
    new_node->data = data;
    new_node->next = NULL;
    if(is_empty()) {
        first = new_node;
        return;
    }
    Node<T>* curr = first;
    while(curr) {
        if(curr->next == NULL) {
            curr->next = new_node;
            return;
        }
        curr = curr->next;
    }
}

template <typename T>
void List<T>::reverse() 
{
    Node<T>* curr = first;
    Node<T>* prev = NULL;
    Node<T>* next = NULL;
    while (curr) {
        next = prev;
        prev = curr;
        curr = curr->next;
        prev->next = next;
    }
    first = prev;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& l)
{
    Node<T>* temp = l.first;
    while (temp) {
        out << temp->data << "  ";
        temp = temp->next;
    }
    std::cout << std::endl;
    return out;
}

template <typename T>
T& List<T>::front()
{
    return first->data;
}

template <typename T>
T& List<T>::back()
{
    Node<T>* curr = first;
    for (int i = 1; i < m_size; ++i) {
            curr = curr->next;
    }
    return curr->data;
} 
