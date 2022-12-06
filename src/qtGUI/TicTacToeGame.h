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
#include <memory>

class TicTacToeGame : private IBoardGame {
 public:
    /**
     * @brief Default constructor for TicTacToeGame
    */
    TicTacToeGame();

    /**
     * @brief Destructor for TicTacToeGame
    */
    ~TicTacToeGame();

    /**
     * @brief Constructor with players param
     * 
     * @param i_players The players we have
    */
    excplicit TicTacToeGame(std::pair<std::unique_ptr<IPlayer>,
        std::unique_ptr<IPlayer>> i_players);

    /**
     * @brief Constructor with player and size param
     * 
     * @param size The size of the board
     * @param i_players The players we have
    */
    TicTacToeGame(int size, std::pair<std::unique_ptr<IPlayer>,
        std::unique_ptr<IPlayer>> i_players);

    /**
     * @brief Assign players
     * 
     * @param player The player to assign
    */
    void assignPlayer(std::unique_ptr<IPlayer> player);

    /**
     * @brief Check if the game is over
     * 
     * @return Return a check code
    */
    int checkEnd();

    /**
     * @brief Create a board given a size
     * 
     * @param size The size of the board
    */
    void createBoard(int size);

    /**
     * @brief End the current players turn
    */
    void endTurn();

    /**
     * @brief Modify a tile with given coordinates and letter
     * 
     * @param x The x position on the board
     * @param y The y position on the board
     * @param letter The letter of the current player
    */
    bool modifyTile(int x, int y, char letter);

    /**
     * @brief Get the current board
     * 
     * @return Return the board as a vector
    */
    std::vector<std::vector<char>> getBoard();

    /**
     * @brief Get the board size
     * 
     * @return Return the size of the board
    */
    int getBoardSize();

    /**
     * @brief Get the current letter of the player
     * 
     * @return Return the current letter of the player
    */
    char getCurrentLetter();

    /**
     * @brief Get the turn
     * 
     * @return Return the turn
    */
    int getTurn();

    // std::pair<std::unique_ptr<IPlayer>,
    // std::unique_ptr<IPlayer>> getPlayers();

    /**
     * @brief Set the board to a given board
     * 
     * @param board The board which will replace the board
    */
    void setBoard(std::vector<std::vector<char>> board);

    /**
     * @brief Set the players to given players
     * 
     * @param i_player The players we have
    */
    void setPlayers(std::pair<std::unique_ptr<IPlayer>,
        std::unique_ptr<IPlayer>> i_player);
};
