#include <iostream>
#include <math.h>
using namespace std;

int levenshtein_distance(string word_1, string word_2) {
    // Defining the lengths because we are gonna be
    // using these A LOT..
    int word_1_n = word_1.length();
    int word_2_n = word_2.length();

    // Checking the first two conditionals
    if (word_1_n == 0) {
        return word_2_n;

    } else if (word_2_n == 0) {
        return word_1_n;

    }

    // Also gonna be using these A LOT..
    string word_1_suffix = word_1.substr(1);
    string word_2_suffix = word_2.substr(1);

    // Trying to create some more easily read code.
    // Where each part is an expression in the minimum function as, described
    // in the exercise describtion. 
    int part_1 = levenshtein_distance(word_1_suffix, word_2) + 1;
    int part_2 = levenshtein_distance(word_1, word_2_suffix) + 1;
    int part_3 = levenshtein_distance(word_1_suffix, word_2_suffix) + (word_1[0] == word_2[0] ? 0 : 1);

    return min(min(part_1, part_2), part_3);

}

int main() {
    // Initializing our two words whcih we need to find
    // the distance of.
    string word_1{};
    string word_2{};

    // Getting our two words
    cin >> word_1 >> word_2;

    cout << levenshtein_distance(word_1, word_2) << endl;

    return 0;
}