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

        //This function checks if the list is empty or not
        bool is_empty();

        //This function inserts element in the 
        //given position in the range of [0, m_size-2]
        void insert(int pos, T new_data); 

        //This function deletes element in the 
        //given position in the range of [0, m_size-1] 
        void remove(int pos);

        //This function adds data in the end of the list
        void push_back(T data);

        //This function deletes the last element of the list
        void pop_back();

        //This function returns reverse of the list
        void reverse();

        //Overload function for operator <<
        friend std::ostream& operator<< <>(std::ostream& out, const List& l);

        //Returns the first element of the list
        T& front();

        //returns the last element of the list
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
        std::cout << "Can't remove element form empty list" << std::endl;
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
    if(List<T>::is_empty()) {
        throw "Empty list hasn't front element";
    }
    return first->data;
}

template <typename T>
T& List<T>::back()
{
    if(List<T>::is_empty()) {
        throw "Empty list hasn't back element";
    }
    Node<T>* curr = first;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    return curr->data;
} 
