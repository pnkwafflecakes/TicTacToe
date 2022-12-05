#include <string>
#include "pch.h"
#include "../include/HumanPlayer.h"
#include "MockTicTacToeGame.h"

class HumanPlayerTests :public::testing::Test {
protected:
    HumanPlayer player;
    void SetUp() override {

    }

    void TearDown() override {
    }
};

TEST_F(HumanPlayerTests, testLetterX) {
    HumanPlayer player = HumanPlayer('X', 2);
    EXPECT_EQ('X', player.getLetter());
}

TEST_F(HumanPlayerTests, testLetterO) {
    HumanPlayer player = HumanPlayer('O', 2);
    EXPECT_EQ('O', player.getLetter());
}

TEST_F(HumanPlayerTests, testLetterx) {
    HumanPlayer player = HumanPlayer('x', 2);
    EXPECT_EQ('X', player.getLetter());
}

TEST_F(HumanPlayerTests, testLettero) {
    HumanPlayer player = HumanPlayer('O', 2);
    EXPECT_EQ('O', player.getLetter());
}

TEST_F(HumanPlayerTests, testInvalidLetterA) {
    try {
        player = HumanPlayer('A', 2);
    }
    catch (std::invalid_argument& e) {
        EXPECT_STREQ("Invalid letter", e.what());
    }
}

TEST_F(HumanPlayerTests, testInvalidLetter) {
    try {
        player = HumanPlayer('%', 2);;
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

TEST_F(HumanPlayerTests, testInvalidLetterChar) {
    try {
        player = HumanPlayer('%', 2);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

TEST_F(HumanPlayerTests, testClickTile) {
    player = HumanPlayer('X', 2);
    MockTicTacToeGame* game = new MockTicTacToeGame();
    player.clickTile(1, 1, game);
    EXPECT_EQ(game->getBoard()[1][1], 'X');
    delete game;
}

TEST_F(HumanPlayerTests, testGetMethods) {
    HumanPlayer player2 = HumanPlayer('O', 1);
    EXPECT_EQ('O', player2.getLetter());
    EXPECT_EQ(1, player2.getPlayerNum());
    EXPECT_EQ("human", player2.getType());
}