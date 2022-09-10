// We need to read a positive integer and write out its prime factorization

#include <iostream>
using namespace std;

int main() {
    int toBeFactorized;
    int timesFactorized = 0;
    int counter = 2;


    cin >> toBeFactorized;

    while (toBeFactorized > 1) {
        if (toBeFactorized % counter == 0) {
            if (timesFactorized == 0) {
                cout << counter;
            } else {
                cout << " * " << counter;
            }
            toBeFactorized /= counter;
            timesFactorized++;
        } else {
            counter++;
        }
    }

    cout << endl;

    return 0;

}