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


TicTacToeGame::TicTacToeGame() {
    turn = 1;
    players.first = nullptr;
    players.second = nullptr;
    createBoard(3);
    currentPlayer = nullptr;
}

TicTacToeGame::~TicTacToeGame() {
    if (players.first != nullptr) {
        delete players.first;
    }
    if (players.second != nullptr) {
        delete players.second;
    }
}

TicTacToeGame::TicTacToeGame(std::pair<IPlayer*, IPlayer*> i_players) {
    turn = 0;
    players = i_players;
    currentPlayer = i_players.first;
    createBoard(3);
}

TicTacToeGame::TicTacToeGame(int size,
                            std::pair<IPlayer*, IPlayer*> i_players) {
    turn = 0;
    players = i_players;
    currentPlayer = players.first;
    createBoard(size);
}

void TicTacToeGame::assignPlayer(IPlayer* player) {
    if (player == nullptr) {
        throw std::invalid_argument("Null player!");
    } else if (players.first == nullptr) {
        players.first = player;
        currentPlayer = players.first;
    } else if (players.second == nullptr) {
        players.second = player;
    }
}

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

void TicTacToeGame::createBoard(int size) {
    if (size != 3) {
        throw std::invalid_argument("Invalid size.");
    }
    std::vector<std::vector<char> > board(
        size,
        std::vector<char>(size, 'N'));
    this->board = board;
}

void TicTacToeGame::endTurn() {
    this->turn += 1;

    if (currentPlayer->getPlayerNum() == players.first->getPlayerNum()) {
        currentPlayer = players.second;
    } else {
        currentPlayer = players.first;
    }
}

int TicTacToeGame::getBoardSize() {
    int size = 0;

    for (int i = 0; i < board.size(); i++) {
        size += board[i].size();
    }
    return size;
}

IPlayer* TicTacToeGame::getCurrentPlayer() {
    return currentPlayer;
}

int TicTacToeGame::getTurn() {
    return turn;
}

std::vector<std::vector<char>> TicTacToeGame::getBoard() {
    return board;
}

std::pair<IPlayer*, IPlayer*> TicTacToeGame::getPlayers() {
    return players;
}

void TicTacToeGame::setBoard(std::vector<std::vector<char>> board) {
    this->board = board;
}

void TicTacToeGame::setPlayers(std::pair<IPlayer*, IPlayer*> i_players) {
    this->players = players;
}
