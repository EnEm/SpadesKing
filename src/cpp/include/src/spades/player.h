#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include "card.h"

class Bot;
class Round;
class Team;
class Trick;
class Game;

class Player {
 public:
  enum Direction { NORTH, EAST, SOUTH, WEST };
  static const std::string directionToString(const Direction& direction);

  Player(const std::string& name);

  const std::string& getName() const;
  void setDirection(const Direction& direction);
  const Direction& getDirection() const;
  void setTeam(Team* const team);
  Team* const getTeam() const;

  int getBidValue() const;
  void resetTricks();
  void incrementTricks();
  int getTricks() const;
  void setHand(const std::vector<Card>& card);
  const std::vector<Card>& getHand() const;

  virtual void playCard(Trick* trick);
  virtual void makeBid(const Round* round);

 protected:
  void setBidValue(const int bidValue);

  void removeCard(const Card& card);
  bool canPlayCard(const Card& card, const Trick* trick) const;

 private:
  const std::string name;
  Direction direction;
  Team* team = nullptr;

  int bidValue;
  int tricks;
  std::vector<Card> hand;

  bool hasCard(const Card& card) const;
  bool hasSuit(const Card::Suit& suit) const;

  void sortHand();
};

class HumanPlayer : public Player {
 public:
  HumanPlayer(const std::string& name);
  void playCard(Trick* trick);
  void makeBid(const Round* round);

 private:
  void displayHand() const;
  static void displayGameState(const Trick* trick);
  static void displayGameState(const Round* round);
  static void displayGameState(const Game* game);
  static void displayGameState();

  const Card askForCard(const Trick* trick) const;
  const int askForBid(const Round* round) const;
  static const int getValidatedInput(int min, int max);
};

class ComputerPlayer : public Player {
 public:
  ComputerPlayer(const std::string& name, const Bot* const bot);
  void playCard(Trick* trick);
  void makeBid(const Round* round);

 private:
  const Bot* const bot;
};

#endif  // PLAYER_H