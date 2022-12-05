#pragma once
#include <memory>
#include "IPlayer.h"

class IPlayerFactory {
    public:
        virtual std::unique_ptr<IPlayer> createPlayer(char i_Letter, int i_PlayerNum) = 0;
};
