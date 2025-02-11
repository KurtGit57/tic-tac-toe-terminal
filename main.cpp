#include <iostream>
using namespace std;


char GameBoard[3][3]; //This Array holds the value for each spot on the board
void RenderBoard();
void P1Coordinate();     //These functions are defined early on to for cleaner code
void P2Coordinate();
int CheckCoordinate(int plot);
bool WinCondition(char BoardPiece);




int main(){                 //main function

    RenderBoard();

    while (1) {
      P1Coordinate();
      RenderBoard();
      
      
        if(WinCondition('X')) {
            break;
        }
        
        
      P2Coordinate();
      RenderBoard();
      
        if(WinCondition('O')) {
            break;
        }
        
        
    }

    cout << "WINNER WINNER, WE HAVE A WINNER!!";
}







void P1Coordinate() {    /* This functions main purpose is to read the coordinate data that player 1
                            passes and passes that to GameBoard as indexes  */
   int RowPlot;
   int ColumnPlot;
   char *GoToBoard;

    cout << "P L A Y E R   1  T U R N" << endl << endl;
    cout << "Enter a row plot (Between 1 and 3): ";
    cin >> RowPlot;
    RowPlot = CheckCoordinate(RowPlot);

    cout << "Enter a column Plot (Between 1 and 3): ";
    cin >> ColumnPlot;
    cout << endl << endl;
    ColumnPlot = CheckCoordinate(ColumnPlot);
    
    


    GoToBoard = &GameBoard[ColumnPlot-1][RowPlot-1];

    while (*GoToBoard != '\0') {
        cout << "This space is currently occupied. Please enter another coordinate. \n ";
        
        cout << "Enter a row plot (Between 1 and 3): ";
        cin >> RowPlot;
        RowPlot = CheckCoordinate(RowPlot);
        
        cout << "Enter a column Plot (Between 1 and 3): ";
        cin >> ColumnPlot;
        cout << endl << endl;
        ColumnPlot = CheckCoordinate(ColumnPlot);

      GoToBoard = &GameBoard[ColumnPlot-1][RowPlot-1];


    }

    *GoToBoard = 'X';
    
}

void P2Coordinate() {

   int RowPlot;
   int ColumnPlot;
   char *GoToBoard;


    cout << "P L A Y E R  2  T U R N" << endl << endl;
    cout << "Enter a row plot (Between 1 and 3): ";
    cin >> RowPlot;
    RowPlot = CheckCoordinate(RowPlot);
    
    cout << "Enter a column Plot (Between 1 and 3): ";
    cin >> ColumnPlot;
    cout << endl << endl;
    ColumnPlot = CheckCoordinate(ColumnPlot);
    
    
    
    GoToBoard = &GameBoard[ColumnPlot-1][RowPlot-1];
    

    while (*GoToBoard != '\0') {
        cout << "This space is currently occupied. Please enter another coordinate. \n ";
        
        cout << "Enter a row plot (Between 1 and 3): ";
        cin >> RowPlot;
        RowPlot = CheckCoordinate(RowPlot);
        
        cout << "Enter a column Plot (Between 1 and 3): ";
        cin >> ColumnPlot;
        cout << endl << endl;
        ColumnPlot = CheckCoordinate(ColumnPlot);

      GoToBoard = &GameBoard[ColumnPlot-1][RowPlot-1];

    }



    *GoToBoard = 'O';


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











void RenderBoard() {

    printf(" %c | %c | %c \n", GameBoard[0][0], GameBoard[0][1], GameBoard[0][2]);
    printf("----------- \n");
    printf(" %c | %c | %c \n", GameBoard[1][0], GameBoard[1][1], GameBoard[1][2]);
    printf("----------- \n");
    printf(" %c | %c | %c \n", GameBoard[2][0], GameBoard[2][1], GameBoard[2][2]);
}





























/* TODO: 
        .Make comments for all of the code that is available 
  |DONE|.Create a function that detects if the user inputs a coordinate on the board that does not exist
  |DONE|.Create a function that detects if the user inputs a coordinate that is already occupied
        .Create a procedure in the main function that checks for a win condition  
*/
