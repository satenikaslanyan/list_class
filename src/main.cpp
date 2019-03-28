#include "queue.hpp"

int main()
{
    List<int> l;
    l.insert(1, 2);
    l.pop_back();
    for (int i = 0; i < 10; ++i) {
        l.push_back(i);
    }
    std::cout << l;
    l.insert(11, 110);
    l.insert(9, 110);
    std::cout << l;
    l.remove(10);
    std::cout << l;
    l.pop_back();
    std::cout<< l;
    l.reverse();
    std::cout << l;

    Queue<int> q;
    q.pop();
    try {
        std::cout << q.q_front() << std::endl;
    } catch (const char* c) {
        std::cout << c << std::endl;
    }
    for(int i = 0; i < 10; ++i) {
        q.push(i);
    }
    std::cout << q.q_back() << std::endl;
    while(!q.is_empty()){
        try {
            std::cout << q.q_front() << "  ";
        } catch (const char* c) {
            std::cout << c << std::endl;
        }
        q.pop();
    }
    std::cout << std::endl;
}

