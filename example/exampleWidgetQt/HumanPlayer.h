#pragma once
#include "IPlayer.h"
#include "IBoardGame.h"
class HumanPlayer : public IPlayer {
  public:
    HumanPlayer();

    HumanPlayer(char letter, int playerNum);

    void clickTile(int x, int y, IBoardGame* game);

    char getLetter();

    int getPlayerNum();

    std::string getType();
};
