#include <iostream>
#include "functions.h"

bool turn(Player &player, char (&grid)[3][3], bool turn)
{
    int column = 0;
    int row = 0;
    bool valid = true;

    do
    {
        if (player.computer)
        {
            column = (rand() % 3);
            row = (rand() % 3);
        }
        else
        {
            std::cout << "Player " << player.player << ", please select where to place " << player.letter << " (1-3)(1-3): ";
            std::cin >> row >> column;
            row -= 1;
            column -= 1;
        }

        if (row < 0 || row > 2 || column < 0 || column > 2)
        {
            if (player.computer == false)
            {
                std::cout << "Invalid Input, Please select numbers between 0 and 2 \n";
            }

            valid = false;
        }
        else
        {

            if (grid[row][column] == ' ')
            {
                grid[row][column] = player.letter;
                valid = true;
            }
            else
            {
                if (player.computer == false)
                {
                    std::cout << "Invalid Location, try again \n";
                }

                valid = false;
            }
        }

    } while (valid == false);

    if (player.player == 1)
    {
        return false;
    }
    else
        return true;
};

void drawGrid(char (&grid)[3][3])
{

    std::cout << "-------------\n";
    for (int k = 0; k < 3; k++)
    {
        std::cout << " | ";
        for (int i = 0; i < 3; i++)
        {
            std::cout << grid[k][i] << " | ";
        }
        std::cout << "\n------------\n";
    }
}

void winnerCheck(Player &player, char (&grid)[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == player.letter && grid[i][1] == player.letter && grid[i][2] == player.letter)
            player.winner = true;
        else if (grid[0][i] == player.letter && grid[1][i] == player.letter && grid[2][i] == player.letter)
            player.winner = true;
    }

    if (grid[0][0] == player.letter && grid[1][1] == player.letter && grid[2][2] == player.letter)
        player.winner = true;
    if (grid[2][0] == player.letter && grid[1][1] == player.letter && grid[0][2] == player.letter)
        player.winner = true;
}