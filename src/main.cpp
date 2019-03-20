#include "list.hpp"

int main()
{
    List<int> l;
    l.insert(1, 2);
    l.pop_back();
    for (int i = 0; i < 10; ++i) {
        l.push_back(i);
    }
    std::cout << l;
    l.get_size();
    l.insert(11, 110);
    l.insert(5, 110);
    std::cout << l;
    l.get_size();
    l.remove(4);
    l.pop_back();
    std::cout<< l;
    l.get_size();
    l.reverse();
    std::cout << l;
}

