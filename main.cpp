//
//  main.cpp
//  tycoon-reset
//
//  Created by Angel Gutierrez on 8/5/21.
//

#include <iostream>

#include "Card.hpp"
#include "Player.hpp"
#include "Tycoon.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Tycoon game;
    game.init_game();                                                     // now get the round(s) started
                                                                          // one game, three rounds, undefined num of turns
    // while (true) {
        while (game.currently_playing() > 1) {                            // so long as there are at least 2 people playing continue
            while (game.turn) {                                           // this loop will simulate each "turn" in tycoon
                game.enter_switch();
                
                if (!game.cont_turn()) {                                  // end the turn if last player (person who last played) ==
                    game.clear_pile();                                    // current player implying a whole loop has occured
                    break;
                }
            }
            game.clear_pile();
            cout << "you've broken out of the turn loop which should never happen rn lol actually yeah it should\n\n";
        }
    // }
}
