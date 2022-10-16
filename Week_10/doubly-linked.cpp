#include "doubly-linked.h"

List::List(void) {
    // Declaring our first node and it's values
    Node *first;
    first->val = NULL;
    first->next = NULL;
    first->prev = NULL;

    this->first = first;
}

// Destructor doesn't need to do anything
List::~List(void) {};

void List::insert(int n) {
    // Why not just use pointers... I guess
    //
    // We start by assigning current node to the first value
    Node * curr_node = first;

    // Then we check through our nodes and stop, when they stop
    // pointing onwards, so as long as their next isn't a NULL
    // pointer, then we go to their next.
    while(curr_node->next != NULL) {
        curr_node = curr_node->next;

    }

    if (curr_node->val == NULL) {
        curr_node->val = n;

    } else {
        Node * new_node;
        new_node->val = n;
        new_node->next = NULL;
        new_node->prev = curr_node;

        curr_node->next = new_node;

    }

    


}
