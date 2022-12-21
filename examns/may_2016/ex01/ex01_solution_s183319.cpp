#include <iostream>
#include <vector>
#include "ex01_library.h"

using namespace std;

// Exercise 1 (a)
// Check and correct if necessary
/*
* Should start at zero index
*/
void display(double *A, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            cout << A[i*n+j] << " ";
        }
        cout << endl;
    }
}

// Exercise 1 (b)
// Implement this function
/*
* Fairly straightforward
*/
void reset(double *A, unsigned int n, double x){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            A[i*n+j] = x;
        }
    }
}

// Exercise 1 (c)
// Implement this function
/*
* This was truly tedious, tedious, lemon-tedious.
*/
void reduce(double * A, unsigned int n){
    // Creating the new matrix, such that A isn't overwritten in runtime
    // which would yield the wrong values:
    double * B = new double[n*n];
    // Maybe easier, I don't know
    int last_indx = n-1;

    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            if(i == 0 && j == 0) {
                // Upper left-hand corner
                B[0] = A[1] + A[last_indx + 1];

            } else if(i == 0 && j == last_indx) {
                // Upper right-hand corner
                B[i*n + j] = A[last_indx - 1] + A[last_indx + last_indx];

            } else if(i == last_indx && j == 0) {
                // lower left-hand corner
                B[i*n + j] = A[last_indx*(n-1)] + A[last_indx*n + 1];

            } else if(i == last_indx && j == last_indx) {
                // lower right-hand corner
                B[i*n + j] = A[last_indx*n + last_indx] + A[last_indx*(n-1) + last_indx*n + last_indx];

            } else if(i == 0) {
                // In the first row
                B[i*n + j] = A[i*n + j - 1] + A[i*n + j + 1] + A[(i + 1)*n + j];

            } else if(j == 0) {
                // In the first column
                B[i*n + j] = A[(i - 1)*n + j] + A[(i + 1)*n + j] + A[i*n + (j + 1)];

            } else if(i == last_indx) {
                // Last row
                B[i*n + j] = A[i*n + (j - 1)] + A[i*n + (j+1)] + A[(i - 1)*n + j];

            } else if(j == last_indx) {
                // last column
                B[i*n + j] = A[(i - 1)*n + j] + A[(i + 1)*n + j] + A[i*n + (j - 1)];

            } else {
                // standard case
                B[i*n + j] = A[(i - 1)*n + j] + A[(i + 1)*n + j] + A[i*n + (j - 1)] + A[i*n + (j + 1)];

            }
            
        }
    }

    /*
    * Overwriting A to be equal to B
    */
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            A[i*n + j] = B[i*n + j];

        }
    }
    
}

// Exercise 1 (d)
// Implement this function
vector<double> sumRows(double * A, unsigned int n){
    
    // Put your code here
    
}

// Exercise 1 (e)
// Implement this function
vector<double> sumCols(double * A, unsigned int n){
    
    // Put your code here
    
}

// Do not modify
void print(vector<double> & v){
    for(unsigned int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}