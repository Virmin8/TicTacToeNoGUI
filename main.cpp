#include <iostream>
#include "functions.h"

int main()
{

    bool playerTurn = true;
    bool tie = false;
    int rounds = 0;

    Player player1;
    player1.letter = 'X';
    player1.player = 1;

    Player player2;
    player2.letter = 'O';
    player2.player = 2;

    char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    std::cout << "Game Start!!! \n";
    drawGrid(grid);

    while (player1.winner == false && player2.winner == false && tie == false)
    {

        if (playerTurn)
        {
            playerTurn = turn(player1, grid, playerTurn);
            drawGrid(grid);
            winnerCheck(player1,grid);
        }
        else
        {
            playerTurn = turn(player2, grid, playerTurn);
            drawGrid(grid);
            winnerCheck(player2,grid);
        }

        if (rounds >= 9)
        {
            if (player1.winner == false && player2.winner == false)
            {
                tie = true;
            }
        }

        rounds++;
    }
    if (player1.winner == true)
    {
        std::cout << "Player 1 has won!! \n";
    }
    else if (player2.winner == true)
    {
        std::cout << "Player 2 has won!! \n";
    }
    else
        std::cout << "Its a TIE!! \n";
    

    return 0;
}