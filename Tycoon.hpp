//
//  Tycoon.hpp
//  tycoon-reset
//
//  Created by Angel Gutierrez on 8/5/21.
//

#ifndef Tycoon_hpp
#define Tycoon_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <random>
#include<iostream>
using namespace std;

#include "Player.hpp"
#include "Card.hpp"


class Tycoon {
private:
    // "dealer" and players
    vector<Card> deck;
    vector<Player> players;
    
    // card/s currently at top of play (bc u can play 1-4 cards at a time)
    vector<Card> pile_cards;
    
    // game and statistic tracking
    int round = 0;
    int points[4] {30, 20, 10, 0};
    
public:
    // keep track of whos turn it would be currently
    int current_player;
    int last_player;
    
    // game turns
    bool turn = true;
    
    // game startup functions all called in one
    void init_game();
    
        // game startup
        void init_deck();
        void init_players();
        void shuffle_deck();
        void assign_player_hands();
        int locate_three_diamond();

    
    // data tracking functions
    
        // general game
        void print_deck();
        int get_round();
        int currently_playing();
    
        // player based
        void print_player_hands();
        void current_phand();
        int num_cards(int c);

    // misc functions kinda just do whatever
    void enter_switch();
    bool cont_turn();
    void clear_pile();
    bool play_cards();
    Player cur_player();
};

#endif /* Tycoon_hpp */
