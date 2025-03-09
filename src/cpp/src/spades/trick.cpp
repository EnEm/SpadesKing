#include "trick.h"

#include <iostream>
#include <stdexcept>

#include "card.h"
#include "game.h"
#include "player.h"
#include "round.h"

Trick::Trick(const Round* const round) : round(round) {
  leadDirIndx = round->getLeadDirIndx();
  curDirIndx = leadDirIndx;
}

const Round* const Trick::getRound() const { return round; }

const int Trick::getLeadDirIndx() const { return leadDirIndx; }

const std::string Trick::toString() const {
  std::string result = "Trick: \n";
  for (int indx = 0; indx < 4; ++indx) {
    int tempDirIndx = (leadDirIndx + indx) % 4;
    if (tempDirIndx == curDirIndx) break;

    const Player* const player = round->getGame()->getPlayer(tempDirIndx);
    const std::string directionString =
        Player::directionToString(player->getDirection());
    const std::string playerName = player->getName();
    result += directionString + " :  " + playerName +
              cards[tempDirIndx].toString() + "\n";
  }
  return result;
}

void Trick::run() {
  for (int indx = 0; indx < 4; indx++) {
    curDirIndx = (leadDirIndx + indx) % 4;
    round->getGame()->getPlayer(curDirIndx)->playCard(this);
  }
}

void Trick::addCard(const Card card, int dirIndx) { cards[dirIndx] = card; }

const Card& Trick::getCard(int dirIndx) const { return cards[dirIndx]; }

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