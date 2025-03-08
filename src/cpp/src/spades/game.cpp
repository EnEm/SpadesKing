#include "game.h"

#include <iostream>

#include "player.h"
#include "random.h"
#include "round.h"
#include "team.h"

Game::Game(Player* const players[4], const int scoreLimit)
    : players{players[0], players[1], players[2], players[3]},
      scoreLimit(scoreLimit) {
  for (int dirIndx = 0; dirIndx < 4; dirIndx++) {
    players[dirIndx]->setDirection(static_cast<Player::Direction>(dirIndx));
  }

  teams[0] = new Team(players[0], players[2], Team::DirectionPair::NORTH_SOUTH);
  teams[1] = new Team(players[1], players[3], Team::DirectionPair::EAST_WEST);

  leadDirIndx = rng() % 4;
}

Team* const Game::getTeam(const int dirPairIndx) const {
  return teams[dirPairIndx];
}

Player* const Game::getPlayer(const int dirIndx) const {
  return players[dirIndx];
}

const int Game::getLeadDirIndx() const { return leadDirIndx; }

const std::string Game::toString() const { return "Game state representation"; }

void Game::run() {
  std::cout << initString() << std::endl;

  while (teams[0]->getFinalScore() < scoreLimit &&
         teams[1]->getFinalScore() < scoreLimit) {
    Round round(this);
    round.run();

    leadDirIndx = (leadDirIndx + 1) % 4;
  }
}

std::vector<int> Game::getScores() const {
  std::vector<int> scores;
  for (auto i = 0; i < 4; i++) {
    scores.push_back(players[i]->getTeam()->getFinalScore());
  }
  return scores;
}

std::string Game::initString() const {
  return "Started the game with team\n" + teams[0]->toString() + "   and\n" +
         teams[1]->toString();
}