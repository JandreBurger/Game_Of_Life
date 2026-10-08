#include "grid.h"
#include <iostream>

Grid:: Grid(){     //build grid
    for (int y= 0 ; y<12 ; y++){
        for (int x = 0;x< 12 ; x++){   
            grid[y][x] = false;


        }
    }


}

void Grid :: display(){


    for (int y = 0 ; y<=10 ; y++){

        for(int x= 0 ; x<=10 ; x++){

            if (grid[y][x]){

                std::cout <<" # "; // display alive cells
            }
            else {
                std:: cout << " . " ; // display dead cells 

            }

            
        }
        std::cout<< std::endl;

    }




}


void Grid :: setCell(int x, int y, bool alive){
    grid[y][x]= alive;
}

int Grid :: countNeighbours(int x,int y){
    int count = 0 ;
    for (int dy = -1 ; dy <= 1 ; dy++){
        for (int dx = -1 ; dx <= 1 ; dx++){

            if(dx == 0 && dy ==0 ){
                //skip
                continue;

            }else if (grid[y+dy][x+dx]){

                count++; // increment if a neighbor is detected 
            }

                
            
        }
    }
return count;


}

void Grid::update(){

    
    for (int y = 1 ; y<=10 ; y++){

        for(int x= 1 ; x<=10 ; x++){

            int neighbours = countNeighbours(x,y);
            if (grid[y][x]){

                
            }
            else {
                std:: cout << " . " ; // display dead cells 

            }

            
        }
        std::cout<< std::endl;

    
    
    
    




};