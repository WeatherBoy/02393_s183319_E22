#include <iostream>
using namespace std;

// Classes are named by the convention of
// <ClassName>
class AdressBook {
    public:
        // declare all the fields we need (as public)
        bool initialized;
        string firstName;
        string middleName;
        string lastName;
        string phoneNumber;
        string streetAdress;
        string houseNumber;
        string zipCode;
        string region;

        AdressBook() {
            // this is an initializer (constructor) of the class
            // when it is created without any input.
            // Constructors in c++ has to have the same name as the
            // class itself.

            // Fields are named by the convention
            // <memberVariable>
            initialized = false;
            firstName = "";
            middleName = "";
            lastName = "";
            phoneNumber = "";
            streetAdress = "";
            houseNumber = "";
            zipCode = "";
            region = "";
        }

        void clean() {
            // a function to clean all the information from our class
            initialized = false;
            firstName = "";
            middleName = "";
            lastName = "";
            phoneNumber = "";
            streetAdress = "";
            houseNumber = "";
            zipCode = "";
            region = "";
        }

        string toString() {
            // a function that makes our weird class nice for the output
            // stream
            return firstName + "," + middleName + "," +
                    lastName + "," + phoneNumber + "," +
                    streetAdress + "," + houseNumber + "," +
                    zipCode + "," + region;
        }
};

void eatAdressBookInput() {
    string tmp;

    cin >> tmp; //0
    cin >> tmp; //1
    cin >> tmp; //2
    cin >> tmp; //3
    cin >> tmp; //4
    cin >> tmp; //5
    cin >> tmp; //6
    cin >> tmp; //7

}

int main() {
    // variables are written by the naming convention
    // <variable_name>
    AdressBook the_book[50];
    string command;
    int adress;

    cin >> command;

    while (command != "quit") {
        if (command == "add") {
            cin >> adress;

            if (1 <= adress && adress <= 50) {
                // if the adress is within the valid range
                adress--;       // adress needs to be decremented to fit exercise adressing

                if (! the_book[adress].initialized) {
                    // if this adress wasn't already initialized
                    the_book[adress].initialized = true; // super scuffed solution

                    cin >> the_book[adress].firstName;      //0
                    cin >> the_book[adress].middleName;     //1
                    cin >> the_book[adress].lastName;       //2
                    cin >> the_book[adress].phoneNumber;    //3
                    cin >> the_book[adress].streetAdress;   //4
                    cin >> the_book[adress].houseNumber;    //5
                    cin >> the_book[adress].zipCode;        //6
                    cin >> the_book[adress].region;         //7

                } else {
                    // Otherwise eat the input
                    eatAdressBookInput();
                } 
            } else {
                // Otherwise eat the input
                eatAdressBookInput();

            }
        } else if (command == "clr") {
            cin >> adress;

            if (1 <= adress && adress <= 50) {
                adress--;       // adress needs to be decremented to fit exercise adressing
                the_book[adress].clean();

            }
        } else if (command == "qry") {
            cin >> adress;

            if (1 <= adress && adress <= 50) {
                adress--;       // adress needs to be decremented to fit exercise adressing

                if (the_book[adress].initialized) {
                    cout << the_book[adress].toString() << endl;

                } 
            }
        } 

        cin >> command; 
    }

    return 0;
}