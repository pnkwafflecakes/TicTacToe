/**
 * @file 
 * @author 
 * @brief 
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2022
 */

#include "ComputerPlayer.h"
#include <list>
#include <vector>
#include <stdexcept>

ComputerPlayer::ComputerPlayer(char iLetter, int iPlayerNum,
                                std::string const& iDifficulty) {
    if (iLetter == 'X' || iLetter== 'x' || iLetter == 'O' || iLetter == 'o') {
        letter = static_cast<char>toupper(iLetter);
    } else {
        letter = 0;
        throw std::invalid_argument("Invalid letter");
    }
    playerNum = iPlayerNum;
    difficulty = iDifficulty;
    type = "computer";
}

ComputerPlayer::ComputerPlayer() {
    type = "computer";
}

ComputerPlayer::~ComputerPlayer() {
}

void ComputerPlayer::clickTile(int x, int y, IBoardGame* game) {
    game->modifyTile(x, y, this->letter);
}

std::pair<int, int> ComputerPlayer::generateMove(IBoardGame* game) {
    std::vector<std::vector<char>> board = game->getBoard();
    std::vector<std::pair<int, int>> moves;
    if (difficulty == "easy") {
        // Calculate possible moves
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                // add as possible move if tile is null
                if (board[i][j] == 'N') {
                    moves.insert(moves.begin(), std::pair<int, int>(i, j));
                }
            }
        }
        // Generate random possible move
        int moveIndex = rand_r() % moves.size();
        return moves[moveIndex];
    }
    return std::pair<int, int>(-1, -1);
}

std::string ComputerPlayer::getDifficulty() {
    return difficulty;
}

char ComputerPlayer::getLetter() {
    return letter;
}

int ComputerPlayer::getPlayerNum() {
    return playerNum;
}

std::string ComputerPlayer::getType() {
        return type;
}
