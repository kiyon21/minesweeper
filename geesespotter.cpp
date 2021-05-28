#include "geesespotter_lib.h"

char * createBoard(std::size_t xdim, std::size_t ydim) {

char * new_board = new char[xdim*ydim];

for(int i = 0; i < xdim*ydim; i++) {
  new_board[i] = 0;
}

return new_board;

}

void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim)
{
  int geese_count;

    for (int i = 0;i < xdim*ydim; i++){
    geese_count = 0;
        if (board[i]==9) {continue;}
    //if board is in the corner, check the three arrays around
      else if (i == 0) {
        if (board[i+1] == 9){
          ++geese_count;
        }
        if (board [i+xdim] == 9){
          ++geese_count;
        }
        if (board [i+xdim+1] == 9 ){
          ++geese_count;
        }
      }
      else if (i == xdim-1){
        if (board [i-1] == 9){
          ++geese_count;
        }
        if (board [i+xdim] == 9){
          ++geese_count;
        }
        if (board [i+xdim-1] == 9 ){
          ++geese_count;
        }
      }
      else if (i == (xdim*ydim)-xdim) {
        if (board [i+1] == 9){
          ++geese_count;
        }
        if (board [i-xdim] == 9){
          ++geese_count;
        }
        if (board [i-xdim+1] == 9 ){
          ++geese_count;
        }
      }
      else if (i==(xdim*ydim)-1){
        if (board [i-1] == 9){
          ++geese_count;
        }
        if (board [i-xdim] == 9){
          ++geese_count;
        }
        if (board [i-xdim-1] == 9 ){
          ++geese_count;
        }
      }
      //check if its at the top
      else if ((i > 0) && (i < xdim-1)) {
        if (board [i+1] == 9) {
          ++geese_count;
        }
        if (board [i-1] == 9) {
          ++geese_count;
        }
        if (board [i+xdim] == 9){
          ++geese_count;
        }
        if (board [i+xdim-1] == 9) {
          ++geese_count;
        }
        if (board [i+xdim+1] == 9){
          ++geese_count;
        }
      }
      //check if bottom
      else if ((i>(xdim*ydim)-xdim ) && (i < (xdim*ydim) - 1)){
        if (board [i+1] == 9) {
          ++geese_count;
        }
        if (board [i-1] == 9) {
          ++geese_count;
        }
        if (board [i-xdim] == 9){
          ++geese_count;
        }
        if (board [i-xdim-1] == 9) {
          ++geese_count;
        }
        if (board [i-xdim+1] == 9){
          ++geese_count;
        }
      }
      //check left side
      else if ((i%xdim )== 0) {
        if (board[i+1] == 9) {
          ++geese_count;
        }
        if (board[i-xdim] == 9) {
          ++geese_count;
        }
        if (board[i+xdim] == 9){
          ++geese_count;
        }
        if (board[i-xdim+1] == 9) {
          ++geese_count;
        }
        if (board[i+xdim+1] == 9){
          ++geese_count;
        }
      }
      //check if right side
      else if (((i+1)%xdim) == 0){
         if (board[i-1] == 9) {
          ++geese_count;
        }
        if (board[i-xdim] == 9) {
          ++geese_count;
        }
        if (board[i+xdim] == 9){
          ++geese_count;
        }
        if (board[i-xdim-1] == 9) {
          ++geese_count;
        }
        if (board[i+xdim-1] == 9){
          ++geese_count;
        }
      }
      else {
        if (board [i+1] == 9){
          ++geese_count;
        }
         if (board[i-1] == 9){
          ++geese_count;
        }
         if (board[i+xdim] == 9){
          ++geese_count;
        }
         if (board[i-xdim] == 9) {
          ++geese_count;
        }
         if (board[i-xdim+1] == 9) {
          ++geese_count;
        }
         if (board[i-xdim-1] == 9){
          ++geese_count;
        }
         if (board[i+xdim+1] == 9){
          ++geese_count;
        }
         if (board[i+xdim-1] == 9){
          ++geese_count;
        }
      }
      if (board[i] == 9) {
          board[i] = 9;
      }
      else {
      board[i] = geese_count;
      }
      }
  }

