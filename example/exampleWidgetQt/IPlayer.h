#pragma once
#include <string>
#include "IBoardGame.h"
#include <string>

// forward declaration
class IBoardGame;

class IPlayer {
public:
    char letter;
    int playerNum;
    std::string type;

    virtual void clickTile(int x, int y, IBoardGame* game) = 0;

    virtual char getLetter() = 0;

    virtual int getPlayerNum() = 0;

    virtual std::string getType() = 0;
};