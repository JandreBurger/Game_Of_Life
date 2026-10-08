#pragma once

class Grid

{
    private :
    bool grid[12][12]; //define grid

    public :
     Grid();

     void display(); //define display
     void setCell(int x , int y, bool alive); // define life cell
     int countNeighbours(int x, int y);
     void update();

};
