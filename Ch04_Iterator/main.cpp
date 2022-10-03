#include <iostream>
#include "iter.h"

int main() {
    std::cout << "Enter values--hit return after each value\n";    
    std::cout << "Any negative value ends the entry\n";    
    std::cout << "------------------------------------------\n";    
    Sequence<int> seq(10);
    int input = 0;
    while (input >= 0) {
        std::cin >> input;
        if (input >=0) 
            seq.insert(input);
    }
    for (auto iter = seq.begin(); iter != seq.end(); iter++) {
        std::cout << *iter << ' ';
    }
    std::cout << '\n';
}
