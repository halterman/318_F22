
#include <iostream>


// linkedlist.h

int create_count = 0;
int destroy_count = 0;

struct Node {
    int data;
    Node *next;
    Node(int data) : data{data}, next{nullptr} {
        create_count++;
    }
    ~Node() {
        destroy_count++;
    }
};


//** // Inserts a new element onto the rear of a
//** // null-terminated linked list
//** Node *insert(Node *p, int n) {
//**     // Make the new node
//**     Node *nn = new Node(n);
//**     // Find the last element in the list
//**     Node *cursor = p; 
//**     while (cursor && cursor->next) 
//**         cursor = cursor->next;
//**     if (cursor) {   // Insert on back of nonempty list
//**         cursor->next = nn;
//**     } else {
//**         p = nn; // List initially empty
//**     }
//**     return p;
//** }

// BAD INSERT. DO NOT ATTEMPT TO USE LOCAL DATA OUTSIDE
// OF A FUNCTION or METHOD.
// Inserts a new element onto the rear of a
// null-terminated linked list
Node *insert(Node *p, int n) {
    // Make the new node
    Node new_node(n);   // Note: new_node is a local variable
    Node *nn = &new_node;
    // Find the last element in the list
    Node *cursor = p; 
    while (cursor && cursor->next) 
        cursor = cursor->next;
    if (cursor) {   // Insert on back of nonempty list
        cursor->next = nn;
    } else {
        p = nn; // List initially empty
    }
    return p;
}


void dispose_list(Node *p) {
    while (p) {
        auto temp = p;
        p = p->next;
        delete temp;
    }
}

void print_list(Node *list) {
    std::cout << '{';
    if (list) {
        std::cout << list->data;
        for (auto p = list->next; p; p = p->next)
            std::cout << ", " << p->data;
    }
    std::cout << "}\n";
}

void test() {
    std::cout << "Enter values--hit return after each value\n";    
    std::cout << "Any negative value ends the entry\n";    
    std::cout << "------------------------------------------\n";    
    Node *my_list = nullptr;
    print_list(my_list);
    int input = 0;
    while (input >= 0) {
        std::cin >> input;
        if (input >= 0)
            my_list = insert(my_list, input);
        print_list(my_list);
    }
    dispose_list(my_list);
    std::cout << "Nodes created: " << create_count << '\n';
    std::cout << "Nodes destroyed: " << destroy_count << '\n';
}


int main() {
    std::cout << "Beginning main\n";
    test();
    std::cout << "Ending main\n";
}
