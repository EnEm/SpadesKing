#ifndef SPADES_MATCH_H
#define SPADES_MATCH_H

#include <string>
#include <vector>

#include "card.h"
#include "player.h"

namespace spades {

class Match {
 public:
  Match(const std::vector<std::string>& playerNames);
  void start();
  void playRound();
  void end();

 private:
  std::vector<Player> players;
  std::vector<Card> deck;
  int currentRound;
  void shuffleDeck();
  void dealCards();
  void scoreRound();
};

}  // namespace spades

#endif  // SPADES_MATCH_H