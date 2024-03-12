#pragma once
#include "std_lib_facilities.h"

enum class Suit {clubs, diamonds, hearts, spades};
enum class Rank {two=2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};
string suitToString(Suit suit);
string rankToString(Rank rank);

class Card {
private:
    Suit s;
    Rank r;

public:
    Card(Suit suit, Rank rank) {
        s = suit;
        r = rank;
    }

    string getSuit() {
        return suitToString(s);
    }

    string getRank() {
        return rankToString(r);
    }

    int getValueOfCardRank(Rank rank) {
        switch (rank) {
            case Rank::two: return 2;
            case Rank::three: return 3;
            case Rank::four: return 4;
            case Rank::five: return 5;
            case Rank::six: return 6;
            case Rank::seven: return 7;
            case Rank::eight: return 8;
            case Rank::nine: return 9;
            case Rank::ten: return 10;
            case Rank::jack: return 10;
            case Rank::queen: return 10;
            case Rank::king: return 10;
            case Rank::ace: return 0;
        }
        return 0;
    }
    Rank getRankAsRank() {
        return r;
    }

    string toString() {
        ostringstream os;
        os << getRank() << " of " << getSuit();
        return os.str();
    }
};