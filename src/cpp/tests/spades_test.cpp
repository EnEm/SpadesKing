#include <gtest/gtest.h>

#include "card.h"

TEST(CardTest, CardStringTest) {
  EXPECT_EQ(Card(Card::Suit::CLUBS, Card::Rank::SEVEN).toString(),
            "Seven of Clubs");
  EXPECT_EQ(Card(Card::Suit::SPADES, Card::Rank::ACE).toString(),
            "Ace of Spades");
  EXPECT_EQ(Card(Card::Suit::HEARTS, Card::Rank::KING).toString(),
            "King of Hearts");
  EXPECT_EQ(Card(Card::Suit::DIAMONDS, Card::Rank::QUEEN).toString(),
            "Queen of Diamonds");

  EXPECT_EQ(Card(Card::Suit::CLUBS, Card::Rank::TEN).toString(true), "T\x05");
  EXPECT_EQ(Card(Card::Suit::SPADES, Card::Rank::FOUR).toString(true), "4\x06");
  EXPECT_EQ(Card(Card::Suit::HEARTS, Card::Rank::EIGHT).toString(true),
            "8\x03");
  EXPECT_EQ(Card(Card::Suit::DIAMONDS, Card::Rank::JACK).toString(true),
            "J\x04");
}