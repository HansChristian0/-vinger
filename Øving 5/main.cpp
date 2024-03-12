#include "std_lib_facilities.h"
#include "card.h"
#include "cardDeck.h"
#include "blackjack.h"

int main(){
    Player Ole;
    CardDeck deck;
    Dealer Peter;
    Blackjack spill;
    spill.play(Ole, Peter, deck);
    return 0;
}