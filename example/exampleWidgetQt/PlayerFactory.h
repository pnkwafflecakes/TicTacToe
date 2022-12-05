#pragma once
#include "IPlayerFactory.h"
class PlayerFactory : public IPlayerFactory {
    public:
        PlayerFactory();
        ~PlayerFactory();
        std::unique_ptr<IPlayer> createPlayer(char i_Letter, int i_PlayerNum);
};
