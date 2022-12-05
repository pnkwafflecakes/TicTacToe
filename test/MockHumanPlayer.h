#pragma once
#include"../include/IPlayer.h"
#include"../include/IBoardGame.h"
class MockHumanPlayer : public IPlayer {
public:
    int clickCounter = 0;

    MockHumanPlayer() {
    letter = 'X';
    playerNum = 1;
    type = "human";
    }


    void clickTile(int x, int y, IBoardGame* game) {
        if (clickCounter == 0) {
            game->modifyTile(1, 1, letter);
        }
        else if (clickCounter == 1) {
            game->modifyTile(0, 1, letter);
        }

        else if (clickCounter == 2) {
            game->modifyTile(2, 1, letter);
        }
        clickCounter++;
    }

    char getLetter() {
        return letter;
    }

    int getPlayerNum() {
        return playerNum;
    }

    std::string getType() {
        return type;
    }

    void setLetter(char letter) {

    }

    void setPlayerNum() {

    }
};