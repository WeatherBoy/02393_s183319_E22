#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Tile **createCavern(unsigned int m, unsigned int n) {
    // same old
    Tile ** cavern = new Tile*[m];

    for (unsigned int i = 0; i < m; i++) {
        // Allocating memory for the pointer at index i
        cavern[i] = new Tile[n];

        for (unsigned int j = 0; j < n; j++) {
            // overwritting values of chessboard
            cavern[i][j].content = nothing;
            cavern[i][j].explored = false;

        }
    }

    return cavern;
}


string to_print_at_position(Content at_position, bool explored, bool within_distance) {
    if(within_distance) {
        // within distance, so we print in normal fashion
        if (at_position == nothing) {
            return " ";

        } else if (at_position == player) {
            return "X";

        } else if (at_position == rock) {
            return "#";

        } else if (at_position == wumpus) {
            return "W";

        } else {
            // hopefully this case won't happen
            // in any case it will be a noticable error
            return "@";
        }
    } else {
        // not within distance
        if (!explored) {
            // Not explored, we return a question mark
            return "?";

        } else {
            // then it has been explored, but it isn't within distance
            if (at_position == rock) {
                // explored rocks can always be seen
                return "#";

            } else {
                // what is in the dark is unkown to the player
                return "-";

            }
        }
    }

    // shouldn't occur, but an error just in case
    return "@";
}


// Task 1(b).  Implement this function
void revealCavern(Tile **cav, unsigned int m, unsigned int n) {

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            // for this example we are always within distance,
            // which means explored could technicly be anything
            cout << to_print_at_position(cav[i][j].content, cav[i][j].explored, true);

        }
        cout << endl;
    }
}


double calc_dist(int x1, int y1, int x2, int y2) {
    // calculating the distance between two points (x1, y1) and (x2, y2)
    int dis_1 = x1 - x2;
    int dis_2 = y1 - y2;
    return sqrt(dis_1*dis_1 + dis_2*dis_2);

}


// Task 1(c).  Implement this function
bool movePlayer(Tile **cav, int m, int n, int r, int c) {
    // For more easily read code
    int const max_distance = 5;
    bool player_found = false;
    int player_pos_r = 0;
    int player_pos_c = 0;

    // searching for player
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (cav[i][j].content == player) {
                // we found the player
                player_found = true;
                player_pos_r = i;
                player_pos_c = j;
                break;
            }
        }
    }

    if(player_found) {
        if (0 <= r && r < m && 0 <= c && c < n) {
            // target is within cavern
            if (calc_dist(player_pos_r, player_pos_c, r, c) < max_distance) {
                if (cav[r][c].content == nothing) {
                    // there is nothing at the position we are targeting
                    cav[player_pos_r][player_pos_c].content = nothing;
                    cav[r][c].content = player;

                    return true;

                } else if (cav[r][c].content == player) {
                    // if the player is at target position then we don't update the cavern...
                    //
                    // Honestly an unnecessary conditional considering if we had just used a
                    // disjunction in the above, then the same outcome would have been
                    // achieved, yet I deemed this more readable code.
                    return true;
                }
            }
        }

    }

    // not all conditions were met, then we must return false and not update cavern
    return false;
}


// Task 1(d).  Implement this function
void drawCavern(Tile **cav, unsigned int m, unsigned int n) {
    // For more easily read code
    int const max_distance = 4;
    bool player_found = false;
    int player_pos_r = 0;
    int player_pos_c = 0;
    bool within_distance = false;

    // searching for player
    //
    // This could probably have been a function, but I am not comfortable 
    // enough with functions returning multiple parameters in c++, for
    // me to begin implementing it at an exam.
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (cav[i][j].content == player) {
                // we found the player
                player_found = true;
                player_pos_r = i;
                player_pos_c = j;
                break;
            }
        }
    }

    // now drawing the cave
    //
    // I realize now this could have been a function on its own called by both
    // drawCavern() as well as realCavern()... oh, well
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            // figuring out whether we are within distance and updating explored
            within_distance = (calc_dist(player_pos_r, player_pos_c, i, j) < max_distance) ? true : false;
            
            // the explored status at position (i, j) is based on whether it is currently within distance
            // or it had already been explored
            cav[i][j].explored = (within_distance || cav[i][j].explored)  ? true : false;

            // printing based on distance and exploration
            cout << to_print_at_position(cav[i][j].content, cav[i][j].explored, within_distance);

        }
        cout << endl;
    }
}


// Do not modify the following function.
// This code (that you don't need to read) places the player
// at location (0,0) and pseudo-randomly places some rocks
// and a Wumpus. The pseudo-random placement depends on the
// value of 'seed'.
void setupCavern(Tile **cav, unsigned int m, unsigned int n,
                 unsigned int seed) {
    mt19937 e; // Pseudo-random number generator
    e.seed(seed);

    // 1/3rd of the tiles are rocks
    unsigned int rocks = (m * n) / 3;
    for (unsigned int i = 0; i < rocks; i++) {
        cav[e()%m][e()%n].content = rock;
    }

    // We never place the Wumpus on row 0 or column 0
    unsigned int row = (e() % (m-1)) + 1;
    unsigned int col = (e() % (n-1)) + 1;
    cav[row][col].content = wumpus;

    cav[0][0].content = player;
}

// Do not modify the following function.
void deleteCavern(Tile **c, unsigned int m) {
    for (unsigned int i = 0; i < m; i++) {
        delete[] c[i];
    }
    delete[] c;
}
