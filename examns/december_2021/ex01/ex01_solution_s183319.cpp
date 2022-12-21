#include <iostream>
#include "ex01_library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n) {
    Square ** chessboard = new Square*[n];

    for (unsigned int i = 0; i < n; i++) {
        // Allocating memory for the pointer at index i
        chessboard[i] = new Square[n];

        for (unsigned int j = 0; j < n; j++) {
            // overwritting values of chessboard
            chessboard[i][j].piece = none;
            chessboard[i][j].team = nobody;

        }
    }

    return chessboard;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (c[i][j].piece == none) {
                cout << "_ ";

            } else if (c[i][j].team == white) {
                if(c[i][j].piece == rook) {
                    cout << "r ";

                } else if (c[i][j].piece == bishop) {
                    cout << "b ";

                }
            } else if (c[i][j].team == black) {
                if(c[i][j].piece == rook) {
                    cout << "R ";

                } else if (c[i][j].piece == bishop) {
                    cout << "B ";

                }
            }
        }
        cout << endl;

    }

}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n,
          int r1, int c1, int r2, int c2) {
    // Invalid case
    if (c[r1][c1].team == c[r2][c2].team) {
        // Positions occupied by same team
        return false;

    } else if (r1 == r2 && c1 == c2) {
        // The positions are the same, hence the piece isn't moved
        return false;

    } else if (c[r1][c1].piece == none) {
        // There is no piece at the starting position
        return false;

    }

    // valid cases
    if (c[r1][c1].piece == rook) {
        if (r1 == r2 || c1 == c2) {
            // We know that we are looking at a rook piece,
            // hence we can just assign the new square to "rook"
            c[r2][c2].piece = rook;
            c[r2][c2].team = c[r1][c1].team;

            c[r1][c1].piece = none;
            c[r1][c1].team = nobody;

            return true;

        } else {
            return false;

        }
    } else if (c[r1][c1].piece == bishop) {
        // using the fancy hint from the exercise
        if (abs(r1 - r2) == abs(c1 - c2)) {
            // We know that we are looking at a rook bishop,
            // hence we can just assign the new square to "bishop"
            c[r2][c2].piece = bishop;
            c[r2][c2].team = c[r1][c1].team;

            c[r1][c1].piece = none;
            c[r1][c1].team = nobody;

            return true;

        } else {
            return false;

        }

    }

    // Probably unnecessary
    return false;

}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n,
                int row, int col) {
    // Starts by checking whether there even is a piece at the
    // given position.
    if (c[row][col].piece == none) {
        return false;

    }

    // Assigning the team, such that we can check whether they
    // are opposing teams
    Team org_team = c[row][col].team;

    // I think the only valid solution is in O(n * n)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == row || j == col) {
                if (c[i][j].team != org_team && c[i][j].piece == rook) {
                    // in this case the piece is in fact threatened by a rook
                    return true;

                }
                
            } else if (abs(i - row) == abs(j - col)) {
                if (c[i][j].team != org_team && c[i][j].piece == bishop) {
                    // in this case the piece is in fact threatened by a bishop
                    return true;

                }
            }
        }
    }

    return false;
    
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        delete[] c[i];
    }
    delete[] c;
}
