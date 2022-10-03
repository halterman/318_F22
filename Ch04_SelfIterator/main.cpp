#include <iostream>
#include "iter_self.h"

int main() {
    std::cout << "Enter values--hit return after each value\n";    
    std::cout << "Any negative value ends the entry\n";    
    std::cout << "------------------------------------------\n";    
    Sequence<int> seq(10);
    int input = 0;
    while (input >= 0) {
        std::cin >> input;
        seq.insert(input);
    }
    for (seq.begin(); seq.has_next(); seq.advance()) {
        std::cout << seq.current() << ' ';
    }
    std::cout << '\n';
}
