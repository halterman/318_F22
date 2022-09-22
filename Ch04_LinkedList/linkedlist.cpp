#include "linkedlist.h"


// // Inserts a new element onto the rear of a
// // null-terminated linked list; uses recursion
// Node *insert(Node *p, int n) {
//     //  Check that we are not at the end of the list
//     if (p)
//         p->next = insert(p->next, n); // Add to rest of list
//     else {   //  Insert new item
//         p = new Node;
//         p->data = n;
//         p->next = nullptr;
//     }
//     return p;
// }









//** // Inserts a new element onto the rear of a
//** // null-terminated linked list; avoids recursion
//** Node *insert(Node *p, int n) {
//**     // Make the new node
//**     Node *nn = new Node;
//**     nn->data = n;
//**     nn->next = nullptr;
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









// Inserts a new element onto the front of a
// null-terminated linked list
Node *insert(Node *p, int element) {
    Node *nn = new Node;
    nn->data = element;
    nn->next = p;
    return nn;
}


