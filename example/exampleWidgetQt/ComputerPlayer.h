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
#include "IPlayer.h"
#include "IBoardGame.h"
#include <string>
#include <utility>

/**
 * @details Class for ComputerPlayer object
 */
class ComputerPlayer : public IPlayer {
 public:
        /**
         * @brief Constructor for ComputerPlayer using custom parameters
         * 
         * @param letter The letter to be assinged to this player 'X' or 'O'
         * @param playerNum The number of this player X or O
         * @param difficulty The factor that determines how hard the computer is to play against
        */
        ComputerPlayer(char letter, int playerNum,
                        std::string const& difficulty);

        /**
         * @brief Default constructor for ComputerPlayer
        */
        ComputerPlayer();

        /**
         * @brief Destructor for ComputerPlayer
        */
        ~ComputerPlayer();

        /**
         * @brief Method to click a tile on the board
         * 
         * @param x The x position on the board
         * @param y The y position on the board
         * @param game The board which the game is played on
        */
        void clickTile(int x, int y, std::unique_ptr<IBoardGame> game);

        /**
         * @brief Method to generate a move
         * 
         * @param game The board which the game is played on
         * @return Returns a pair of coordinates (x, y)
        */
        std::pair<int, int> generateMove(IBoardGame* game);

        /**
         * @brief Get the difficulty of the player
         * @return Return the difficulty of the player
        */
        std::string getDifficulty();

        /**
         * @brief Get the letter of the player
         * @return Return the letter of the player
        */
        char getLetter();

        /**
         * @brief Get the player number
         * @return Return the player number
        */
        int getPlayerNum();

        /**
         * @brief Get the type of player
         * @return Return the type of player
        */
        std::string getType();

 private:
    std::string difficulty;
};
