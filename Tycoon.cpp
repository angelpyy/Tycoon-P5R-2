//
//  Tycoon.cpp
//  tycoon-reset
//
//  Created by Angel Gutierrez on 8/5/21.
//

#include "Tycoon.hpp"

void Tycoon::init_deck() {
    // clear the deck to ensure there are no dupes
    this->deck.clear();

    for (int i = 0; i < 13; i++) {
        string suit = "Spades";
        int val = (11 + i) % 13;
        int num = i + 1;
        bool special = false;

        if (num == 8 || num == 3) {
            special = true;
        }

        Card temp(suit, num, val, special);
        this->deck.push_back(temp);
    }

    for (int i = 0; i < 13; i++) {
        string suit = "Diamonds";
        int val = (11 + i) % 13;
        int num = i + 1;
        bool special = false;

        if (num == 8 || num == 3) {
            special = true;
        }

        Card temp(suit, num, val, special);
        this->deck.push_back(temp);
    }

    for (int i = 0; i < 13; i++) {
        string suit = "Clubs";
        int val = (11 + i) % 13;
        int num = i + 1;
        bool special = false;

        if (num == 8) {
            special = true;
        }

        Card temp(suit, num, val, special);
        this->deck.push_back(temp);
    }

    for (int i = 0; i < 13; i++) {
        string suit = "Hearts";
        int val = (11 + i) % 13;
        int num = i + 1;
        bool special = false;

        if (num == 8) {
            special = true;
        }

        Card temp(suit, num, val, special);
        this->deck.push_back(temp);
    }
    
    // insert the joker cards which are used in the game
    Card jok1("Joker", 0, 13, true);
    Card jok2("Joker", 0, 13, true);

    this->deck.push_back(jok1);
    this->deck.push_back(jok2);
}

void Tycoon::init_players() {
    // create the player objects
    Player p1;
    Player p2;
    Player p3;
    Player p4;

    // assuming this adds them as {p1, p2, p3, p4}
    this->players.insert(this->players.end(), {p1, p2, p3, p4});
}
    
void Tycoon::shuffle_deck() {
    // randomize the set of cards
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(this->deck.begin(), this->deck.end(), default_random_engine(seed));
}

void Tycoon::assign_player_hands () {
    // grab random element, swap with the end, and remove from the end. alt is create a randomizer function which is betetr
    shuffle_deck();
    int count = 0;

    while (!this->deck.empty()) {
        this->players[count % 4].add_card(this->deck.back());
        this->deck.pop_back();

        count++;
    }
    
    for (auto i = players.begin(); i != players.end(); i++) {
        i->sort_hand();
    }

    
}

int Tycoon::locate_three_diamond() {
    // just return i????
    int index = 0;

    for (int i = 0; i < this->players.size(); i++) {
        if (this->players[i].three_of_diamond()) {
            return index;
        }
        index++;
    }

    cout << "if you're reading this there's been a mistake !!!\n";
    return -255;
}

void Tycoon::init_game() {
    init_deck();
    init_players();
    shuffle_deck();
    assign_player_hands();
    
    current_player = locate_three_diamond();
    last_player = -1;
}

void Tycoon::print_deck() {
    for (auto i = deck.begin(); i != deck.end(); i++) {
         i->print_info();
     }
     cout << endl << endl;
}

void Tycoon::print_player_hands() {
    // print out player hands to view initial state
        for (auto i = players.begin(); i != players.end(); i++) {
            // i->show_hand();
            // cout << endl;

            // after i've printed each hand sort it and print it to compare(as to avoid making another loop)
            i->sort_hand();
            i->show_hand();
            cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

        }

}

int Tycoon::get_round() {
    return round;
}

void Tycoon::current_phand() {
    players[current_player].show_hand();
}

int Tycoon::currently_playing() {
    int count = 0;
    
    for (int i = 0; i < 4; i++) {
        if (this->players[i].is_playing()) {
            count++;
        }
    }
    
    return count;
}

int Tycoon::num_cards(int c) {
    return this->players[c].num_cards();
}

