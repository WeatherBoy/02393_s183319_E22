#include "ex04-library.h"
#include <iostream>
#include <climits>
using namespace std;

/*
* WAUW, is this buffer!?!
* never before seen!
*/

// Task 4(a).  Write a placeholder implementation of CountingBuffer's
//             constructor and methods
CountingBuffer::CountingBuffer(int default_val) {
    this->default_val = default_val;

}

// Task 4(b).  Write a working implementation of write() and frequency()
void CountingBuffer::write(int v) {
    bool data_point_present = false;

    for(auto data_point : this->data) {
        // I don't entirely know whether this is correct, so I am just hoping
        if(data_point.first == v) {
            data_point_present = true;

            // The data_point exists within data, so we increment it
            this->data[v]++;
            break;
        }
    }

    for (auto ranking: this->insertion_ranking) {
        // incrementning all the rankings by one
        this->insertion_ranking[ranking.first]++;

    }

    // setting the ranking of v to be one
    this->insertion_ranking[v] = 1;

    if (!data_point_present) {
        // The value is appended to the map with frequency 1
        this->data[v] = 1;
    }

    return;
        

}

unsigned int CountingBuffer::frequency(int v) {
    for(auto data_point : data) {
        // I don't entirely know whether this is correct, so I am just hoping
        if(data_point.first == v) {
            // if the first value matches v, then we return the frequency
            // (second value).
            return data_point.second;

        }
    }

    // otherwise it isn't in our map, so we just return zero
    return 0;
}

// Task 4(c).  Write a working implementation of mostFrequent()
int CountingBuffer::mostFrequent() {
    // counting buffer loops over all data_points in this->data, and
    // finds the highest frequency with the lowest ranking
    if (this->data.empty()) {
        // In the case our buffer is empty, we just return the default value
        return this->default_val;

    } else {
        // to be used in the loop:
        unsigned int max_frequency = 0;
        unsigned int lowest_ranking = INT_MAX;
        int most_frequent_value = 0;

        for(auto data_point : this->data) {
            if (data_point.second > max_frequency ||
                (data_point.second == max_frequency &&
                this->insertion_ranking[data_point.first] < lowest_ranking)) {
                    // the frequency is greater then the current greatest frequency
                    // OR:
                    // the frequency is equal to the current greatest frequency AND
                    // the insertion ranking is also lower!
                    max_frequency = data_point.second;
                    lowest_ranking = this->insertion_ranking[data_point.first];
                    most_frequent_value = data_point.first;

                }
        }

        return most_frequent_value;
    }

}

// Task 4(d).  Write a working implementation of clear()
void CountingBuffer::clear() {
    // wauw
    this->data.clear();

}
// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
