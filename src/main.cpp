#include "queue.hpp"

int main()
{
    List<int> l;
    //l.insert(1, 2);
    //l.pop_back();
    for (int i = 0; i < 10; ++i) {
        l.push_back(i);
    }
    std::cout << l;
    List<int> k;
    k = l;
    std::cout << k;

    // l.get_size();
    // l.insert(11, 110);
    // l.insert(9, 110);
    // std::cout << l;
    //l.get_size();
    //l.remove(0);
    l.pop_back();
    std::cout<< l;
    //l.get_size();
    l.reverse();
    std::cout << l;


    Queue<int> q;
    try {
        std::cout << q.s_front() << std::endl;
    } catch (const char* c) {
        std::cout << c << std::endl;
    }
    for(int i = 0; i < 10; ++i) {
        q.s_push(i);
    }
    while(!q.s_is_empty()){
        try {
            std::cout << q.s_front() << "  ";
        }catch(const char* c){
            std::cout << c << std::endl;
        }
        q.s_pop();
    }
    std::cout << std::endl;

}

