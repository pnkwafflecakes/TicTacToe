/**
 * @file IBoardGame.h
 * @author Adam Schlinker (adam.schlinker@uleth.ca)
 * @brief Interface for a 2D board game class.
 * @version 0.1
 * @date 2022-11-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include "IPlayer.h"
#include <vector>
#include <utility>
#include <memory>

// forward declaration
class IPlayer;

/**
 * @details Class for BoardGame objects
*/
class IBoardGame {
 public:
    std::vector<std::vector<char>> board;
    std::pair<std::unique_ptr<IPlayer>, std::unique_ptr<IPlayer>> players;
    char currentLetter;
    int turn;

    /**
     * @brief Used to assign players
    */
    virtual void assignPlayer(std::unique_ptr<IPlayer> player) = 0;

    /**
     * @brief Used to check if the game is over
    */
    virtual int checkEnd() = 0;

    /**
     * @brief Used to create a board given a size
    */
    virtual void createBoard(int size) = 0;

    /**
     * @brief Used to end the current players turn
    */
    virtual void endTurn() = 0;

    /**
     * @brief Used to modify tiles
     * 
     * @param x The x position on the board
     * @param y The y position on the board
     * @param letter The letter to be placed in the tile, X or O
    */
    virtual bool modifyTile(int x, int y, char letter) = 0;

    /**
     * @brief Used to get the board
     * 
     * @return Returns a vector as the board
    */
    virtual std::vector<std::vector<char>> getBoard() = 0;

    /**
     * @brief Used to get the size of the board
     * 
     * @return Returns the size of the board
    */
    virtual int getBoardSize() = 0;

    /**
     * @brief Used to get the current letter of a player
     * 
     * @return Return the letter
    */
    virtual char getCurrentLetter() = 0;

    /**
     * @brief Used to get the current turn
     * 
     * @return Return the current turn
    */
    virtual int getTurn() = 0;

    //virtual std::pair<std::unique_ptr<IPlayer>, std::unique_ptr<IPlayer>> getPlayers() = 0;

    /**
     * @brief Used to set the board
     * 
     * @param board The board which will replace the board
    */
    virtual void setBoard(std::vector <std::vector<char>> board) = 0;

    /**
     * @brief Used to set the players
     * 
     * @param i_players The players we have
    */
    virtual void setPlayers(std::pair<std::unique_ptr<IPlayer>, std::unique_ptr<IPlayer>> i_players) = 0;
};
