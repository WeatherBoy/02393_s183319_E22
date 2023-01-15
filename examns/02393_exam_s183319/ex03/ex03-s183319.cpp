#include <iostream>
#include <algorithm>
#include "ex03-library.h"
using namespace std;

// Do not modify
Locker::Locker() {
    this->lockerIDs.push_back("LYNGBY01");
    this->lockerOccupancy["LYNGBY01"] = {"Alice", "Daisy", 1234};

    this->lockerIDs.push_back("LYNGBY02");
    this->lockerOccupancy["LYNGBY02"] = {"Claire", "Alice", 567};

    this->lockerIDs.push_back("LYNGBY03");
    this->lockerOccupancy["LYNGBY03"] = {"Daisy", "Bob", 890};

    this->lockerIDs.push_back("LYNGBY04");

    this->lockerIDs.push_back("LYNGBY05");
    this->lockerOccupancy["LYNGBY05"] = {"Bob", "Daisy", 159};

    this->lockerIDs.push_back("LYNGBY06");
}

// Task 3(a).  Implement this method
void Locker::putPackage(string lockerID, string sender, string recipient, int unlockCode) {
    if(find(this->lockerIDs.begin(), this->lockerIDs.end(), lockerID) != this->lockerIDs.end()) {
        // if lockerID IS in lockerIDs, then I should do something
        //
        // this is because, now we know that this locker exists, but we should also check whether
        // it is within the database, to make sure it isn't already occupied:

        if(this->lockerOccupancy.find(lockerID) == this->lockerOccupancy.end()) {
            // if lockerID does not exist within lockerOccupancy, then it isn't already occupied!
            // Hence it is available and should be updated:
            this->lockerOccupancy[lockerID] = {sender, recipient, unlockCode};

        }
    }

    // otherwise we do nothing...
    return;
}

// Task 3(b).  Implement this method
void Locker::retrievePackage(string lockerID, int unlockCode) {
    // As I understand we should delete only from lockerOccupancy, because we still
    // have the lockerID.. only difference is being that now it is available

    if(this->lockerOccupancy.find(lockerID) != this->lockerOccupancy.end()) {
        // If the locker is occupied
        if(this->lockerOccupancy[lockerID].unlockCode == unlockCode) {
            // and we have the correct code to unlock it
            //
            // basicly copy-pasted from the link provided in the exercise description
            lockerOccupancy.erase(lockerID);
        }
    }
}


// Task 3(c).  Implement this method
void Locker::findPackagesByRecipient(vector<string> recipients) {
    for(auto lockerID: this->lockerIDs) {
        if(this->lockerOccupancy.find(lockerID) != this->lockerOccupancy.end()) {
            // lockerID is present in lockerOccupancy
            for(auto recipient: recipients) {
                if(lockerOccupancy[lockerID].recipient == recipient) {
                    // We found a recepient matching the lockerID, so we print
                    // it to the terminal.
                    cout << lockerID << endl;

                    // We can in fact break here, because every maps key needs to
                    // be unique, hence there cannot be multiple recepients per
                    // lockerID.
                    break;
                }
            }
        }
    }
}

// Do not modify
void Locker::display() {
    for (auto it = this->lockerIDs.begin(); it != this->lockerIDs.end(); it++) {
        cout << "Locker '" << *it << "' ";
        if (this->lockerOccupancy.find(*it) == this->lockerOccupancy.end()) {
            cout << "is empty" << endl;
        } else {
            cout << "contains a package from " << this->lockerOccupancy[*it].sender;
            cout << " to " << this->lockerOccupancy[*it].recipient;
            cout << " (unlock code: " << this->lockerOccupancy[*it].unlockCode << ")" << endl;
        }
    }
}
