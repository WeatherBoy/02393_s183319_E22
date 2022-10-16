#include "doubly-linked.h"

List::List(void) {
    // Declaring our first node and it's values.
    // I am initialising a lot to NULL, because this
    // will make handling certain situations a lot easier.
    //
    // Notice that I make the first a pointer to a Node 
    // variable, this is because our member variable is
    // a pointer to the Node type.
    Node *first;
    first->val = NULL;
    first->next = NULL;
    first->prev = NULL;

    // Assigning the member variable to be this "NULL-
    // initialization".
    this->first = first;
}

// Destructor doesn't need to do anything
List::~List(void) {};

void List::insert(int n) {
    // I think that by this implementation we will always insert
    // in constant time.
    //
    // Why not just use pointers, I guess...

    if (first->val == NULL) {
        // In this first case, because of how I decided to do it
        // the value at our first node is NULL, this means that
        // our entire linked list is empty or NULL.
        // We obviously wants to insert at the end, which in this
        // case is the begining, so we just insert the value here.
        first->val = n;
        
    } else if (first->val != NULL && first->prev == NULL) {
        // A litlle more complicated case.
        // The value at our first node isn't NULL but the value 
        // of the previous node is NULL. Since we insert at the end
        // which is first's previous Node, because we link
        // back around from begining to end and vice versa, this means
        // that our list is empty asside from the first Node.
        //
        // In this case we make a Node and connect to our first Node,
        // both back and front and now we have a list of two Nodes.
        Node * new_node;
        new_node->val = n;
        new_node->next = first;
        new_node->prev = first;

        
        first->prev = new_node;
        first->next = new_node;
        
    } else if(first->val != NULL && first->prev != NULL) {
        // This will always be the case we end in for lists of
        // size m, where m >= 2.
        //
        // Here there is something in the first Node, but 
        // it also has a previous Node, so we need to insert
        // a new Node at previous, without messing any of
        // the lists internal structure up.
        //
        // I have also made the previous_last_node variable,
        // here in an attempt to make the code more readable.
        // The previous last Node is now the second to last
        // Node and its next () is therefore gonna be pointing
        // at the new last Node, more precisely the [!] line.
        Node * new_node;
        Node * prev_last_node = first->prev;
        new_node->val = n;
        new_node->next = first;
        new_node->prev = prev_last_node;

        prev_last_node->next = new_node;    // <-- [!]
        first->prev = new_node;

    }

}

void List::reverse(void) {
    // TODO
    // implement this
}

void List::print(void) {
    // TODO
    // write comments for this
    if (first->val != NULL) {
        cout << first->val << ", ";

        if (first->next != NULL) {
            Node * temp_node = first;

            while (temp_node->next != first) {
                temp_node = temp_node->next;
                cout << temp_node->val << ", ";

            }
            cout << temp_node->val;
            
        }
    }
}
