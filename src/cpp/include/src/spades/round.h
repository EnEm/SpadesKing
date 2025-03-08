#ifndef ROUND_H
#define ROUND_H

#include <string>
class Game;
class Card;
class Player;

class Round {
 public:
  Round(const Game* const game);

  const Game* const getGame() const;
  const int getLeadDirIndx() const;
  const std::string toString() const;

  void run();

 private:
  const Game* const game;

  int leadDirIndx;

  void dealCards();
  void initCards(const Card* cards[52]);
  void shuffleCards(const Card* cards[52]);
  void dealHand(const Card* const cards[13], Player* const player);
  void runBidding();
  void runTrick();
  void updateScores();
  void handleNilBids();
};

#endif  // ROUND_H