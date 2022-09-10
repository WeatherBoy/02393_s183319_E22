// Use Leibniz formula
#include <iostream>
#include <math.h>
using namespace std;

double pi(int n) {
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += pow(-1, i)* (1 / ( (2.0 * i) + 1.0));
    }
    
    return sum * 4.0;
}

int main() {
    int n;

    cin >> n;
    cout << pi(n) << endl;

    return 0;

}