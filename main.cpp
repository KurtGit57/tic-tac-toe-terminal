#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <chrono> 
#include "utilities.h"
using namespace std;


char GameBoard[3][3]; //This Array holds the value for each spot on the board
struct playerScore {
    
  uint32_t wins = 0, losses = 0;
  uint32_t turnCounter; 
  float timeCounter;
};
playerScore playerOne, playerTwo;


void RenderBoard();
void P1Coordinate();     
void P2Coordinate();
void divrCoordinate(char gamePiece, std::string turnMessage, playerScore* avgRecordTime);
int CheckCoordinate(int plot);
bool WinCondition(char BoardPiece); //This function doesn't work (what the hell was I thinking for the logic)
bool conditionWin(char BoardPiece);
void mainGameLoop();
bool playAgain(); 




int main(){                 //main function
    
    mainGameLoop();
}



void mainGameLoop() {  //Took the code from the main function and put it in its own game loop function. 
 begin:
 
    RenderBoard();
    while (1) {
        
      //P L A Y E R  1  T U R N
      divrCoordinate('X', "P L A Y E R  1  T U R N", &playerOne);
      RenderBoard();
      
      
        if(conditionWin('X')) {
            playerOne.wins++;
            playerTwo.losses++;
            break;
        }
       playerOne.turnCounter++;
       
       
      //P L A Y E R  2  T U R N
      divrCoordinate('O', "P L A Y E R  2  T U R N", &playerTwo);
      RenderBoard();
      
        if(conditionWin('O')) {
            playerTwo.wins++;
            playerOne.losses++;
            break;
        }
       playerTwo.turnCounter++;
        
        
    }
    cout << "WINNER WINNER, WE HAVE A WINNER!!" << std::endl;
    
    //This entire if statement could just be put into playAgain(). The function can just use recursion to repeat the game loop.
    if(playAgain()) {
        memset(GameBoard, '\0', sizeof(GameBoard));
        
        //The command in system is supposed to be "cls" because of windows,
        //but for some reason codehs needs me to use "clear", a linux comand??????
        system("clear");
        goto begin;
    }
    std::cout << "Thanks for Playing!" << std::endl;
    std::cout << "Scores: " << std::endl;
    std::cout << "Player 1,   Wins: " << playerOne.wins << "  Losses: " << playerOne.losses << "  Avg Turn Time: " << getAverage(playerOne.timeCounter, playerOne.turnCounter) << "ms" << std::endl;
    std::cout << "Player 2,   Wins: " << playerTwo.wins << "  Losses: " << playerTwo.losses << "  Avg Turn Time: " << getAverage(playerTwo.timeCounter, playerTwo.turnCounter) << "ms" <<std::endl;
}





int CheckCoordinate(int Plot) {
    
    while (Plot > 3) {
        cout << endl << "This number is too High, please enter another: ";
        cin >> Plot;
    }    
    
    return Plot;
}


bool WinCondition(char BoardPiece) {  
  for (int i = 0; i < 3; i++) {
      
  
   if (GameBoard[0][i] == BoardPiece ) {
       cout << i;
       return true;
   }
   
  }
  
  return false;
}

bool conditionWin(char BoardPiece) {
    
  bool firstDiagonal = 
    GameBoard[0][0] == BoardPiece &&
    GameBoard[1][1] == BoardPiece &&
    GameBoard[2][2] == BoardPiece;
    
  bool secondDiagonal = 
    GameBoard[0][2] == BoardPiece &&
    GameBoard[1][1] == BoardPiece &&
    GameBoard[2][0] == BoardPiece;
    
    
  //Check the rows for appropriate win conditions
  for(int i = 0; i < 3; i++) {      
      
      if( BoardPiece == GameBoard[i][0] && GameBoard[i][0] == GameBoard[i][1] && GameBoard[i][1] == GameBoard[i][2]) {
          
          return true;
      }
  }
  
  //Check the columns for appropriate win conditions 
  for(int i = 0; i < 3; i++) {
      
     if(GameBoard[0][i] == BoardPiece && GameBoard[0][i] == GameBoard[1][i] && GameBoard[1][i] == GameBoard[2][i]) {
         
         return true;
     }
  }
  
  if(firstDiagonal || secondDiagonal) 
      return true;
  
  return false;
}

void divrCoordinate(char gamePiece, std::string turnMessage, playerScore* avgRecordTime) {
    
    int PLOT_Row, PLOT_Column;
    auto begin = chrono::high_resolution_clock::now();
    
    cout << turnMessage << endl << endl;
    cout << "Enter a row plot (Between 1 and 3): ";
    cin >> PLOT_Row;
    PLOT_Row = CheckCoordinate(PLOT_Row);
    
    cout << "Enter a column Plot (Between 1 and 3): ";
    cin >> PLOT_Column;
    cout << endl << endl;
    PLOT_Column = CheckCoordinate(PLOT_Column);
    
    while(GameBoard[PLOT_Row - 1][PLOT_Column - 1] != '\0') {
        cout << turnMessage << endl << endl;
        cout << "Enter a row plot (Between 1 and 3): ";
        cin >> PLOT_Row;
        PLOT_Row = CheckCoordinate(PLOT_Row);
        
        cout << "Enter a column Plot (Between 1 and 3): ";
        cin >> PLOT_Column;
        cout << endl << endl;
        PLOT_Column = CheckCoordinate(PLOT_Column);

    }
    GameBoard[PLOT_Row - 1][PLOT_Column - 1] = gamePiece;
    
    
    auto end =  chrono::high_resolution_clock::now();
    
    //Getting the time interval 
    auto timeInterval = chrono::duration_cast<chrono::milliseconds>(end - begin);
    avgRecordTime->timeCounter += timeInterval.count();
}


bool playAgain() {
    std::string answer;
    std::cout << "Do you want to play again(y/n)" << std::endl;
    while(1) {   
        std::cin >> answer;
        if(answer == "y") {
            return true;
        } 
        else if (answer == "n") {
            return false;
        }
        
    }
    return true;
}





void RenderBoard() {

    printf(" %c | %c | %c \n", GameBoard[0][0], GameBoard[0][1], GameBoard[0][2]);
    printf("----------- \n");
    printf(" %c | %c | %c \n", GameBoard[1][0], GameBoard[1][1], GameBoard[1][2]);
    printf("----------- \n");
    printf(" %c | %c | %c \n", GameBoard[2][0], GameBoard[2][1], GameBoard[2][2]);
}





























/* TODO: 
  |DONE|.Make comments for all of the code that is available 
  |DONE|.Create a function that detects if the user inputs a coordinate on the board that does not exist
  |DONE|.Create a function that detects if the user inputs a coordinate that is already occupied
  |DONE|.Create a procedure in the main function that checks for a win condition  
*/
