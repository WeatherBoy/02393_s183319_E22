#include "ex04-library.h"
#include <numeric>
using namespace std;

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods
SensorBuffer::SensorBuffer(unsigned int num_averages) {
    // We allocate memeory to our vector "data" by using the reserve()
    // function.
    this->num_averages = num_averages;
    this->write_count = 0;
}

// Task 4(b).  Write a working implementation of write() and writeCount()
void SensorBuffer::write(int v) {
    this->write_count++;

    if (this->write_count > this->num_averages) {
        // If we surpass the amount of data we have allocated we erease
        // the first entry of data, and then append. 
        this->data.erase(this->data.begin());
        this->data.push_back(v);

    } else {
        // If we are still under our data limit, then we just append to
        // data
        this->data.push_back(v);
    }

}

unsigned int SensorBuffer::writeCount() {
    return this->write_count;

}

// Task 4(c).  Write a working implementation of read()
int SensorBuffer::read() {
    if (this->write_count == 0) {
        // special case
        return 0;

    } else {
        // Else return the latest datapoint appended to
        // data
        return this->data.back();
    }
}

// Task 4(d).  Write a working implementation of readAvg()
int SensorBuffer::readAvg() {
    if (this->write_count == 0) {
        // special case
        return 0;

    } else {
        // Else return the average of the vector
        return int(accumulate(this->data.begin(), this->data.end(), 0.0) / this->data.size());
    }
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
