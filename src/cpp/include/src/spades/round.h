#ifndef SPADES_ROUND_H
#define SPADES_ROUND_H

namespace spades {

class Round {
 public:
  Round();
  ~Round();

  void startRound();
  void endRound();
  void playCard(int playerId, int cardId);
  int getScore(int playerId) const;

 private:
  void calculateScores();

  // Add member variables as needed
};

}  // namespace spades

#endif  // SPADES_ROUND_H