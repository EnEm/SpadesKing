#include "trick.h"

#include <algorithm>
#include <iostream>

Trick::Trick() : leadSuit(), cards() {}

void Trick::addCard(const Card& card) {
  if (cards.empty()) {
    leadSuit = card.getSuit();
  }
  cards.push_back(card);
}

Suit Trick::getLeadSuit() const { return leadSuit; }

Card Trick::getWinningCard() const {
  if (cards.empty()) {
    throw std::runtime_error("No cards in trick");
  }

  Card winningCard = cards[0];
  for (const auto& card : cards) {
    if (card.getSuit() == leadSuit && card.getRank() > winningCard.getRank()) {
      winningCard = card;
    } else if (card.getSuit() == Suit::SPADES &&
               winningCard.getSuit() != Suit::SPADES) {
      winningCard = card;
    } else if (card.getSuit() == Suit::SPADES &&
               card.getRank() > winningCard.getRank()) {
      winningCard = card;
    }
  }
  return winningCard;
}

void Trick::toString() const {
  for (const auto& card : cards) {
    std::cout << card << " ";
  }
  std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
  os << card.toString();
  return os;
}