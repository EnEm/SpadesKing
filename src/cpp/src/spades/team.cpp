#include "team.h"

#include "player.h"

Team::Team(Player* const player1, Player* const player2,
           const DirectionPair& directionPair)
    : players{player1, player2}, directionPair(directionPair) {
  player1->setTeam(this);
  player2->setTeam(this);
}

const Player* const Team::getPlayer(const int index) const {
  if (index < 0 || index >= 2) {
    return nullptr;
  }
  return players[index];
}

const Team::DirectionPair& Team::getDirectionPair() const {
  return directionPair;
}

const std::string Team::toString() const {
  return players[0]->getName() + " and " + players[1]->getName();
}

int Team::getBidValue() const {
  return players[0]->getBidValue() + players[1]->getBidValue();
}

int Team::getTricks() const {
  return players[0]->getTricks() + players[1]->getTricks();
}

int Team::getFinalScore() const { return score * 10 + bags; }

void Team::addScore(int score) { this->score += score; }

void Team::addBags(int bags) {
  this->bags += bags;
  while (bags >= 10) {
    this->score -= 100;
    this->bags -= 10;
  }
}