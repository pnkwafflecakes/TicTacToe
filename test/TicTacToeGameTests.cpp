#include "pch.h"
#include "../include/TicTacToeGame.h"
#include"MockHumanPlayer.h"
#include"MockComputerPlayer.h"

class GameTests : public ::testing::Test {
    protected:
        TicTacToeGame game;
        MockHumanPlayer human;
        MockComputerPlayer computer;

        void SetUp() override {
            game = TicTacToeGame();
            computer = MockComputerPlayer();
            human = MockHumanPlayer();
        }

        void TearDown() override {

        }
};
TEST_F(GameTests, testAssignPlayerNotNull) {
    try {
        MockHumanPlayer* human2 = new MockHumanPlayer();
        game.assignPlayer(human2);
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        FAIL();
    }
}

TEST_F(GameTests, testAssignPlayerNull) {
    MockHumanPlayer * human2 = 0L;//value of null in c++
    try {
        game.assignPlayer(human2);
        delete human2;
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Null player!", message);
    }
}

TEST_F(GameTests, testCheckEndNotOver) {
    EXPECT_EQ(-1, game.checkEnd());
}
TEST_F(GameTests, testCheckEndOverWithXsBottomRow) {
    game.modifyTile(2, 0, 'X');
    game.modifyTile(2, 1, 'X');
    game.modifyTile(2, 2, 'X');

    EXPECT_EQ(2, game.checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithOsBottomRow) {
    game.modifyTile(2, 0, 'O');
    game.modifyTile(2, 1, 'O');
    game.modifyTile(2, 2, 'O');

    EXPECT_EQ(1, game.checkEnd());
}
TEST_F(GameTests, testCheckEndOverWithXsMiddleColumn) {
    game.modifyTile(0, 1, 'X');
    game.modifyTile(1, 1, 'X');
    game.modifyTile(2, 1, 'X');

    EXPECT_EQ(2, game.checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithOsMiddleColumn) {
    game.modifyTile(0, 1, 'O');
    game.modifyTile(1, 1, 'O');
    game.modifyTile(2, 1, 'O');

    EXPECT_EQ(1, game.checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithOsDiagonalRight) {
    game.modifyTile(0, 0, 'O');
    game.modifyTile(1, 1, 'O');
    game.modifyTile(2, 2, 'O');

    EXPECT_EQ(1, game.checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithXsDiagonalRight) {
    game.modifyTile(0, 0, 'X');
    game.modifyTile(1, 1, 'X');
    game.modifyTile(2, 2, 'X');

    EXPECT_EQ(2, game.checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithDrawFullBoard) {
    game.assignPlayer(new MockHumanPlayer());
    game.assignPlayer(new MockComputerPlayer());
    for (int i = 0; i < 9; i++) {
        game.endTurn();
    }
    
    EXPECT_EQ(0, game.checkEnd());
}

TEST_F(GameTests, TestCreateBoardSize3) {
    game.createBoard(3);
    std::vector<std::vector<char>> board = game.getBoard();
    EXPECT_EQ(9, game.getBoardSize());
    char letter;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            letter = board[i][j];
            EXPECT_EQ('N', letter);
        }
    }
}

TEST_F(GameTests, TestCreateBoardSize2) {
    try {
        game.createBoard(2);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

TEST_F(GameTests, TestCreateBoardSize100) {
    try {
        game.createBoard(100);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

TEST_F(GameTests, TestCreateBoardSizeZero) {
    try {
        game.createBoard(0);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

TEST_F(GameTests, TestCreateBoardSizeNegative) {
    try {
        game.createBoard(-1);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

TEST_F(GameTests, TestEndTurn1) {
    MockHumanPlayer* human2 = new MockHumanPlayer();
    MockComputerPlayer* computer2 = new MockComputerPlayer();
    game.assignPlayer(human2);
    game.assignPlayer(computer2);
    int turn = game.getTurn();
    int playerNum = game.getCurrentPlayer()->getPlayerNum();
    game.endTurn();
    EXPECT_NE(turn, game.getTurn());
    EXPECT_NE(playerNum, game.getCurrentPlayer()->getPlayerNum());
    EXPECT_EQ(2, game.getTurn());
}

TEST_F(GameTests, TestEndTurn2) {
    MockHumanPlayer* human2 = new MockHumanPlayer();
    MockComputerPlayer* computer2 = new MockComputerPlayer();
    game.assignPlayer(human2);
    game.assignPlayer(computer2);
    int turn = game.getTurn();
    int playerNum = game.getCurrentPlayer()->getPlayerNum();
    game.endTurn();
    game.endTurn();
    EXPECT_NE(turn, game.getTurn());
    EXPECT_EQ(playerNum, game.getCurrentPlayer()->getPlayerNum());
    EXPECT_EQ(3, game.getTurn());
}

TEST_F(GameTests, TestEndTurn3) {
    MockHumanPlayer* human2 = new MockHumanPlayer();
    MockComputerPlayer* computer2 = new MockComputerPlayer();
    game.assignPlayer(human2);
    game.assignPlayer(computer2);
    int turn = game.getTurn();
    int playerNum = game.getCurrentPlayer()->getPlayerNum();
    game.endTurn();
    game.endTurn();
    game.endTurn();
    EXPECT_NE(turn, game.getTurn());
    EXPECT_NE(playerNum, game.getCurrentPlayer()->getPlayerNum());
    EXPECT_EQ(2, game.getCurrentPlayer()->getPlayerNum());
    EXPECT_EQ(4, game.getTurn());
}

TEST_F(GameTests, TestModifyTileValid) {
    try {
        game.modifyTile(1, 1, 'X');
        char X = game.getBoard()[1][1];
        EXPECT_EQ('X', X);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
}

TEST_F(GameTests, TestModifyTileValid2) {
    try {
        game.modifyTile(2, 2, 'O');
        char O = game.getBoard()[2][2];
        EXPECT_EQ('O', O);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
}

TEST_F(GameTests, TestModifyTileNegativeX) {
    try {
        game.modifyTile(-1, 2, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

TEST_F(GameTests, TestModifyTileNegativeY) {
    try {
        game.modifyTile(2, -1, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

TEST_F(GameTests, TestModifyTileTooLargeX) {
    try {
        game.modifyTile(5, 2, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

TEST_F(GameTests, TestModifyTileTooLargeY) {
    try {
        game.modifyTile(2, 5, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

TEST_F(GameTests, TestModifyTileInvalidChar) {
    try {
        game.modifyTile(2, 1, 'J');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid character.", message);
    }
}