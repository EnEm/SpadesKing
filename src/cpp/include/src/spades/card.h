#ifndef CARD_H
#define CARD_H

#include <string>

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

enum Rank {
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE
};

class Card {
 public:
  Card(Suit suit, Rank rank);

  Suit getSuit() const;

  Rank getRank() const;

  std::string toString() const;

 private:
  Suit suit;
  Rank rank;
};

std::ostream& operator<<(std::ostream& os, const Card& card);

#endif  // CARD_H
