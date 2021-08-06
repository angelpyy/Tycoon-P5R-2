//
//  Player.cpp
//  tycoon-reset
//
//  Created by Angel Gutierrez on 8/5/21.
//

#include "Player.hpp"

Player::Player() {
    this->current_hand.clear();
    this->points = 0;
    this->rclass = "commoner";
    this->in_game = true;
}

void Player::show_hand() {
    // int arrSize = current_hand.size();
    int j = 1;
    for (auto i = current_hand.begin(); i != current_hand.end(); i++) {
        cout << j << " -- ";
        i->print_info();
        j++;
    }
}

void Player::add_card(Card c) {
    this->current_hand.push_back(c);
}

bool Player::three_of_diamond() {
    for (int i = 0; i < current_hand.size(); i++) {
        if (current_hand[i].get_suit() == "Diamonds" && current_hand[i].get_num() == 3) {
            return true;
        }
    }

    return false;
}

void Player::sort_hand() {
    sort(current_hand.begin(), current_hand.end());
}

void Player::add_points(int p) {
    this->points += p;
}

void Player::set_class(string s) {
    this->rclass = s;
}

bool Player::is_playing() {
    if (this->num_cards() == 0 && this->in_game) {
        this->player_in_out();
    }
    
    return in_game;
}

void Player::player_in_out() {
    this->in_game = !this->in_game;
}

int Player::num_cards() {
    return current_hand.size();
}

void Player::show_card(int c) {
    current_hand[c].print_info();
}

Card Player::remove_card(int i) {
    Card temp = current_hand[i];
    current_hand.erase(current_hand.begin() + i);
    return temp;
}

Card Player::card_at_idx(int i) {
    return current_hand[i];
}

void Player::remove_card(Card c) {
    for (int i = 0; i < current_hand.size(); i++) {
        if (current_hand[i] == c) {
            current_hand.erase(current_hand.begin() + i);
        }
    }
}
