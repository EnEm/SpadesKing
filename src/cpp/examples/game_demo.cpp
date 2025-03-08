#include "game.h"
#include "player.h"

int main() {
  Player* players[4] = {new HumanPlayer("Alice"), new HumanPlayer("Bob"),
                        new HumanPlayer("Charlie"), new HumanPlayer("David")};

  Game game(players, 500);
  game.run();
  return 0;
}