void Tycoon::enter_switch() {
    int selection = -1;
    
    cout << endl;
    cout << "It is currently player " << current_player + 1 << "'s turn!\n";
    cout << "Select an Action:\n";
    cout << "1) Play Turn\n";
    cout << "2) View Hand\n";
    cout << "3) Check Enemy Hand Size\n";
    cout << "0) End Turn\n";
    cout << "-1) Quit Game\n\n";
    
    
    
    while (selection != 0) {
        cout << "select an action\n";
        cin >> selection;
        switch (selection) {
        case 1:
            if (play_cards()) {
                last_player = current_player;
                current_player = (current_player + 1) % 4;
                selection = 0;
                break;
            }
            cout << "bad card input, select new action\n\n";
            break;
        case 2:
            cout << endl;
            current_phand();
            cout << endl;
            break;
        case 3:
            cout << endl;
            cout << "Player " << (current_player + 1) % 4  + 1 << " has " << num_cards((current_player + 1) % 4) << " cards.\n";
            cout << "Player " << (current_player + 2) % 4  + 1 << " has " << num_cards((current_player + 2) % 4) << " cards.\n";
            cout << "Player " << (current_player + 3) % 4  + 1 << " has " << num_cards((current_player + 3) % 4) << " cards.\n";
            cout << endl;
            break;
        case 0:
            current_player = (current_player + 1) % 4;
            break;
        case -1:
            exit(0);
        default:
            cout << endl;
            cout << "Inavlid selection, womp womp.\n";
            cout << endl;
            break;
        }
    }
}

bool Tycoon::cont_turn() {
    if (last_player == current_player) {
        return !turn;
    }
    return turn;
    
}

void Tycoon::clear_pile() {
    pile_cards.clear();
    // pile_cards.push_back(Card());
}

bool Tycoon::play_cards() {
    int play_size;
    int play_idx[4] {-1, -1, -1, -1};
    
    if (pile_cards.size() == 0) {
        cout << endl << "how many cards would you like to play?? ? ?\n";
        while (true) {
            cin >> play_size;
            if (play_size < 5 && play_size > 0) { break; }
            cout << "Invalid amount of cards selected: try again\n";
        }
        
        cout << endl << "enter card number you'd like to play\n";
        cout << "ex -- enter 3 for ";
        players[current_player].show_card(2);
        cout << endl;
        
        for (int i = 0; i < play_size; i++) {
            cout << "enter number of " << "card " << i + 1 << endl;
            cin >> play_idx[i];
        }
        
        for (int j = 0; j < play_size; j++) {
            // ok lol this gives issues because the index changes if i remove a card so time to figure this out
            // Card temp = players[current_player].remove_card(play_idx[j] - 1);
            // pile_cards.push_back(temp);
            
            Card temp = players[current_player].card_at_idx(play_idx[j] - 1);
            pile_cards.push_back(temp);
            
            if (pile_cards[0].get_value() != temp.get_value()) {
                cout << "INVALID CARD SELECTIONS STOP CHEATING OR LEAENR THE GAMGEGAMEGM!!!M!1!!!\n";
                return false;
            }
        }
    }
    else {
        cout << "you must play at least " << pile_cards.size() << " cards" << endl;
        
        for (int i = 0; i < pile_cards.size(); i++) {
            cout << "enter number of card " << i + 1 << endl;
            cin >> play_idx[i];
        }
        
        // i need to figure out how to verify that all cards that are played are valid (share the same value)
        
        for (int i = 0; i < pile_cards.size(); i++) {
            // Card temp = players[current_player].remove_card(play_idx[i] - 1);
            Card temp = players[current_player].card_at_idx(play_idx[i] - 1);
            int past_val = pile_cards[0].get_value();
            
            if (past_val >= temp.get_value()) {
                cout << "INVALID CARD SELECTIONS STOP CHEATING OR LEAENR THE GAMGEGAMEGM!!!M!1!!!\n";
                return false;
            }
            
            pile_cards[i] = temp;
        }
        
    }
    
    for (int k = 0; k < pile_cards.size(); k++) {
        players[current_player].remove_card(pile_cards[k]);
    }
    
    return true;
}
