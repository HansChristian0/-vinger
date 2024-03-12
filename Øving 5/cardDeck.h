#pragma once
#include "card.h"
#include "std_lib_facilities.h"

class CardDeck {
private:
    vector<Card> cards {};

public:
    CardDeck() {
        for (int suitType = static_cast<int>(Suit::clubs); suitType <= static_cast<int>(Suit::spades); suitType++) {
            for (int number = static_cast<int>(Rank::two); number <= static_cast<int>(Rank::ace); number++) {
                cards.push_back(Card(static_cast<Suit>(suitType), static_cast<Rank>(number)));
            }
        }
    }
    
    void swap(int a, int b) {
        Card placeholder = cards.at(a-1);
        cards.at(a-1) = cards.at(b-1);
        cards.at(b-1) = placeholder;
    }

    void printDeck() {
        for(int a = 0; a < cards.size(); a++) {
            cout << cards.at(a).toString() << endl;;
        }
    }

    void shuffle() {
        random_device rd;
        uniform_int_distribution<int> distribution(1,52);
    
        for (int i=0; i<5000; i++) {
            default_random_engine generator(rd());
            swap(distribution(generator), distribution(generator));
        }
    }

    Card drawCard(){
        Card returnValue = cards.at(0);
        cards.erase(cards.begin());
        return returnValue;
    }
    
};

