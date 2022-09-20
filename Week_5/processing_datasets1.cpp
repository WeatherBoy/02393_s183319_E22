#include <iostream>
#include <vector>
#include <algorithm>    // necessary for being able to sort our vector
using namespace std;

int main() {
    char input;
    int number_input;

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
        // cout << "While accesed" << endl;
        // First input we get should tell us the appropiate dataset.
        if (input == 'a') {
            dataset_a.push_back(number_input);
            
        } else if (input == 'b') {
            dataset_b.push_back(number_input);

        }

    }

    // Using the sort function as the exercise says
    sort(dataset_a.begin(), dataset_a.end());
    sort(dataset_b.begin(), dataset_b.end());

    for (unsigned int i = 0; i < dataset_a.size(); i++) {
        // Printing the output of the now sorted dataset_a
        cout << dataset_a[i] << " ";

    }

    for (unsigned int i = 0; i < dataset_b.size(); i++) {
        // Printing the output of the now sorted dataset_b
        cout << dataset_b[i] << " ";
        
    }

    return 0;
}