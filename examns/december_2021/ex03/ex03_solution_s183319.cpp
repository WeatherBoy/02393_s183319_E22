#include <iostream>
#include "ex03_library.h"
using namespace std;

// Do not modify
Hotel::Hotel() {
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::addRoom(string name) {
    // find returns the end of an iterator if it doesn't find the value (third parameter)
    if(find(this->roomNames.begin(), this->roomNames.end(), name) == this->roomNames.end()) {
        this->roomNames.push_back(name);

    }
}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId) {

    if(find(this->roomNames.begin(), this->roomNames.end(), roomName) != this->roomNames.end()) {
        // First we check that the roomName does occur in roomNames, we do this by seeing
        // that the find() function does not return the last index of roomNames.
        if (this->roomOccupancy.find(roomName) == this->roomOccupancy.end()) {
            // Then we check that roomName isn't occupied, we do this by making sure
            // that roomName doesn't occur in roomOccupancy

            bool guest_absent = true;
            for(auto elem: this->roomOccupancy) {
                // for(auto <elem>: <list>) is just a for-each loop
                //
                // We go through every single pair in roomOccupancy and check whether
                // any of the ids are equal to guestId, if it is then we say that the
                // guest isn't abscent and break the loop.
                if (elem.second.id == guestId) {
                    guest_absent = false;
                    break;
                } 
            }

            if (guest_absent) {
                // If the guest is abscent from the hotel, then we can book them into
                // the hotel
                this->roomOccupancy[roomName] = {guestName, guestId};

            }
        }
    }
}

/*
* NOTE:
* Get back to this
*/
// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId) {
    
    for(auto room_name : this->roomNames) {
        // Going through the loop once and checking loads of conditionals

        // Creating a temporary variable, because it makes naming easier
        Guest temp_guest = this->roomOccupancy[room_name];

        if (guestName == "*" && guestId == "*") {
            if (this->roomOccupancy.find(room_name) != this->roomOccupancy.end()) {
                // if the room name is in roomOccupancy, then we print it
                cout << room_name << endl;

            }
            
        } else if (guestId == "*") {
            if (temp_guest.name == guestName) {
                // Here we check that the name is equal to guestName
                cout << room_name << endl;

            }
        } else if (guestName == "*") {
            if (temp_guest.id == guestId) {
                cout << room_name << endl;
            }
        } else {
            if (temp_guest.name == guestName && temp_guest.id == guestId) {
                // Here we check that the name is equal to guestName
                cout << room_name << endl;

                // There should be no further occurences of both guestName
                // and guestId so we can freely break.
                break;
            }
        }
    }         
}

// Do not modify
void Hotel::display() {
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++) {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end()) {
            cout << "empty" << endl;
        } else {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}
