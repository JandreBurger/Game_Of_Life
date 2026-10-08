#include "grid.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>   

Grid::Grid()
{
    // Build both grids
    for (int y = 0; y < 12; y++)
    {
        for (int x = 0; x < 12; x++)
        {
            grid[y][x] = false;
            nextGrid[y][x] = false;
        }
    }
}

void Grid::display()
{
    for (int y = 1; y <= 10; y++)
    {
        for (int x = 1; x <= 10; x++)
        {
            if (grid[y][x])
            {
                std::cout << " # ";
            }
            else
            {
                std::cout << " . ";
            }
        }

        std::cout << std::endl;
    }
}

void Grid::setCell(int x, int y, bool alive)
{
    grid[y][x] = alive;
}

int Grid::countNeighbours(int x, int y)
{
    int count = 0;

    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dx == 0 && dy == 0)
            {
                continue;
            }
            else if (grid[y + dy][x + dx])
            {
                count++;
            }
        }
    }

    return count;
}

void Grid::update()
{
    for (int y = 1; y <= 10; y++)
    {
        for (int x = 1; x <= 10; x++)
        {
            int neighbours = countNeighbours(x, y);

            if (grid[y][x])
            {
                // Alive cell survives with 2 or 3 neighbours
                if (neighbours == 2 || neighbours == 3)
                {
                    nextCell(x, y, true);
                }
                else
                {
                    nextCell(x, y, false);
                }
            }
            else
            {
                // Dead cell becomes alive with exactly 3 neighbours
                if (neighbours == 3)
                {
                    nextCell(x, y, true);
                }
                else
                {
                    nextCell(x, y, false);
                }
            }
        }
    }

    // Move the next generation into the current grid
    for (int y = 1; y <= 10; y++)
    {
        for (int x = 1; x <= 10; x++)
        {
            grid[y][x] = nextGrid[y][x];
        }
    }
}

void Grid::nextCell(int x, int y, bool alive)
{
    nextGrid[y][x] = alive;
}

void Grid::alivepercentage(int percentage){
       

    for(int y = 1 ; y<= 10 ; y++){
        for (int x = 1 ; x<= 10 ; x++){
            int randomnum = (std::rand()%100)+1;
            if (randomnum <= percentage){
                setCell(x,y,true);


            }else{
                setCell(x,y,false);
            }

        }
    }

 
}