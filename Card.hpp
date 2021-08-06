//
//  Card.hpp
//  tycoon-reset
//
//  Created by Angel Gutierrez on 8/5/21.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Card {
private:
    // properties every card should hold for easy identification and operations
    string id;
    string suit;
    int num;
    int value;
    bool special;
public:
    // constructor
    Card(string suit, int num, int value, bool special);
    Card();

    // operator overload for sort algorithm (as opposed to doing it myself bc lazy)
    bool operator<(const Card& rhs) const;
    bool operator==(const Card& rhs) const;
    
    // getter functions
    string get_suit();
    string get_id();
    int get_num();
    int get_value();
    bool is_special();
    
    // print all card info (for debugging making sure all data is working correctly)
    void print_info();

};

#endif /* Card_hpp */
