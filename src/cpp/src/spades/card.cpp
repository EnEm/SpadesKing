#include "card.h"

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

Suit Card::getSuit() const { return suit; }

Rank Card::getRank() const { return rank; }

std::string Card::toString() const {
  static const char* suitNames[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  static const char* rankNames[] = {"2",     "3",    "4",  "5",  "6",
                                    "7",     "8",    "9",  "10", "Jack",
                                    "Queen", "King", "Ace"};

  return std::string(rankNames[rank]) + " of " + suitNames[suit];
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
  os << card.toString();
  return os;
}