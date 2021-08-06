//
//  Card.cpp
//  tycoon reset
//
//  Created by Angel Gutierrez on 8/5/21.
//

#include "Card.hpp"
using namespace std;

Card::Card(string suit, int num, int value, bool special) {
    this->suit = suit;
    this->num = num;
    this->value = value;
    this->special = special;
    this->id = to_string(num) + suit[0];
}

Card::Card() {
    this->suit = "temp";
    this->num = 0;
    this->value = 0;
    this->special = true;
    this->id = "temp";
}

bool Card::operator<(const Card &rhs) const {
    return this->value < rhs.value;
}

bool Card::operator==(const Card &rhs) const {
    if (num == rhs.num
        && suit == rhs.suit
        && value == rhs.value) {
        return true;
    }
    return false;
}

void Card::print_info() {
    cout << "Card: " << num << " of " << suit << endl; // " and value of " << value << endl;
}

string Card::get_id() {
    return id;
}

string Card::get_suit() {
    return this->suit;
}

int Card::get_num() {
    return this->num;
}

int Card::get_value() {
    return this->value;
}

bool Card::is_special() {
    return this->special;
}


