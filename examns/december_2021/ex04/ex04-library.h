#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_
#include <vector>
using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual ~Buffer();
};


// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
class SensorBuffer: public Buffer {
    private:
        vector<int> data;
        unsigned int num_averages;
        unsigned int write_count;

    public:
        // constructor taking an unsigned int
        SensorBuffer(unsigned int num_averages);

        // adding functions to SensorBuffer
        int readAvg();
        unsigned int writeCount();

        // overwriting pure virtual functions
        void write(int v);
        int read();



};

#endif /* EX04_LIBRARY_H_ */
