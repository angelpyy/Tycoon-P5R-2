//
//  Player.hpp
//  tycoon-reset
//
//  Created by Angel Gutierrez on 8/5/21.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#include "Card.hpp"
class Card;

class Player {
private:
    // each player will have a hand of cards, points to keep track of wins, and a way to check whether theyre still in the game.
    vector<Card> current_hand {};
    string rclass;
    int points;
    bool in_game;
    
public:

    // default constructor
    Player();

    // print every card on the player
    void show_hand();
    
    // print card based off index
    void show_card(int c);
    
    // game init functions
    void add_card(Card c);
    bool three_of_diamond();
    void sort_hand();
    
    // game and round progressions
    void add_points(int p);
    void set_class(string s);
    bool is_playing();
    void player_in_out();
    Card remove_card(int i);
    void remove_card(Card c);
    Card card_at_idx(int i);
    
    // show amount of cards a player has left
    int num_cards();
    
    // alternate functions all related to parsing player input
    // bool card_validation(string a, int &i);
    // Card remove_card(int index);
    // int val_at_idx(int index);
};


#endif /* Player_hpp */
