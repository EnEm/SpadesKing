#ifndef TRICK_H
#define TRICK_H

#include <string>

#include "card.h"

class Round;
class Player;

class Trick {
 public:
  Trick(const Round* const round);

  const Round* const getRound() const;
  const std::string toString() const;

  void run();
  void addCard(const Card card, int dirIndx);

  const int getWinningPlayerDirIndx() const;

 private:
  const Round* const round;

  int leadDirIndx;

  Card cards[4];
};

#endif  // TRICK_H