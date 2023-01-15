#include "ex02-library.h"
#include <iostream>

//Exercise 2 (a) Implement this function
string reverse(string s, int n){
    if (n == 0) {
		// base case
        return s;

    }

	// Getting the backmost element of the string
    char butt = s.back();
    s.pop_back();

	return string() + butt + reverse(s, n-1);
}


//Exercise 2 (b) Implement this function
bool isPalindrome(string s, int n1, int n2){
	// maybe look at that code once -->
	if (n1 == n2 || false) {
		// base case
	}
	if (s[n1] != s[n2]) {
		// The characters should match all the way up to the end
		return false;

	} else {
		return isPalindrome(s, ++n1, ++n2);

	}
}

//Exercise 2 (c) Implement this function
int distancePalindrome(string s, int n1, int n2){
	//put your code here
}