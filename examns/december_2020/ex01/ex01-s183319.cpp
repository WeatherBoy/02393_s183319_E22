#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c) {
    Complex ** complex_mat = new Complex*[m];

    for (unsigned int i = 0; i < m; i++) {
        // Allocating memory for the pointer at index i
        complex_mat[i] = new Complex[n];

        for (unsigned int j = 0; j < n; j++) {
            // overwritting values of chessboard
            complex_mat[i][j].re = c.re;
            complex_mat[i][j].im = c.im;

        }
    }

    return complex_mat;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n) {
    for(unsigned int i = 0; i < m; i++) {
        for(unsigned int j = 0; j < (n - 1); j++) {
            // real part
            cout << A[i][j].re;

            // imaginary part
            if (A[i][j].im >= 0) {
                cout << "+";
            }
            cout << A[i][j].im << "i ";

        }
        // Fence-posting
        // real part
        cout << A[i][(n-1)].re;

        // imaginary part
        if (A[i][(n-1)].im >= 0) {
            cout << "+";
        }
        cout << A[i][(n-1)].im << "i" << endl;
    }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n) {
    // Same time complexity as if I had done it by using
    // createMatrix, however this is faster (although not noticably)
    Complex **A = new Complex*[n];

    for (unsigned int i = 0; i < n; i++) {
        A[i] = new Complex[n];
        for (unsigned int j = 0; j < n; j++) {
            if (i == j) {
                A[i][j] = {1, 0};
            } else {
                A[i][j] = {0, 0};
            }
            
        }
    }
    return A;
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p) {

    // Looping over our C-matrix
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < p; j++) {
            // Creating a temporary value to find the matrix-matrix
            // product.
            Complex temp = {0, 0};
            for (unsigned int k = 0; k < n; k++) {
                // Finding the value of temp based on the formula
                // given in the exercise.
                temp = add(temp, mult(A[i][k], B[k][j]));

            }
            C[i][j] = temp;

        }
    }
}

// Do not modify
Complex add(Complex c, Complex d) {
    Complex result = { c.re + d.re, c.im + d.im };
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d) {
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; i++) { delete[] A[i]; }
    delete[] A;
}
