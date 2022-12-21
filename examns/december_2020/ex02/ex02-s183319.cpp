#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    if (list == nullptr) {
        // In the case that the list is a nullptr
        return 0;
    }

    unsigned int sum_length = 0;

    Elem * list_pntr = list;

    while(list_pntr->next != nullptr) {
        sum_length += list_pntr->times;
        list_pntr = list_pntr->next;

    }

    sum_length += list_pntr->times;

    return sum_length;
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {
    if (list == nullptr) {
        // In the case we get a nullptr, we initialize
        // the list
        Elem * new_node = new Elem;
        new_node->value = v;
        new_node->times = 1;
        new_node->next = nullptr;

        return new_node;
    }

    // Creating a pointer to list, because we do not want
    // to fuck with "list"
    Elem * last = list;

    while(last->next != nullptr) {
        // Traversing the list, till we hit the final element
        last = last->next;
    }

    // When we get the final element we update its end based
    // on the value at the last element
    if (last->value == v) {
        last->times++;

    } else {
        Elem * new_node = new Elem;
        new_node->value = v;
        new_node->times = 1;
        new_node->next = nullptr;

        last->next = new_node;

    }

    return list;
}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    if(n == 0) {
        return nullptr;
    }

    // Initialising our new list as follows
    Elem * head = new Elem;
    head->value = data[0];
    head->times = 1;
    head->next = nullptr;

    // then iterativly building the list by using our handy
    // append function
    for(unsigned int i = 1; i < n; i++) {
        head = append(head, data[i]);
    }

    return head;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
