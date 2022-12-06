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
#include <memory>
#include "IPlayer.h"

/**
 * @details Class to create Players
 */
class IPlayerFactory {
    public:
        /**
         * @brief Method to create a player
         * 
         * @return Return a pointer to the player created
        */
        virtual std::unique_ptr<IPlayer> createPlayer(char i_Letter, int i_PlayerNum) = 0;
};
