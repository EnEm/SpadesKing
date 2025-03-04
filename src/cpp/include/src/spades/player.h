#ifndef SPADES_PLAYER_H
#define SPADES_PLAYER_H

#include <string>
#include <vector>

enum Direction { NORTH, EAST, SOUTH, WEST };

class Player {
 public:
  Player(const std::string& name, const Direction& direction);

  const std::string& getName() const;
  void addCard(const std::string& card);
  const std::vector<std::string>& getHand() const;
  void clearHand();

 private:
  std::string name;
  int score;
  std::vector<std::string> hand;
};

#endif  // SPADES_PLAYER_H