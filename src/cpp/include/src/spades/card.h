#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
 public:
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

  Card() = default;
  Card(const Suit& suit, const Rank& rank);

  const Suit& getSuit() const;
  const Rank& getRank() const;

  const std::string toString(bool shortForm = false) const;

  const bool operator==(const Card& other) const;

 private:
  Suit suit;
  Rank rank;
};

#endif  // CARD_H
