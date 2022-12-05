/**
 * @file HumanPlayer.cpp
 * @author Adam Schlinker (adam.schlinker@uleth.ca)
 * @brief Source code for HumanPlayer class.
 * @version 0.1
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "HumanPlayer.h"
#include <stdexcept>

HumanPlayer::HumanPlayer() {
    type = "human";
}

HumanPlayer::~HumanPlayer() {

}

HumanPlayer::HumanPlayer(char iLetter, int playerNum) {
    if (iLetter == 'X' || iLetter == 'x' || iLetter == 'O' || iLetter == 'o') {
        letter = static_cast<char>(toupper(iLetter));
    } else {
        letter = 0;
        throw std::invalid_argument("Invalid letter");
    }
    this->playerNum = playerNum;
    this->type = "human";
}

void HumanPlayer::clickTile(int x, int y, std::unique_ptr<IBoardGame> game) {
    game->modifyTile(x, y, letter);
}

char HumanPlayer::getLetter() {
    return this->letter;
}

int HumanPlayer::getPlayerNum() {
    return this->playerNum;
}

std::string HumanPlayer::getType() {
    return this->type;
}
