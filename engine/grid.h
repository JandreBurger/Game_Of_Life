#pragma once

class Grid
{
private:
    bool grid[12][12]; // define grid
    bool nextGrid[12][12];

public:
    Grid();

    void display(); // define display
    void setCell(int x, int y, bool alive); // define current cell
    int countNeighbours(int x, int y);
    void update();
    void nextCell(int x, int y, bool alive);
    void alivepercentage(int percentage);
};