#include "round.h"

#include <iostream>

#include "card.h"
#include "game.h"
#include "player.h"
#include "random.h"
#include "team.h"
#include "trick.h"

Round::Round(const Game* const game) : game(game) {
  leadDirIndx = game->getLeadDirIndx();
}

const Game* const Round::getGame() const { return game; }

const int Round::getLeadDirIndx() const { return leadDirIndx; }

const std::string Round::toString() const {
  std::string result = "Round details:\n";
  for (int dirIndx = 0; dirIndx < 4; dirIndx++) {
    const Player* const player = game->getPlayer(dirIndx);
    const std::string directionString =
        Player::directionToString(player->getDirection());
    const std::string playerName = player->getName();
    result += directionString + " : " + playerName + "\n";
    result += "Bid = " + std::to_string(player->getBidValue()) + ", ";
    result += "Tricks = " + std::to_string(player->getTricks()) + "\n";
  }
  return result;
}

void Round::run() {
  dealCards();
  runBidding();
  for (int i = 0; i < 13; i++) {
    runTrick();
  }
  updateScores();
}

void Round::dealCards() {
  const Card* cards[52];
  initCards(cards);
  shuffleCards(cards);
  for (int dirIndx = 0; dirIndx < 4; dirIndx++) {
    dealHand(cards + dirIndx * 13,
             game->getPlayer(static_cast<Player::Direction>(dirIndx)));
  }
}

void Round::initCards(const Card* cards[52]) {
  for (int suitIndx = 0; suitIndx < 4; suitIndx++) {
    for (int rankIndx = 0; rankIndx < 13; rankIndx++) {
      cards[suitIndx * 13 + rankIndx] = new Card(
          static_cast<Card::Suit>(suitIndx), static_cast<Card::Rank>(rankIndx));
    }
  }
}

void Round::shuffleCards(const Card* cards[52]) {
  for (int i = 0; i < 52; i++) {
    int j = rng() % 52;
    const Card* temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
  }
}

void Round::dealHand(const Card* const cards[13], Player* const player) {
  std::vector<Card> hand;
  for (int i = 0; i < 13; i++) {
    hand.push_back(*cards[i]);
  }
  player->setHand(hand);
}

void Round::runBidding() {
  for (int indx = 0; indx < 4; indx++) {
    game->getPlayer((leadDirIndx + indx) % 4)->makeBid(this);
    game->getPlayer((leadDirIndx + indx) % 4)->resetTricks();
  }
}

void Round::runTrick() {
  Trick trick(this);
  trick.run();
  leadDirIndx = trick.getWinningPlayerDirIndx();
  game->getPlayer(leadDirIndx)->incrementTricks();
}

void Round::updateScores() {
  handleNilBids();
  for (int dirPairIndx = 0; dirPairIndx < 2; dirPairIndx++) {
    Team* const team = game->getTeam(dirPairIndx);
    if (team->getBidValue() >= team->getTricks()) {
      team->addScore(team->getBidValue());
      team->addBags(team->getTricks() - team->getBidValue());
    } else {
      team->addScore(-team->getBidValue());
    }
  }
}

void Round::handleNilBids() {
  for (int dirIndx = 0; dirIndx < 4; dirIndx++) {
    Player* const player = game->getPlayer(dirIndx);
    if (player->getBidValue() == 0) {
      if (player->getTricks() == 0) {
        player->getTeam()->addScore(10);
      } else {
        player->getTeam()->addScore(-10);
      }
    }
  }
}