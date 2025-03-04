#ifndef SPADES_TEAM_H
#define SPADES_TEAM_H

#include <string>
#include <vector>

#include "player.h"

class Team {
 public:
  Team(const std::string& name);

  void addPlayer(const Player& player);
  int getScore() const;
  void addScore(int points);
  std::string getName() const;

 private:
  std::string name;
  std::vector<Player> players;
  int score;
};

#endif  // SPADES_TEAM_H