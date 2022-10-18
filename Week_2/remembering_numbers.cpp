#include <iostream>
using namespace std;

int main() {
    int input;
    int const how_many_numbies = 1000;
    int memory[how_many_numbies] = {};
    
    cin >> input;
    while (input != 0) {
        
        cout <<  memory[input - 1] << endl;
        memory[input - 1]++;
        cin >> input;
    }

    return 0;
}