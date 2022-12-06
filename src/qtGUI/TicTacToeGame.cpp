/**
 * @file 
 * @author 
 * @brief 
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2022
 */

#include "TicTacToeGame.h"
#include "IPlayer.h"
#include <stdexcept>
#include <memory>

/**
 * @brief Default constructor for TicTacToeGame
*/
TicTacToeGame::TicTacToeGame() {
    turn = 1;
    players.first = nullptr;
    players.second = nullptr;
    createBoard(3);
    currentLetter = 'N';
}

/**
 * @brief Destructor for TicTacToeGame
*/
TicTacToeGame::~TicTacToeGame() {}

/**
 * @brief Constructor with players param
 * 
 * @param i_players The players we have
*/
TicTacToeGame::TicTacToeGame(std::pair<std::unique_ptr<IPlayer>,
    std::unique_ptr<IPlayer>> i_players) {
    turn = 0;
    players.first = std::move(i_players.first);
    players.second = std::move(i_players.second);
    currentLetter = players.first.get()->getLetter();
    createBoard(3);
}

/**
 * @brief Constructor with player and size param
 * 
 * @param size The size of the board
 * @param i_players The players we have
*/
TicTacToeGame::TicTacToeGame(int size, std::pair<std::unique_ptr<IPlayer>,
    std::unique_ptr<IPlayer>> i_players) {
    turn = 0;
    players.first.reset(i_players.first.get());
    players.second = std::move(i_players.second);
    currentLetter = players.first.get()->getLetter();
    createBoard(size);
}

/**
 * @brief Assign players
 * 
 * @param player The player to assign
*/
void TicTacToeGame::assignPlayer(std::unique_ptr<IPlayer> player) {
    if (player == nullptr) {
        throw std::invalid_argument("Null player!");
    } else if (players.first.get() == nullptr) {
        players.first = std::move(player);
        currentLetter = players.first.get()->getLetter();
    } else if (players.second.get() == nullptr) {
        players.second = std::move(player);
    }
}

/**
 * @brief Modify a tile with given coordinates and letter
 * 
 * @param x The x position on the board
 * @param y The y position on the board
 * @param letter The letter of the current player 
*/
bool TicTacToeGame::modifyTile(int x, int y, char letter) {
    if (letter != 'X' && letter != 'O' && letter != 'N') {
        throw std::invalid_argument("Invalid character.");
        return false;
    } else if (x < 0 || x > 2 || y < 0 || y > 2) {
        throw std::invalid_argument("Invalid coordinate.");
        return false;
    } else if (this->board[x][y] == 'N') {
        this->board[x][y] = letter;
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Check if the game is over
 * 
 * @return Return a check code
*/
int TicTacToeGame::checkEnd() {
    // check diagonals
    if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
        || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
        return 1;
    } else if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
        || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
        return 2;
    }

    // check rows ands cols
    for (int i = 0; i < board.size(); i++) {
        if ((board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
            || (board[i][0] == 'O' && board[i][1] == 'O'
                && board[i][2] == 'O')) {
            return 1;
        } else if ((board[0][i] == 'X' && board[1][i] == 'X'
                    && board[2][i] == 'X')
                    || (board[i][0] == 'X' && board[i][1] == 'X'
                    && board[i][2] == 'X')) {
            return 2;
        }
    }
    if (turn > 8) {
        return 0;
    }
    // return -1 and keep the game going
    return -1;
}

/**
 * @brief Create a board given a size
 * 
 * @param size The size of the board
*/
void TicTacToeGame::createBoard(int size) {
    if (size != 3) {
        throw std::invalid_argument("Invalid size.");
    }
    std::vector<std::vector<char> > board(
        size,
        std::vector<char>(size, 'N'));
    this->board = board;
}

/**
 * @brief End the current players turn
*/
void TicTacToeGame::endTurn() {
    this->turn += 1;

    if (currentLetter == players.first->getLetter()) {
        currentLetter = players.second.get()->getLetter();
    } else {
        currentLetter = players.first.get()->getLetter();
    }
}

/**
 * @brief Get the board size
 * 
 * @return Return the size of the board
*/
int TicTacToeGame::getBoardSize() {
    int size = 0;

    for (int i = 0; i < board.size(); i++) {
        size += board[i].size();
    }
    return size;
}

/**
 * @brief Get the current letter of the player
 * 
 * @return Return the current letter of the player
*/
char TicTacToeGame::getCurrentLetter() {
    return currentLetter;
}

/**
 * @brief Get the turn
 * 
 * @return Return the turn
*/
int TicTacToeGame::getTurn() {
    return turn;
}

/**
 * @brief Get the current board
 * 
 * @return Return the board as a vector
*/
std::vector<std::vector<char>> TicTacToeGame::getBoard() {
    return board;
}

/**
 * @brief Set the board to a given board
 * 
 * @param board The board which will replace the board
*/
void TicTacToeGame::setBoard(std::vector<std::vector<char>> board) {
    this->board = board;
}

/**
 * @brief Set the players to given players
 * 
 * @param i_player The players we have
*/
void TicTacToeGame::setPlayers(std::pair<std::unique_ptr<IPlayer>,
    std::unique_ptr<IPlayer>> i_Players) {
    players.first = std::move(i_Players.first);
    players.second = std::move(i_Players.second);
}
