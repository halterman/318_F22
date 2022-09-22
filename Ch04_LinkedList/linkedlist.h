// linkedlist.h

struct Node {
    int data;
    Node *next;
};

// Inserts a new element onto the front of a
// null-terminated linked list
Node *insert(Node *p, int element);

