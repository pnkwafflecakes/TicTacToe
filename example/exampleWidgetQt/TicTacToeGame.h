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
#include <vector>
#include <utility>

class TicTacToeGame : private IBoardGame {
 public:
    TicTacToeGame();

    ~TicTacToeGame();

    TicTacToeGame(std::pair<std::unique_ptr<IPlayer>, std::unique_ptr<IPlayer>> i_players);

    TicTacToeGame(int size, std::pair<std::unique_ptr<IPlayer>, std::unique_ptr<IPlayer>> i_players);

    void assignPlayer(std::unique_ptr<IPlayer> player);

    int checkEnd();

    void createBoard(int size);

    void endTurn();

    bool modifyTile(int x, int y, char letter);

    std::vector<std::vector<char>> getBoard();

    int getBoardSize();

    char getCurrentLetter();

    int getTurn();

    //std::pair<std::unique_ptr<IPlayer>, std::unique_ptr<IPlayer>> getPlayers();

    void setBoard(std::vector<std::vector<char>> board);

    void setPlayers(std::pair<std::unique_ptr<IPlayer>, std::unique_ptr<IPlayer>> i_player);
};
