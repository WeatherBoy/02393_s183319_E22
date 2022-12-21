#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

// Exercise 3(a)
Dictionary::Dictionary(void){
    // Put your code here
}

// Exercise 3(b)
// Check and correct if necessary
void Dictionary::insert_words(string u, string v){
    words[0][u] = v;
}

// Exercise 3(b)
// Check and correct if necessary
string Dictionary::get_word(int lang, string u){
    return words[lang][u];
}

// Exercise 3(c)
void Dictionary::insert_synonym(int lang, string u,
                                     string v){
    // Put your code here
}

// Exercise 3(d)
set<string> Dictionary::get_synonyms(int lang, string u){
    // Put your code here
}

// Exercise 3(e)
set<string> Dictionary::translate(int lang, string u){
    // Put your code here
}

