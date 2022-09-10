#include <iostream>
using namespace std;

int main() {
    int n;
    double tempVal;
    double sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tempVal;
        sum += tempVal;
    }

    cout << sum << endl;

    return 0;
}