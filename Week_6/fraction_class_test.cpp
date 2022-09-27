#include <iostream>
using namespace std;

class Fraction {
    private:
        // Internal representation of a fraction as two integers
        int numerator;
        int denominator;

        // Simplifying our fraction
        void simplify() {
            // Not necessarily very pretty code. It could have been a lot better
            // with a list of the primes.
            //
            // We start with a counter at two (because it doesn't matter checking one),
            // and then we go through the whole numbers checking whether both our
            // numerator and denominator are divisible with the number, if it is the
            // case both are divied and hence simplified.
            // We do this as long as both numerator and denominator are smaller than
            // the counter which we are checking.
            unsigned int counter = 2;
            while(counter < numerator && counter < numerator) {
                if (numerator % counter == 0 && denominator % counter == 0) {
                    numerator /= counter;
                    denominator /= counter;
                    // If both were divisible we can reset the counter
                    counter = 1;

                }
                // Incrementing the counter at the of the while-loop.
                counter++;

            }
        }

    public:
        // Class constructor
        Fraction(int n, int d) {
            numerator = n;
            denominator = d;

        }

        // Methods to update the fraction
        void add(Fraction f) {
            numerator = (numerator*f.denominator + f.numerator*denominator);
            //cout << "numerator: " << numerator << endl;
            denominator = denominator*f.denominator;
            //cout << "denominator: " << denominator << endl;
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