void hideBoard(char * board, std::size_t xdim, std::size_t ydim)
{

for (int i = 0; i < xdim*ydim; i++){
     board[i] = (board[i] | hiddenBit());
}
}
void cleanBoard(char * board)
{
    delete [] board;
}
void printBoard(char * board, std::size_t xdim, std::size_t ydim)
{
  for (int i = 0; i < xdim*ydim; ++i){
    if ((board[i] & markedBit()) == markedBit()) {
      if ((i+1)%xdim == 0) {
        std::cout << 'M' << std::endl;
      }
      else {
        std::cout << 'M';
      }
    }
    else if ((board[i] & hiddenBit()) == hiddenBit()) {
      if ((i+1)%xdim == 0) {
        std::cout << '*' << std::endl;
      }
      else {
      std::cout << '*';
      }
    }
    else {
      if ((i+1)%xdim == 0){
        std::cout << (int)board[i] << std::endl;
      }
      else {
      std::cout << (int)board[i];
      }
    }
  }
  std::cout << std::endl;
}
int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{
  
    int i{};
    i = (yloc*xdim)+xloc;

  if ((board[i] & markedBit()) == markedBit()){
    return 1;
  }
  else if ((board[i] & hiddenBit()) == hiddenBit()){
    if (board[i] == 0x29){
        board[i] ^= hiddenBit();
      return 9;
    }
    else if (board[i] == 0x20){
      
    //if board is in the corner, check the three arrays around
      if (i == 0) {
          if (board[i+1] &= hiddenBit()){
              board[i+1] ^= hiddenBit();
          }
          if (board[i+xdim] &= hiddenBit()){
              board[i+xdim] ^= hiddenBit();
          }
          if (board[i+xdim+1] &= hiddenBit()){
              board[i+xdim+1] ^= hiddenBit();
              
          }
      }
      else if (i == xdim-1){
          if (board[i-1] &= hiddenBit()){
              board[i-1] ^= hiddenBit();
          }
          if (board[i+xdim] &= hiddenBit()){
              board[i+xdim] ^= hiddenBit();
          }
          if (board[i+xdim-1] &= hiddenBit()){
              board[i+xdim-1] ^= hiddenBit();
          }
      }
      else if (i == (xdim*ydim)-xdim) {
          if (board[i+1] &= hiddenBit()){
              board[i+1] ^= hiddenBit();
          }
          if (board[i-xdim] &= hiddenBit()){
              board[i-xdim] ^= hiddenBit();
          }
          if (board[i-xdim+1] &= hiddenBit()){
              board[i-xdim+1] ^= hiddenBit();
          }
      }
      else if (i==(xdim*ydim)-1){
          if (board[i-1] &= hiddenBit()){
              board[i-1] ^= hiddenBit();
          }
          if (board[i-xdim] &= hiddenBit()){
              board[i-xdim] ^= hiddenBit();
          }
          if (board[i-xdim-1] &= hiddenBit()){
              board[i-xdim-1] ^= hiddenBit();
          }
        
      }
      //check if its at the top
      else if ((i > 0) && (i < xdim-1)) {
          if (board[i+1] &= hiddenBit()){
              board[i+1] ^= hiddenBit();
          }
          if (board[i-1] &= hiddenBit()){
              board[i-1] ^= hiddenBit();
          }
          if (board[i+xdim] &= hiddenBit()){
              board[i+xdim] ^= hiddenBit();
          }
          if (board[i+xdim-1] &= hiddenBit()){
              board[i+xdim-1] ^= hiddenBit();
          }
          if (board[i+xdim+1] &= hiddenBit()){
              board[i+xdim+1] ^= hiddenBit();
          }
        }
      
      //check if bottom
      else if ((i >(xdim*ydim)-xdim ) && (i < (xdim*ydim) - 1)){
          if (board[i+1] &= hiddenBit()){
              board[i+1] ^= hiddenBit();
          }
          if (board[i-1] &= hiddenBit()){
              board[i-1] ^= hiddenBit();
          }
          if (board[i-xdim] &= hiddenBit()){
              board[i-xdim] ^= hiddenBit();
          }
          if (board[i-xdim-1] &= hiddenBit()){
              board[i-xdim-1] ^= hiddenBit();
          }
          if (board[i-xdim+1] &= hiddenBit()){
              board[i-xdim+1] ^= hiddenBit();
          }
      }
      //check left side
      else if ((i%xdim )== 0) {
          if (board[i+1] &= hiddenBit()){
              board[i+1] ^= hiddenBit();
          }
          if (board[i-xdim] &= hiddenBit()){
              board[i-xdim] ^= hiddenBit();
          }
          if (board[i+xdim] &= hiddenBit()){
              board[i+xdim] ^= hiddenBit();
          }
          if (board[i-xdim+1] &= hiddenBit()){
              board[i-xdim+1] ^= hiddenBit();
          }
          if (board[i+xdim+1] &= hiddenBit()){
              board[i+xdim+1] ^= hiddenBit();
          }
      }
      //check if right side
      else if (((i+1)%xdim) == 0){
          if (board[i-1] &= hiddenBit()){
              board[i-1] ^= hiddenBit();
          }
          if (board[i-xdim] &= hiddenBit()){
              board[i-xdim] ^= hiddenBit();
          }
          if (board[i+xdim] &= hiddenBit()){
              board[i+xdim] ^= hiddenBit();
          }
          if (board[i-xdim-1] &= hiddenBit()){
              board[i-xdim-1] ^= hiddenBit();
          }
          if (board[i+xdim+1] &= hiddenBit()){
              board[i+xdim+1] ^= hiddenBit();
          }
      }
        //check anywhere in the middle
      else {
          if (board[i+1] &= hiddenBit()){
              board[i+1] ^= hiddenBit();
          }
          if (board[i-1] &= hiddenBit()){
              board[i-1] ^= hiddenBit();
          }
          if (board[i+xdim] &= hiddenBit()){
              board[i+xdim] ^= hiddenBit();
          }
          if (board[i-xdim] &= hiddenBit()){
              board[i-xdim] ^= hiddenBit();
          }
          if (board[i-xdim+1] &= hiddenBit()){
              board[i-xdim+1] ^= hiddenBit();
          }
          if (board[i-xdim-1] &= hiddenBit()){
              board[i-xdim-1] ^= hiddenBit();
          }
          if (board[i+xdim+1] &= hiddenBit()){
              board[i+xdim+1] ^= hiddenBit();
          }
          if (board[i+xdim-1] &= hiddenBit()){
              board[i+xdim-1] ^= hiddenBit();
          }
      }
        board[i] ^= hiddenBit();
      return 0;
    }
    
    else {
      board[i] ^= hiddenBit();
      return 0;
    }
  }
    else {
      return 2;
    }
    
  }

int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{
    int index = (yloc*xdim)+xloc;

    if ((board[index] & markedBit()) == markedBit()){
        board[index] ^= markedBit();
      return 0;
    }
    else if ((board[index] & hiddenBit()) == hiddenBit()){
        board[index] |= markedBit();
        return 0;
    }
    else {
      return 2;
    }

}
bool isGameWon(char * board, std::size_t xdim, std::size_t ydim)
{
    for (int i = 0; i < xdim*ydim; ++i){
      if ((board[i] & 0x29) == 0x29 || (board[i] & 0x19) == 0x19) {
      return false;
      }
    }
    return true;
}
   


}
int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){

}
int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){

}
bool isGameWon(char * board, std::size_t xdim, std::size_t ydim){

}

*/
