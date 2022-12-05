#pragma once
#include "IPlayer.h"
#include "IBoardGame.h"
#include <string>

class ComputerPlayer : public IPlayer {
    public:
        ComputerPlayer(char letter, int playerNum, std::string const& difficulty);

        ComputerPlayer();

        ~ComputerPlayer();

        void clickTile(int x, int y, IBoardGame* game);

        std::pair<int, int> generateMove(IBoardGame* game);

        std::string getDifficulty();

    char getLetter();

    int getPlayerNum();

        std::string getType();
private:
    std::string difficulty;
};