#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int number_of_intervals;
    int size_of_data_set;
    int length_of_intervals;
    int temp_value;

    // We can set the largest number as zero initially 
    // because all input should be positive integers
    int largest_number = 0;

    cin >> number_of_intervals;
    cin >> size_of_data_set;

    // We use the vector type because Hanse said
    // we couldn't use a list.
    // aParEntLY thEy nEed tO kNoW tHe sIZe aT cOMpiLe tIMe
    vector<double> data_set(size_of_data_set);
    vector<double> histogram(number_of_intervals);

    for (int i = 0; i < size_of_data_set; i++) {
        cin >> temp_value;

        if (largest_number < temp_value) {
            largest_number = temp_value;

        }
        if (0 <= temp_value) {
            data_set[i] = temp_value;

        }
    
    }

    length_of_intervals = ceil(double(largest_number)/number_of_intervals);

    for (int i = 0; i < size_of_data_set; i++) {

        if (data_set[i] == largest_number && largest_number % number_of_intervals == 0) {
            // this is the edge-case which was mentioned in the exercise
            // if the largest number is divisible by the number of intervalls
            // then it will fall out of scope for our Vector,
            // but we know it should be added to the very last interval
            histogram[number_of_intervals - 1]++;

        } else {
            // flooring the number in the data_set (divied by the length of the intervals)
            // tells us which interval it belongs to and thus we can 
            // increment the corresponding interval in our histogram
            int index_to_increment = floor(double(data_set[i])/length_of_intervals);

            histogram[index_to_increment]++;

        }

    }

    for (int i = 0; i < number_of_intervals; i++) {
        // finally a for-loop to print our findings
        cout << i*length_of_intervals << ": " << histogram[i] << endl;

    }

    return 0;
}