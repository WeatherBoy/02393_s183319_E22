#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_
#include <map>
using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual void clear() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class CountingBuffer, by extending Buffer
class CountingBuffer: public Buffer {
    private:
        int default_val;
        // Map where first entry is value and second entry is frequency
        map<int, unsigned int> data;

        // Map of insertion ranking, this is probably one of the stupidest
        // things I have implemented during an exam and I highly doubt
        // this was what was intended
        map<int, unsigned int> insertion_ranking;

    public:
        // constructor taking an int
        CountingBuffer(int default_val);

        // adding functions to SensorBuffer
        unsigned int frequency(int v);
        int mostFrequent();

        // overwriting pure virtual functions
        void write(int v);
        void clear();
};

#endif /* EX04_LIBRARY_H_ */
