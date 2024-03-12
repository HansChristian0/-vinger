#include "blackjack.h"

int Person::sumCards() {
    int sum = 0;
        int ace = 0;
        for (Card& card : cards) {
            if (card.getRank() == "Ace") {
                ace += 1;
            }
            sum += card.getValueOfCardRank(card.getRankAsRank());
        }
        for (int x=0; x<ace; x++) {
            if (sum <= 10) {
                sum += 11;
            } else {
                sum += 1;
            }
        }
    return sum;
}

bool Person::checkRealBlackjack(vector<Card> cards) {
    if (cards.size() == 2) {
        if (sumCards() == 11) {
            return true;
        }
    }
    return false;
}

void Person::printCards(vector<Card> cards) {
    cout << "sin hånd består av " << endl;
    for (Card& card : cards) {
        cout << card.toString() << endl;
    }
}

void Dealer::drawCards(Card card) {
    if (sumCards() < 17) {
            cards.push_back(card);
    } else {
        cout << "Dealer kan ikke trekke flere kort " << endl;
    }
}

void Player::drawCards(Card card) {
        cards.push_back(card);
}

void Blackjack::checkWinner(Player player, Dealer dealer) {
    if (player.checkRealBlackjack(player.cards)){
        if (!dealer.checkRealBlackjack(dealer.cards)){
            cout << "Player won! " << endl;
        }
    }
    else if (dealer.sumCards() > 21) {
        if (player.sumCards() < 21) {
            cout << "Player won! " << endl;
        }
    }
    else if (player.sumCards() > 21) {
        if (dealer.sumCards() < 21) {
            cout << "Dealer won! " << endl;
        }
    }
    else if (player.sumCards() > dealer.sumCards()) {
        cout << "Player won! " << endl;
    } else {
        cout << "Dealer won! " << endl;
    }
}

void Blackjack::play(Player player, Dealer dealer, CardDeck deck){
    deck.shuffle();
    player.drawCards(deck.drawCard());
    player.drawCards(deck.drawCard());
    dealer.drawCards(deck.drawCard());
    dealer.drawCards(deck.drawCard());
    cout << "Player ";
    player.printCards(player.cards);
    cout << endl;
    cout << "Dealer ";
    player.printCards(dealer.cards);
    cout << endl;

    bool game = true;
    string playerInput;
    string dealerInput;

    while (game) {
        cout << "Ønsker player å trekke et kort? (j/n) ";
        cin >> playerInput;
        
        if (playerInput == "j"){
            player.drawCards(deck.drawCard());
            cout << endl << "Player ";
            player.printCards(player.cards);
            if (player.sumCards() > 21) {
                break;
            }
        } else {
            game = false;
        }
        
        cout << "Ønsker dealer å trekke et kort? (j/n) ";
        cin >> dealerInput;
        
        if (dealerInput == "j" && dealer.sumCards()<17){
            dealer.drawCards(deck.drawCard());
            cout << endl << "Dealer ";
            dealer.printCards(dealer.cards);
            game = true;
        }

    }
    checkWinner(player, dealer);

}