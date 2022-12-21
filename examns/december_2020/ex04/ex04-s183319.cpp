#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
//             constructor and methods
LimitedBuffer::LimitedBuffer(unsigned int max_buffer_cap, int rasmus) {
    this->max_buffer_cap = max_buffer_cap;
    this->rasmus = rasmus;

}

// Task 4(b).  Write a working implementation of write() and occupancy()
void LimitedBuffer::write(int v) {
    if (this->data.size() < max_buffer_cap) {
        this->data.push_back(v);

    }
    

}

unsigned int LimitedBuffer::occupancy() {
    return this->data.size();

}

// Task 4(c).  Write a working implementation of read()
int LimitedBuffer::read() {
    if (this->data.size() == 0) {
        return this->rasmus;

    }

    // "else"
    int val = this->data[0];
    this->data.erase(this->data.begin());
    return val;

}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
