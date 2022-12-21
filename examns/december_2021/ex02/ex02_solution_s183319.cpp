#include <iostream>
#include "ex02_library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger* find(Passenger *q, unsigned int ticket) {
    if (q == nullptr) {
        // If nullptr, return nullptr!
        return nullptr;

    }

    // Creates a temporary pointer, because we really don't wanna
    // mistreat q
    Passenger * tmp_ptr = q;

    // Going through the linked list
    while (tmp_ptr->next != nullptr) {
        if (tmp_ptr->ticket == ticket) {
            return tmp_ptr;

        } else {
            tmp_ptr = tmp_ptr->next;

        }
    }

    // Checking the last element of the linked list
    if (tmp_ptr->ticket == ticket) {
        return tmp_ptr;

    }

    // None of the cases were met, we return a nullptr
    return nullptr;
}


// Task 2(b).  Implement this function
Passenger* remove(Passenger *q, unsigned int ticket) {
    // Edge case for q being the nullptr
    if (q == nullptr) {
        return q;

    }

    // In the case that there is only one element and it is the ticket
    if (q->ticket == ticket && q->next == nullptr) {
        return nullptr;

    }

    Passenger * tmp_prev = q;
    Passenger * tmp_next = q->next;

    while (tmp_next != nullptr) {
        if (tmp_next->ticket == ticket) {
            tmp_prev->next = tmp_next->next;
            return q;

        } else {
            tmp_prev = tmp_next;
            tmp_next = tmp_next->next;
            
        }
    }
    
}

// Task 2(c).  Implement this function
Passenger* priority(Passenger *q) {
    // Replace the following with your code
    return nullptr;
}

// Do not modify
void displayQueue(Passenger *q) {
    if (q == nullptr) {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    if (q->priority) {
        cout << " (priority)";
    }
    cout << endl;
    displayQueue(q->next);
}
