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

/**
 * @details Class for IPlayer object
 */
class IPlayer {
 public:
    char letter;
    int playerNum;
    std::string type;

    /**
     * @brief Method to click a tile on the board
     * 
     * @param x The x position on the board
     * @param y The y position on the board
     * @param game The board which the game is played on
    */
    virtual std::pair<int, int> clickTile(int x, int y, std::shared_ptr<IBoardGame> game) = 0;

    /**
     * @brief Get the letter of the player
     * @return Return the letter of the player
    */
    virtual char getLetter() = 0;

    /**
     * @brief Get the player number
     * @return Return the player number
    */
    virtual int getPlayerNum() = 0;

    /**
     * @brief Get the type of player
     * @return Return the type of player
    */
    virtual std::string getType() = 0;
};
