#include "player.h"
#include "round.h"
#include "trick.h"

ComputerPlayer::ComputerPlayer(const std::string& name, const Bot* const bot)
    : Player(name), bot(bot) {}

void ComputerPlayer::playCard(Trick* trick) {
  // const Card card = bot->playCard(this, trick);
  // removeCard(card);
  // trick->addCard(card, static_cast<int>(getDirection()));
}

void ComputerPlayer::makeBid(const Round* round) {
  // const int bidValue = bot->makeBid(this, round);
  // setBidValue(bidValue);
}