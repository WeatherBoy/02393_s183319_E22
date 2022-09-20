#include <iostream>
#include <vector>
using namespace std;

int main() {
    char input;
    int number_input;
    int smallest_array_size;

    // We should propaply initialize our dot product to zero.
    int dot_product = 0;

    // we have two vectors for our datasets
    vector<int> dataset_a{};
    vector<int> dataset_b{};

    // I do not know why, but we need to use the cin.fail() in this manner
    // it won't work with a local compiler, but for some reason it
    // works when uploaded to CodeJudge.
    // I added the check with the char 'q', just so that I could
    // exit on my own terms.
    while(true) {
        cin >> input;
        if (cin.fail() || input == 'q') {
            break;
        }
        cin >> number_input;
        if (cin.fail() || input == 'q') {
            break;
        }

        // First input we get should tell us the appropiate dataset.
        if (input == 'a') {
            dataset_a.push_back(number_input);
            
        } else if (input == 'b') {
            dataset_b.push_back(number_input);

        }

    }

    // Ternary operator - the syntax is luckily the exact same as in Java.
    smallest_array_size = dataset_a.size() < dataset_b.size() ? dataset_a.size() : dataset_b.size(); 

    // Since we can just treat the nonexisting indices as zero, we
    // can cut off our dot product at the size of the smallest array.
    for(unsigned int i = 0; i < smallest_array_size; ++i) {
        cout << "indedx: " << i << endl;
        dot_product += dataset_a[i]*dataset_b[i];

    }

    cout << dot_product << endl;

    

    return 0;
}