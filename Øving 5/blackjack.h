#pragma once
#include "cardDeck.h"
#include "card.h"
#include "std_lib_facilities.h"

class Person{
public:
    vector<Card> cards;
    int sumCards();
    bool checkRealBlackjack(vector<Card> cards);
    void printCards(vector<Card> cards); 
};

class Dealer : public Person {
public:
    void drawCards(Card card);
};

class Player : public Person {
public:
    void drawCards(Card card);
};

class Blackjack{
public:
    void checkWinner(Player player, Dealer dealer);
    void play(Player player, Dealer dealer, CardDeck deck);
};