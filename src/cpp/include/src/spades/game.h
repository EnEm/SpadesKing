#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

class Player;
class Team;

class Game {
 public:
  Game(Player* const players[4], const int scoreLimit);

  const int getLeadDirIndx() const;
  Player* const getPlayer(const int dirIndx) const;
  Team* const getTeam(const int dirPairIndx) const;
  const std::string toString() const;

  void run();
  std::vector<int> getScores() const;

 private:
  int leadDirIndx;
  Player* const players[4];
  Team* teams[2];
  const int scoreLimit;

  std::string initString() const;
};

#endif  // GAME_H