#ifndef TRICK_H
#define TRICK_H

#include <vector>

#include "card.h"

class Trick {
 public:
  Trick();
  void addCard(const Card& card);
  Suit getLeadSuit() const;
  Card getWinningCard() const;
  void toString() const;

 private:
  Suit leadSuit;
  std::vector<Card> cards;
};

std::ostream& operator<<(std::ostream& os, const Trick& card);

#endif  // TRICK_H