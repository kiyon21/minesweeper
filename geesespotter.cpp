#include "geesespotter_lib.h"
#include <iostream>

char * createBoard(std::size_t xdim, std::size_t ydim);
/*void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim);
void hideBoard(char * board, std::size_t xdim, std::size_t ydim);
void cleanBoard(char * board);
void printBoard(char * board, std::size_t xdim, std::size_t ydim);
int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc);
int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc);
bool isGameWon(char * board, std::size_t xdim, std::size_t ydim); */

char * createBoard(std::size_t xdim, std::size_t ydim) {

int num_boxes = xdim*ydim;
char *boxes[num_boxes];
for (int i; i < num_boxes; i++){
    boxes[i] = 0;
}
return boxes[num_boxes];

}

/*
void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim){ 
 


}
void hideBoard(char * board, std::size_t xdim, std::size_t ydim){

}
void cleanBoard(char * board){

}
void printBoard(char * board, std::size_t xdim, std::size_t ydim){

}
int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){

}
int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){

}
bool isGameWon(char * board, std::size_t xdim, std::size_t ydim){

}

*/