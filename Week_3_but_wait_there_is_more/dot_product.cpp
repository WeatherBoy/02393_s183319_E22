#include <iostream>
#include <vector>
using namespace std;

int main() {
    int length_of_vectors;
    double dot_product = 0;

    cin >> length_of_vectors;
    
    // We use the vector type because Hanse said
    // we couldn't use a list.
    // aParEntLY thEy nEed tO kNoW tHe sIZe aT cOMpiLe tIMe
    vector<double> vector1(length_of_vectors);
    vector<double> vector2(length_of_vectors);


    for (int i = 0; i < length_of_vectors; i++) {
            cin >> vector1[i];

    }
    for (int i = 0; i < length_of_vectors; i++) {
            cin >> vector2[i];

    }
    for (int i = 0; i < length_of_vectors; i++) {
            dot_product += vector1[i] * vector2[i];

    }

    cout << dot_product << endl;


    return 0;
}