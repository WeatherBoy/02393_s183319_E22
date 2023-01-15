#include <iostream>
#include "ex02-library.h"
using namespace std;

/*
* I am very puzzled as to why Result had a None... was there a point to it.
* Is there some edge-case I am missing, that will be harrowing for the
* result of this exam..?
*/

// Task 2(a).  Implement this function
void displayTeams(TournamentNode *t) {
    if (t == nullptr ) {
        // special case if t is nullptr, then we don't print
        // anything
        return;

    }

    if (t->nodeType == team ) {
        // we know that teams are leaf nodes, hence we can return
        // a base case here
        cout << t->name << endl;
        return;

    } else if (t->nodeType == match) {
        // hopefully this recursive implementation will work
        displayTeams(t->left);
        displayTeams(t->right);
        return;

    } else {
        // only god can help us here...
        cout << "Something wen't wrong... oh no!" << endl;
        return;

    }
}


// Task 2(b).  Implement this function
unsigned int matches(TournamentNode *t) {
    if (t == nullptr) {
        // speical case
        return 0;

    } else if (t->nodeType == match) {
        // match case
        return 1 + matches(t->left) + matches(t->right);

    } else if (t->nodeType == team) {
        // base case
        return 0;

    } else {
        // again... only the programming gods may be of aid here
        cout << "aargh, I am mad!" << endl;
        return 0;

    }
}


// Task 2(c).  Implement this function
string winner(TournamentNode *t) {
    if (t == nullptr) {
        // special case -- no winner
        return "";

    }
    if (t->nodeType == team) {
        // Here I assume, I have reached the base case.. i.e. the winner
        return t->name;

    }

    if (t->nodeType == match) {
        if (t->result == leftWin) {
            return winner(t->left);

        } else if (t->result == rightWin) {
            return winner(t->right);

        } else {
            // no winner, what!?
            return "";

        }
    }

    // Standard error I guess (but I would hope we never reached this return statement).
    return "";
}


// Task 2(d). Implement this function
bool wonAnyMatch(TournamentNode *t, string teamName) {
    if (t == nullptr) {
        // special case
        return false;

    }

    if (t->nodeType == team) {
        // base case:
        // We have sadly reached a leaf-node and must return false
        return false;
        
    }

    if (t->nodeType == match) {
        if (t->result == rightWin && t->right->name == teamName) {
            // The team won the right match
            return true;

        } else if (t->result == leftWin && t->left->name == teamName) {
            // the team won the left match
            return true;

        } else {
            return wonAnyMatch(t->right, teamName) || wonAnyMatch(t->left, teamName); 

        }
    }

    // we hopefully won't end up here, but just in case
    return false;
}