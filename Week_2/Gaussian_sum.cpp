#include <iostream>
using namespace std;

int main() {
    int bigNum;
    int gaussianSum = 0;

    cin >> bigNum;
    for (int i = 1; i <= bigNum; i++) {
        gaussianSum += i;
    }

    cout << gaussianSum << endl;

    return 0;
}