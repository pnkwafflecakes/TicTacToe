#include "PlayerFactory.h"
#include "HumanPlayer.h"

PlayerFactory::PlayerFactory() {

}

PlayerFactory::~PlayerFactory() {

}

std::unique_ptr<IPlayer> createPlayer(char i_Letter, int i_PlayerNum) {
    std::unique_ptr<IPlayer> player(new HumanPlayer(i_Letter, i_PlayerNum));

    return player;
}