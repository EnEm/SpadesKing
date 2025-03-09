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
    std::cout << card.toString(true) << " ";
  }
  std::cout << std::endl;
}

void HumanPlayer::displayGameState(const Trick* trick) {
  displayGameState(trick->getRound());
  std::cout << trick->toString() << std::endl;
}

void HumanPlayer::displayGameState(const Round* round) {
  displayGameState(round->getGame());
  std::cout << round->toString() << std::endl;
}

void HumanPlayer::displayGameState(const Game* game) {
  displayGameState();
  std::cout << game->toString() << std::endl;
}

void HumanPlayer::displayGameState() {
  std::cout << std::string(50, '=') << std::endl << std::endl;
}

const Card HumanPlayer::askForCard(const Trick* trick) const {
  std::vector<Card> playableCards;
  for (const Card& card : getHand()) {
    if (canPlayCard(card, trick)) {
      playableCards.push_back(card);
    }
  }

  std::cout << "Playable cards: " << std::endl;
  for (size_t i = 0; i < playableCards.size(); ++i) {
    std::cout << i + 1 << ": " << playableCards[i].toString() << std::endl;
  }

  std::cout << "Enter the number of the card you want to play: ";
  int choice = getValidatedInput(1, static_cast<int>(playableCards.size()));
  return playableCards[choice - 1];
}

const int HumanPlayer::askForBid(const Round* round) const {
  std::cout << "Enter bid: ";
  return getValidatedInput(0, 13);
}

const int HumanPlayer::getValidatedInput(int min, int max) {
  int value = -1;
  while (true) {
    std::string input;
    std::getline(std::cin, input);

    bool valid = true;
    for (char c : input) {
      if (!isdigit(c)) {
        valid = false;
        break;
      }
    }
    if (input.size() > 9) valid = false;

    if (valid) {
      value = std::stoi(input);
      if (value >= min && value <= max) {
        break;
      }
    }
    std::cout << "Invalid input. Please enter a number between " << min
              << " and " << max << ": ";
  }
  return value;
}
