#include <iostream>
#include <vector>
using namespace std;

int main() {
    char input;
    int number_input;

    // Simply just variables for counting
    int numbers_printed_from_a = 0;
    int numbers_printed_from_b = 0;

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

    while(true) {
        // Is this good code?
        // ...no.
        // Should it work?
        // ...hopefully
        if (numbers_printed_from_a < dataset_a.size()) {
            // if we have printed fewer numbers then there are in dataset a,
            // then we can keep on printing, otherwise... no
            cout << dataset_a[numbers_printed_from_a] << " ";
            numbers_printed_from_a++;

        }
        if (numbers_printed_from_b < dataset_b.size()) {
            // if we have printed fewer numbers then there are in dataset b,
            // then we can keep on printing, otherwise... no
            cout << dataset_b[numbers_printed_from_b] << " ";
            numbers_printed_from_b++;

        }
        if (dataset_b.size() <= numbers_printed_from_b && dataset_a.size() <= numbers_printed_from_a) {
            break;

        }
    }

    return 0;
}