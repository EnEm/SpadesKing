#include "card.h"

Card::Card(const Suit& suit, const Rank& rank) : suit(suit), rank(rank) {}

const Card::Suit& Card::getSuit() const { return suit; }

const Card::Rank& Card::getRank() const { return rank; }

const std::string Card::toString() const {
  static const char* suitNames[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  static const char* rankNames[] = {"2",     "3",    "4",  "5",  "6",
                                    "7",     "8",    "9",  "10", "Jack",
                                    "Queen", "King", "Ace"};

  return std::string(rankNames[rank]) + " of " + suitNames[suit];
}