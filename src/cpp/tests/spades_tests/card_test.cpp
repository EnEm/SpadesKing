#include "card.h"

#include <gtest/gtest.h>

TEST(SpadesTest, CardStringTest) {
  EXPECT_EQ(Card(Card::Suit::CLUBS, Card::Rank::SEVEN).toString(),
            "7 of Clubs");
  EXPECT_EQ(Card(Card::Suit::SPADES, Card::Rank::ACE).toString(),
            "Ace of Spades");
  EXPECT_EQ(Card(Card::Suit::HEARTS, Card::Rank::KING).toString(),
            "King of Hearts");
  EXPECT_EQ(Card(Card::Suit::DIAMONDS, Card::Rank::QUEEN).toString(),
            "Queen of Diamonds");
}