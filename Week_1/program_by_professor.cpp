#include <iostream>
using namespace std;

int runOperation(string op) {
    if (op == "add") {
        // TODO
        return 0; // Success
    } else {
        cout << "Oops! I don't understand" << op << endl;
        return 1; // Non-zero means failure
    }
}

int main() {
    int exitCode;

    cout << "Hej 02393!" << endl << "I am your program" << endl;

    cout << "What operation would you like to perform?" << endl;
    cout << "The available options  are: add" << endl;

    string op; // declare variable op
    cin >> op;

    exitCode = runOperation(op);

    return exitCode; // Success!
}