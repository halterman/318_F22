#include <iostream>
#include "linkedlist.h"

void print_list(Node *list) {
    std::cout << '{';
    if (list) {
        std::cout << list->data;
        for (auto p = list->next; p; p = p->next)
            std::cout << ", " << p->data;
    }
    std::cout << "}\n";
}

int main() {
    std::cout << "Enter values--hit return after each value\n";    
    std::cout << "Any negative value ends the entry\n";    
    std::cout << "------------------------------------------\n";    
    Node *my_list = nullptr;
    print_list(my_list);
    int input = 0;
    while (input >= 0) {
        std::cin >> input;
        my_list = insert(my_list, input);
        print_list(my_list);
    }
}
