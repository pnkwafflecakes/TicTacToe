/**
 * @file ComputerPlayer.cpp
 * @author Cole Kepford
 * @brief Implementation of the ComputerPlayer class
 * @version 1.0
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 */

// test

#include "ComputerPlayer.h"
#include <list>
#include <vector>
#include <stdexcept>
#include <utility>
#include <memory>
#include <string>

 /**
  * @brief Implemented constructor for ComputerPlayer using custom parameters
  *
  * @param letter The letter to be assinged to this player 'X' or 'O'
  * @param playerNum The number of this player X or O
  * @param difficulty The factor that determines how hard the computer is to play against
 */
ComputerPlayer::ComputerPlayer(char iLetter, int iPlayerNum,
    std::string const& iDifficulty) {
    if (iLetter == 'X' || iLetter == 'x' || iLetter == 'O' || iLetter == 'o') {
        letter = static_cast<char>(toupper(iLetter));
    } else {
        letter = 0;
        throw std::invalid_argument("Invalid letter");
    }

    playerNum = iPlayerNum;
    difficulty = iDifficulty;
    type = "computer";
}

/**
 * @brief Implemented default constructor for ComputerPlayer
*/
ComputerPlayer::ComputerPlayer() {
    type = "computer";
}

/**
 * @brief Implemented destructor
*/
ComputerPlayer::~ComputerPlayer() {
}

/**
 * @brief Call modifyTile from game to check and modify a tile after it is clicked
 *
 * @param x The x position on the board
 * @param y The y position on the board
 * @param game The board which the game is played on
*/
void ComputerPlayer::clickTile(int x, int y, std::shared_ptr<IBoardGame> game) {
    game.get()->modifyTile(x, y, this->letter);
}

/**
 * @brief Generate a move on easy difficulty where ComputerPlayer picks a random tile
 *
 * @param game The board which the game is played on
*/
std::pair<int, int> ComputerPlayer::generateMove(IBoardGame* game) {
    std::vector<std::vector<char>> board = game->getBoard();
    std::vector<std::pair<int, int>> moves;
    if (difficulty == "easy") {
        // Calculate possible moves
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                // Add as possible move if tile is null
                if (board[i][j] == 'N') {
                    moves.insert(moves.begin(), std::pair<int, int>(i, j));
                }
            }
        }
        // Generate random possible move
        int moveIndex = std::rand() % moves.size();
        return moves[moveIndex];
    }
    return std::pair<int, int>(-1, -1);
}

/**
 * @brief Implemented get the difficulty of the player
 * @return Return the difficulty of the player
*/
std::string ComputerPlayer::getDifficulty() {
    return difficulty;
}

/**
 * @brief Implemented get the letter of the player
 * @return Return the letter of the player
*/
char ComputerPlayer::getLetter() {
    return letter;
}

/**
 * @brief Implemented get the player number of the player
 * @return Return the player number of the player
*/
int ComputerPlayer::getPlayerNum() {
    return playerNum;
}

/**
 * @brief Implemented get the type of the player
 * @return Return the type of the player
*/
std::string ComputerPlayer::getType() {
    return type;
}
