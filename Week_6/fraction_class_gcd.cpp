#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
    private:
        // Internal representation of a fraction as two integers
        int numerator;
        int denominator;

        // Simplifying our fraction
        void simplify() {
            // Using the built-in gcd function
            int for_division = gcd(numerator, denominator);
            numerator /= for_division;
            denominator /= for_division;
            
        }

    public:
        // void class cinstructor
        Fraction() {
            numerator = 0;
            denominator = 1;

        }
        // Class constructor
        Fraction(int n, int d) {
            numerator = n;
            denominator = d;

        }

        // Methods to update the fraction
        void add(Fraction f) {
            numerator = (numerator*f.denominator + f.numerator*denominator);
            denominator = denominator*f.denominator;
            simplify();
        }
        void mult(Fraction f) {
            numerator *= f.numerator;
            denominator *= f.denominator;
            simplify();
        }
        void div(Fraction f) {
            numerator *= f.denominator;
            denominator *= f.numerator;
            simplify();
        }

        // Display method
        void display() {
            cout << numerator << " / " << denominator << endl;

        }

};


int main() {
    // Declaring all the variables that we are gonna use for input
    int numerator_1{};
    string frac{};          // we just discard the frac, but we still need to find it
    int denominator_1{};
    string operation;
    int numerator_2{};
    int denominator_2{};

    // Then we declare the two fractions that we are gonna perform operations on.
    Fraction frac_1{};
    Fraction frac_2{};

    // Getting the input and handling it
    while(true) {
        // Check whether the first input fails
        cin >> numerator_1;
        if (cin.fail()) {
            break;
        }

        // If the first input doens't fail, we just expect all of it to be present.
        cin >> frac >> denominator_1  >> operation >> numerator_2 >> frac >> denominator_2;
        frac_1 = Fraction(numerator_1, denominator_1);
        frac_2 = Fraction(numerator_2, denominator_2);

        if (operation == "+") {
            frac_1.add(frac_2);
            frac_1.display();

        } else if (operation == "*") {
            frac_1.mult(frac_2);
            frac_1.display();

        } else if (operation == "div") {
            frac_1.div(frac_2);
            frac_1.display();

        } else {
            // illegal operation
            cout << "Ya done goofed BYOAH!" << endl;
            return 0;

        }
    }

    return 0;
}