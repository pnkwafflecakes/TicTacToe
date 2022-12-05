#include <string>
#include "pch.h"
#include "../include/TicTacToeGame.h"
#include "../include/ComputerPlayer.h"
#include "MockTicTacToeGame.h"

class ComputerPlayerTests :public::testing::Test {
protected:
    ComputerPlayer player;
    MockTicTacToeGame game;

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(ComputerPlayerTests, testLetterX) {
    player = ComputerPlayer('X', 2, "easy");
    EXPECT_EQ('X', player.getLetter());
}

TEST_F(ComputerPlayerTests, testLetterO) {
    player = ComputerPlayer('O', 2, "easy");
    EXPECT_EQ('O', player.getLetter());
}

TEST_F(ComputerPlayerTests, testLetterx) {
    player = ComputerPlayer('x', 2, "easy");
    EXPECT_EQ('X', player.getLetter());
}

TEST_F(ComputerPlayerTests, testLettero) {
    player = ComputerPlayer('O', 2, "easy");
    EXPECT_EQ('O', player.getLetter());
}

TEST_F(ComputerPlayerTests, testInvalidLetterA) {
    try {
        player = ComputerPlayer('A', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        EXPECT_STREQ("Invalid letter", e.what());
    }
}

TEST_F(ComputerPlayerTests, testInvalidLetter) {
    try {
        player = ComputerPlayer('%', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

TEST_F(ComputerPlayerTests, testInvalidLetterChar) {
    try {
        player = ComputerPlayer('%', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

TEST_F(ComputerPlayerTests, testClickTile) {
    player = ComputerPlayer('X', 2, "easy");
    MockTicTacToeGame * game2 = new MockTicTacToeGame();
    player.clickTile(1, 1, game2);
    EXPECT_EQ(game2->getBoard()[1][1], 'X');
    delete game2;
}

TEST_F(ComputerPlayerTests, testGetMethods) {
    player = ComputerPlayer('O', 1, "easy");
    EXPECT_EQ('O', player.getLetter());
    EXPECT_EQ(1, player.getPlayerNum());
    EXPECT_EQ("computer", player.getType());
    EXPECT_EQ("easy", player.getDifficulty());
}

TEST_F(ComputerPlayerTests, testGenerateMoveEmptyBoard) {
    
    player = ComputerPlayer('X', 1, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    std::pair<int, int> move = player.generateMove(game2);
    bool inRange = false;
    if (move.first >= 0 && move.first <= 2 && move.second >= 0 && move.second <= 2) {
        inRange = true;
    }
    EXPECT_EQ(true, inRange);
}

TEST_F(ComputerPlayerTests, testGenerateMoveTopRowFull) {

    player = ComputerPlayer('X', 1, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    game2->board[0][0] = 'X';
    game2->board[0][1] = 'X';
    game2->board[0][0] = 'O';
    std::pair<int, int> move = player.generateMove(game2);
    bool validMove = false;
    if (game2->board[move.first][move.second] == 'N') {
        validMove = true;
    }
    EXPECT_EQ(true, validMove);
    delete game2;
}

TEST_F(ComputerPlayerTests, testGenerateMoveMiddleRowFull) {

    player = ComputerPlayer('X', 1, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    game2->board[1][0] = 'X';
    game2->board[1][1] = 'X';
    game2->board[1][0] = 'O';
    std::pair<int, int> move = player.generateMove(game2);
    bool validMove = false;
    if (game2->board[move.first][move.second] == 'N') {
        validMove = true;
    }
    EXPECT_EQ(true, validMove);
    delete game2;
}

TEST_F(ComputerPlayerTests, testGenerateMoveBottomRowFull) {

    player = ComputerPlayer('X', 1, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    game2->board[2][0] = 'X';
    game2->board[2][1] = 'X';
    game2->board[2][0] = 'O';
    std::pair<int, int> move = player.generateMove(game2);
    bool validMove = false;
    if (game2->board[move.first][move.second] == 'N') {
        validMove = true;
    }
    EXPECT_EQ(true, validMove);
    delete game2;
}

TEST_F(ComputerPlayerTests, testGenerateMoveMiddleColumnFull) {

    player = ComputerPlayer('X', 1, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    game2->board[0][1] = 'X';
    game2->board[1][1] = 'X';
    game2->board[2][1] = 'O';
    std::pair<int, int> move = player.generateMove(game2);
    bool validMove = false;
    if (game2->board[move.first][move.second] == 'N') {
        validMove = true;
    }
    EXPECT_EQ(true, validMove);
    delete game2;
}
