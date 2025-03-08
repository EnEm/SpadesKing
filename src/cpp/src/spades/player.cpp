#include "player.h"

#include <algorithm>
#include <stdexcept>

#include "trick.h"

Player::Player(const std::string& name) : name(name) {}

const std::string& Player::getName() const { return name; }

void Player::setDirection(const Direction& direction) {
  this->direction = direction;
}

const Player::Direction& Player::getDirection() const { return direction; }

void Player::setTeam(Team* const team) { this->team = team; }

Team* const Player::getTeam() const { return team; }

int Player::getBidValue() const { return bidValue; }

void Player::resetTricks() { tricks = 0; }

void Player::incrementTricks() { tricks++; }

int Player::getTricks() const { return tricks; }

void Player::setHand(const std::vector<Card>& cards) { hand = cards; }

const std::vector<Card>& Player::getHand() const { return hand; }

void Player::playCard(Trick* trick) {
  throw std::runtime_error("Not implemented");
}

void Player::makeBid(const Round* round) {
  throw std::runtime_error("Not implemented");
}

void Player::setBidValue(const int bidValue) { this->bidValue = bidValue; }

void Player::removeCard(const Card& card) {
  if (hasCard(card)) {
    hand.erase(std::find(hand.begin(), hand.end(), card));
  } else {
    throw std::runtime_error("Player does not have card");
  }
}

bool Player::canPlayCard(const Card& card, const Trick* trick) const {
  if (!hasCard(card)) {
    return false;
  }

  // TODO
  return true;
}

bool Player::hasCard(const Card& card) const {
  return std::find(hand.begin(), hand.end(), card) != hand.end();
};