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

void yooo(Tycoon game);

int main(int argc, const char * argv[]) {
    // insert code here...
    Tycoon game;
    game.init_game();                                                     // now get the round(s) started
    
    yooo(game);
    yooo(game);
    yooo(game);
    
    /*                                                                    // one game, three rounds, undefined num of turns
    while (true) {                                                        // so long as there are at least 2 people playing continue
        while (game.currently_playing() > 1) {                            // this loop will simulate each "turn" in tycoon
            if (game.cur_player().is_playing()) {
                game.enter_switch();
            }
            game.current_player = (game.current_player + 1) % 4;
            if (!game.cont_turn()) { break; }                             // end the turn if last player (person who last played)
        }
        game.clear_pile();
        cout << "new turn start\n\n";
    }
     */
}

void yooo(Tycoon game) {
    while (true) {                                                        // so long as there are at least 2 people playing continue
        while (game.currently_playing() > 1) {                            // this loop will simulate each "turn" in tycoon
            if (game.cur_player().is_playing()) {
                game.enter_switch();
            }
            game.current_player = (game.current_player + 1) % 4;
            if (!game.cont_turn()) { break; }                             // end the turn if last player (person who last played)
        }
        game.clear_pile();
        cout << "new turn start\n\n";
    }
}
