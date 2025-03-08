#include <iostream>

#include "game.h"
#include "player.h"
#include "round.h"
#include "trick.h"

HumanPlayer::HumanPlayer(const std::string& name) : Player(name) {}

void HumanPlayer::playCard(Trick* trick) {
  displayGameState(trick);
  displayHand();
  const Card card = askForCard(trick);
  removeCard(card);
  trick->addCard(card, static_cast<int>(getDirection()));
}

void HumanPlayer::makeBid(const Round* round) {
  displayGameState(round);
  displayHand();
  const int bidValue = askForBid(round);
  setBidValue(bidValue);
}

void HumanPlayer::displayHand() const {
  std::cout << "Hand: ";
  for (const Card& card : getHand()) {
    std::cout << card.toString() << " ";
  }
  std::cout << std::endl;
}

void HumanPlayer::displayGameState(const Trick* trick) const {
  displayGameState(trick->getRound());
  std::cout << "Current trick: " << trick->toString() << std::endl;
}

void HumanPlayer::displayGameState(const Round* round) const {
  displayGameState(round->getGame());
  std::cout << "Current round: " << round->toString() << std::endl;
}

void HumanPlayer::displayGameState(const Game* game) const {
  std::cout << "Current game: " << game->toString() << std::endl;
}

const Card HumanPlayer::askForCard(const Trick* trick) const {
  std::cout << "Enter card to play: ";
  std::string suit;
  std::string rank;
  std::cin >> rank >> suit;
  return Card(static_cast<Card::Suit>(std::stoi(suit)),
              static_cast<Card::Rank>(std::stoi(rank)));
}

const int HumanPlayer::askForBid(const Round* round) const {
  std::cout << "Enter bid: ";
  int bid;
  std::cin >> bid;
  return bid;
}
