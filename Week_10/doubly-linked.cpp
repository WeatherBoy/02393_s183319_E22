#include <iostream>
#include "doubly-linked.h"

List::List(void) {
    // This is a litlle bit of a cheat because I did look at the
    // at the solution. But it is clearly a lot easier to just
    // assign first to be a null-pointer.
    //
    // Understanding the difference between NULL and nullptr:
    // It is extremely basic.
    // NULL can be assigned to pointers as well as constants,
    // wheras a nullptr can only be assigned to something that
    // is a pointer.
    this->first = nullptr;
    
}


List::~List(void) {
    // We actually need to erase something here, when we call
    // our destructor.

    if (first == nullptr) {
        // If first is just the nullptr, then we can return,
        // because our doubly-linked list is empty.
        return;

    } else if (first->next == first) {
        // If the next element of first is first, then first
        // is the sole element and we can just delete it.
        delete first;
        return;

    } else {
        // Otherwise, we should delete all the elements
        // iteratively.
        // We do this by creating a temporary Node, which
        // will help us loop through the doubly-linked list.
        Node * temp_node = first;

        while(temp_node->next != first) {
            // We can then assign the temporary Node to the
            // next value and delete the value it previously
            // assumed.
            temp_node = temp_node->next;
            delete temp_node->prev;

        }
        ////////////////////////////////////////////////////////////////////
        // REMEMBER:
        // Tripple check when you delete memory, because what went wrong
        // here was you were trying to delete the same memory twice.
        // You basicly delete "this->first" on your first run through
        // the while loop, but you also tried to delete "this->first",
        // when you got to it the second time around...
        ////////////////////////////////////////////////////////////////////
        // delete temp_node->next;
        
        delete temp_node;
        return;
    }

};


void List::insert(int n) {
    // I think that by this implementation we will always insert
    // in constant time.
    //
    // Why not just use pointers, I guess...

    // REMEMBER!
    // To instantiate your objects...
    //
    // I create a temporary Node, which value (val) is gonna be
    // the n we wish to insert.
    Node *temp_node = new Node();
    temp_node->val = n;

    if (first == nullptr) {
        // In this first case, if first is a nullptr, then there
        // is simply nothing in our dobly linked list. It
        // is empty.
        // We obviously wants to insert at the end, which in this
        // case is the begining, so we just insert the value here.
        first = temp_node;

        // But we need to make som links, so this temp_node should
        // be pointing back and forth to itself.
        first->prev = first;
        first->next = first;
        return;
        
    } else if (first->next == first && first->prev == first) {
        // A litlle more complicated case.
        // If we are in the case that first is pointing to itself,
        // then it is the only element in the list and as such
        // this should be handled just a little different than
        // normally.
        // There needs to be a link back and forth to the new
        // Node we wish to insert.
        //
        // Connecting to first to the temporary Node.
        first->next = temp_node;
        first->prev = temp_node;

        // Connecting the temporary Node to first.
        temp_node->prev = first;
        temp_node->next = first;

        return;
        
    } else if(first->prev != first && first->next != first) {
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
        Node * prev_last_node = first->prev;
        temp_node->next = first;
        temp_node->prev = prev_last_node;

        prev_last_node->next = temp_node;    // <-- [!]
        first->prev = temp_node;

        return;
    } else {
        // Redundant error
        cout << "something went wrong" << endl;
        return;

    }

    return;
    // NOTE:
    // This could have been done as a single conditional, but I thought
    // this way was more educational and it helped understand the 
    // intrinsic logic of our doubly-linked list.
}


void List::reverse(void) {
    if (first == nullptr || (first->next == first && first->prev == first)) {
        // If the doubly-linked list is empty or it consists of only one item
        // then it doesn't matter to reverse it.
        return;

    } else {
        // Temporary Node to keep the index as we traverse the doubly linked
        // list.
        Node *temp_node = first;
        // We create the temporary next, such that we don't get into
        // complications when we overwrite it.
        //
        ////////////////////////////////////////////////////////////////////
        // REMEMBER:
        // You shouldn't use the "new" keyword if you immediatly assign the
        // the object a value.
        // This is the case here.
        ////////////////////////////////////////////////////////////////////
        Node *temp_next; // = new Node();

        // We then make the previously last Node into the new member variable
        // 'first'.
        this->first = first->prev;

        while (temp_node != first) {
            // As long as the current Node isn't first, then we reverse the
            // pointers.
            temp_next = temp_node->next;
            temp_node->next = temp_node->prev;
            temp_node->prev = temp_next;

            // Finally the temporary Node assumes the value of the "next"
            // Node in the doubly linked list before we began reversing.
            temp_node = temp_next;

        }

        // Now the next (and final) Node should be first, which we 
        // also need to fix.
        temp_next = first->next;
        first->next = first->prev;
        first->prev = temp_next;

        return;
    }

    return;
}


void List::print(void) {

    if (first != nullptr) {
        // If first isn't the nullptr, then we can print
        // its value.
        cout << first->val << " ";

        // Temporary node for printing.
        Node * temp_node = first;

        while (temp_node->next != first) {
                // As long as the next element isn't first,
                // then we can print the next element.
                //
                // We print in that awkward manner, because it
                // is a fence-post problem.
                temp_node = temp_node->next;
                cout << temp_node->val << " ";

            }
    }
    cout << endl;

    return;
}
