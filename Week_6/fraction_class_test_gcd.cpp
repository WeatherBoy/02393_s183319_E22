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
        void display(void) {
            cout << numerator << "/" << denominator << endl;

        }

};


int main() {
    // simple test
    int numerator_1{};
    int numerator_2{};
    int denominator_1{};
    int denominator_2{};

    cin >> numerator_1 >> denominator_1 >> numerator_2 >> denominator_2;
    Fraction first_frac = Fraction(numerator_1, denominator_1);
    Fraction second_frac = Fraction(numerator_2, denominator_2);

    first_frac.add(second_frac);
    cout << "addition: ";
    first_frac.display();

    cout << endl << "multiplication: ";
    first_frac = Fraction(numerator_1, denominator_1);
    first_frac.mult(second_frac);
    first_frac.display();

    cout << endl << "division: ";
    first_frac = Fraction(numerator_1, denominator_1);
    first_frac.div(second_frac);
    first_frac.display();

    return 0;
}