/**
 * @file 
 * @author 
 * @brief 
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once
#include "IBoardGame.h"
#include <string>
#include <memory>

// forward declaration
class IBoardGame;

class IPlayer {
 public:
    char letter;
    int playerNum;
    std::string type;

    virtual void clickTile(int x, int y, std::unique_ptr<IBoardGame> game) = 0;

    virtual char getLetter() = 0;

    virtual int getPlayerNum() = 0;

    virtual std::string getType() = 0;
};
