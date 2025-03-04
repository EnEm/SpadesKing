#ifndef SPADES_GAME_H
#define SPADES_GAME_H

#include <string>
#include <vector>

class Player;

class Game {
 public:
  Game();
  ~Game();

  void addPlayer(const Player& player);
  void startGame();
  void playRound();
  void endGame();

 private:
  std::vector<Player> players;
  int currentRound;
  void shuffleDeck();
  void dealCards();
  void scoreRound();
};

#endif  // SPADES_GAME_H