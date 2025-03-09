#include "card.h"

Card::Card(const Suit& suit, const Rank& rank) : suit(suit), rank(rank) {}

const Card::Suit& Card::getSuit() const { return suit; }

const Card::Rank& Card::getRank() const { return rank; }

const std::string Card::toString(bool shortForm) const {
  if (shortForm) {
    static const char* suitShortNames[] = {"\xE2\x99\xA5", "\xE2\x99\xA6",
                                           "\xE2\x99\xA3", "\xE2\x99\xA0"};
    static const char* rankShortNames[] = {"2", "3", "4", "5", "6", "7", "8",
                                           "9", "T", "J", "Q", "K", "A"};

    return std::string(rankShortNames[rank]) + suitShortNames[suit];
  }

  static const char* suitNames[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  static const char* rankNames[] = {"Two",   "Three", "Four", "Five", "Six",
                                    "Seven", "Eight", "Nine", "Ten",  "Jack",
                                    "Queen", "King",  "Ace"};

  return std::string(rankNames[rank]) + " of " + suitNames[suit];
}

const bool Card::operator==(const Card& other) const {
  return suit == other.suit && rank == other.rank;
}