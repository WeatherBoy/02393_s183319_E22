#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Implement this function
cell ** createAndInitBoard(int n){
	cell ** checkers_board = new cell*[n];

    for (unsigned int i = 0; i < n; i++) {
        // Allocating memory for the pointer at index i
        checkers_board[i] = new cell[n];

        for (unsigned int j = 0; j < n; j++) {
            // overwritting values of chessboard

			checkers_board[i][j].color = computeColor(i, j);

			// One of the uglier and unecessarier ternaries in modern
			// programming historyu
            checkers_board[i][j].status = computeColor(i, j) == dark ?
										  (i <= 2 ? blackPiece : 
										  ((n - 3) <= i ? whitePiece : emptyC)) : emptyC;
        }
    }

    return checkers_board;
}


//Exercise 1 (b) Implement this function
cell ** duplicateBoard(cell ** A, int n){
	cell ** checkers_board = new cell*[n];

	for (unsigned int i = 0; i < n; i++) {
        // Allocating memory for the pointer at index i
        checkers_board[i] = new cell[n];

        for (unsigned int j = 0; j < n; j++) {
			checkers_board[i][j] = A[i][j];

		}
	}

	return checkers_board;
}


bool outsideBoard(int n, int r, int c) {
	// checking whether the given r or c is outside a board of
	// size n x n.
	return r < 0 || c < 0 || n <= r || n <= c;

}


//Exercise 1 (c) Implement this function
bool moveRight(cell ** A, int n, int r, int c){
	if (outsideBoard(n, r, c)) {
		// We aren't even on the board...
		return false;

	} else if (A[r][c].status == emptyC) {
		// there is no piece where we try to move it.
		return false;

	} else if (A[r][c].status == blackPiece) {
		// the case that it is a black piece we are trying to move

		if(A[r + 1][c - 1].status != emptyC) {
			// There is already a piece, where we are trying to
			// move our piece
			return false;

		} else if (outsideBoard(n, r + 1, c - 1)) {
			// we outside the board, yo!
			return false;

		} else {
			// we actually move the piece
			A[r + 1][c - 1].status = blackPiece;
			A[r][c].status = emptyC;

			return true;
		}

	} else if (A[r][c].status == whitePiece) {
		// the case that it is a black piece we are trying to move

		if(A[r - 1][c + 1].status != emptyC) {
			// There is already a piece, where we are trying to
			// move our piece
			return false;

		} else if (outsideBoard(n, r - 1, c + 1)) {
			// we outside the board, yo!
			return false;

		} else {
			// we actually move the piece
			A[r - 1][c + 1].status = whitePiece;
			A[r][c].status = emptyC;

			return true;
		}

	} 

	return false;
}


//Exercise 1 (d) Implement this function
bool moveLeft(cell ** A,int n,int r, int c){
	if (outsideBoard(n, r, c)) {
		// We aren't even on the board...
		return false;

	} else if (A[r][c].status == emptyC) {
		// there is no piece where we try to move it.
		return false;

	} else if (A[r][c].status == blackPiece) {
		// the case that it is a black piece we are trying to move

		if(A[r + 1][c + 1].status != emptyC) {
			// There is already a piece, where we are trying to
			// move our piece
			return false;

		} else if (outsideBoard(n, r + 1, c + 1)) {
			// we outside the board, yo!
			return false;

		} else {
			// we actually move the piece
			A[r + 1][c + 1].status = blackPiece;
			A[r][c].status = emptyC;

			return true;
		}

	} else if (A[r][c].status == whitePiece) {
		// the case that it is a black piece we are trying to move

		if(A[r - 1][c - 1].status != emptyC) {
			// There is already a piece, where we are trying to
			// move our piece
			return false;

		} else if (outsideBoard(n, r - 1, c - 1)) {
			// we outside the board, yo!
			return false;

		} else {
			// we actually move the piece
			A[r - 1][c - 1].status = whitePiece;
			A[r][c].status = emptyC;

			return true;
		}

	} 

	return false;
}


//Do not modify
cellColor computeColor(int r,int c){
	if((r%2 == 0 && c%2 == 0) || (r%2 != 0 && c%2 != 0)){
		return bright;
	}
	return dark;
}

//Do not modify
void printBoard(cell ** A, int n){
	cout << ' ';
	for(int c=0;c<n;c++){
		cout << c;
	}
	cout << endl;
	for(int r=0;r<n;r++){
		cout << r;
		for(int c=0;c<n;c++){
			//Print ' ' or '#' if empty, or the piece color (W or B)
			switch (A[r][c].status) {
			case emptyC:
				cout << ((A[r][c].color==bright)?' ':'#');
				break;
			case whitePiece:
				cout << "W";
				break;
			case blackPiece:
				cout << "B";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}
