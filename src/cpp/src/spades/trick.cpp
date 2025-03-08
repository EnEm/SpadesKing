#include "trick.h"

#include <iostream>
#include <stdexcept>

#include "card.h"
#include "game.h"
#include "player.h"
#include "round.h"

Trick::Trick(const Round* const round) : round(round) {
  leadDirIndx = round->getLeadDirIndx();
}

const Round* const Trick::getRound() const { return round; }

const std::string Trick::toString() const {
  // TODO
  return "Trick details";
}

void Trick::run() {
  for (int indx = 0; indx < 4; indx++) {
    round->getGame()->getPlayer((leadDirIndx + indx) % 4)->playCard(this);
  }
}

void Trick::addCard(const Card card, int dirIndx) { cards[dirIndx] = card; }

const int Trick::getWinningPlayerDirIndx() const {
  int winningDirIndx = leadDirIndx;

  for (int i = 1; i < 4; i++) {
    int curIndx = (leadDirIndx + i) % 4;

    const Card& currentCard = cards[curIndx];
    const Card& winningCard = cards[leadDirIndx];
    if ((currentCard.getSuit() == winningCard.getSuit() &&
         currentCard.getRank() > winningCard.getRank()) ||
        (currentCard.getSuit() == Card::Suit::SPADES &&
         winningCard.getSuit() != Card::Suit::SPADES)) {
      winningDirIndx = curIndx;
    }
  }

  return winningDirIndx;
}