#ifndef TEAM_H
#define TEAM_H

#include <string>

class Player;

class Team {
 public:
  enum DirectionPair { NORTH_SOUTH, EAST_WEST };
  Team(Player* const player1, Player* const player2,
       const DirectionPair& directionPair);

  const Player* const getPlayer(const int index) const;
  const DirectionPair& getDirectionPair() const;
  const std::string toString() const;

  int getBidValue() const;
  int getTricks() const;

  int getFinalScore() const;
  void addScore(int score);
  void addBags(int bags);

 private:
  const Player* const players[2];
  const DirectionPair directionPair;

  // Usual Spades score / 10 , So 233 would be 23 here with 3 bags.
  int score = 0;
  int bags = 0;
};

#endif  // TEAM_H