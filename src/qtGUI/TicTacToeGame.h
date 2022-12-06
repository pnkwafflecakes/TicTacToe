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

    explicit TicTacToeGame(std::pair<IPlayer*, IPlayer*> i_players);

    TicTacToeGame(int size, std::pair<IPlayer*, IPlayer*> i_players);

    void assignPlayer(IPlayer* player);

    int checkEnd();

    void createBoard(int size);

    void endTurn();

    bool modifyTile(int x, int y, char letter);

    std::vector<std::vector<char>> getBoard();

    int getBoardSize();

    IPlayer* getCurrentPlayer();

    int getTurn();

    std::pair<IPlayer*, IPlayer*> getPlayers();

    void setBoard(std::vector<std::vector<char>> board);

    void setPlayers(std::pair<IPlayer*, IPlayer*> i_player);
};
