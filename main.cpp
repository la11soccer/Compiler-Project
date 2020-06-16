#include <iostream>

using namespace std;


void print(int array[3][3], int player) // funtion to print the board
{
int a = 0;
int b = 0;
cout << "\n\n";
outer:
	inner:

		cout << array[a][b] << " ";
		b++;
		if (b < 3)
		{
			goto inner;
		}
	a++;
	cout << "\n";
	if (a < 3)
	{
		b = 0;
		goto outer;
	}
cout << "Player " << player << " please enter your x and y coordinates : ";
}

bool checkMove(int posx, int posy, int array [3][3])
{
	if (posx > 2 || posx < 0)//make sure the function is within bounds of 0-2 for both x and y
	{
		cout << "Play is outside the board, x coordinate options are 0-2.";
		return false;
	}
	else if (posy > 2 || posy < 0)
	{	
		cout << "Play is outside the board, y coordinate options are 0-2.";
		return false;

	}
	else if (array[posx][posy] != 0)// check to see if the play has already been made
	{
		cout << "Play has already been made, try again";
		return false;//if the play is not valid return false
	}
	else
	{
		return true;
	}

}


bool checkWin(int player, int array[3][3])
{
	int numToCheck = player;

	//////////////CHECKING THE HORIZONTAL ROWS////////////////
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	int rowCount = 0;
	int verticalRow = 0;

outer:

inner:
	if (array[a][b] == numToCheck)//if the index of array is equal to the current player add to rowcount, else set count to 0 (must start over)
	{
		rowCount++;
	}
	else
	{
		rowCount = 0;
	}

	b++;
	if (b < 3)//immitate for loop, run through the 2d array horizontally first so complete inner loop 3 times
	{
		goto inner;
	}
	if (rowCount == 3)//if the row count = 3 a player has won, set the return vaue to true, else set rowCount back to 0
	{
		return true;
	}
	else
	{
		rowCount = 0;
	}
	a++;
	if (a < 3)//immitate outside forloop
	{
		b = 0;
		goto outer;
	}

	//////////CHECKING THE VERTICAL ROWS//////////////
outer2:

inner2:
	if (array[d][c] == numToCheck)//if the index equals the current player add 1 to veritcal row, else, set to 0
	{
		verticalRow++;
	}
	else
	{
		verticalRow = 0;
	}
	d++;
	if (d < 3)//immitate inner for loop, running through the 2d array vertically
	{
		goto inner2;
	}
	if (verticalRow == 3) // if vertialRow = 3 a player has won, return true
	{
		return true;
	}
	else
	{
		verticalRow = 0;
	}
	c++;
	if (c < 3)//immitate outter forloop, running thorugh vertically c++ moves us over to next column to check
	{
		d = 0;
		goto outer2;
	}

	//variables to check horizontally
	int e = 0;
	int f = 0;
	int g = 0;
	int h = 0;
	int diagonalRowRight =0;
	int diagonalRowLeft = 0;
outer3:
	f = 0; // resset f
inner3: //this check the diagonal to the right
	if (array[e][f] == numToCheck) 
	{
		if (f == e) // this will check diagonal right--if the indexes equal eachother, it is an index needed for a diagonal right win
		{
			diagonalRowRight++;
		}
		//cout << "In num to check e = " << e << "f equals = " << f;
		if ((f+e) == 2)//if f+e ==2 the index is a place that would be needed in a diagonal left left win
		{
			diagonalRowLeft++;
		}		

	}
	if (f < 3)//imitating inner for loop
	{
		//cout << "this is f: " << f;
		f++;
		//e++;
		goto inner3;
	}
	e++;
	//cout << "this is e: " << e;
	
	if (e < 3)//immitate outer for loop
	{
		goto outer3;
	}
	if ((diagonalRowRight == 3) || (diagonalRowLeft == 3))//if either diagonal variable == 3 the player has won, return true
	{
		return true;
	}
	else
	{
		return false;
	}



}



int main()
{
	int current_player = 1;
	bool gameover = false;

	int gameBoard[3][3];
	int xpos, ypos;
	int a = 0;
	int b = 0;
	//variables for goto main game play
	int player1rowcount = 0;
	int player2rowcount = 0;
	int mainLoopCount = 0;

outer://set game board to 0s

	inner:		
		gameBoard[a][b] = 0;
		b++;
		if (b < 3)
		{
			goto inner;
		}
	a++;
	if (a < 3)
	{
		b = 0;
		goto outer;
	}


	//main goto for program, helps keep track is there is a tie
mainLoop:
	print(gameBoard, current_player);
	cin >> xpos >> ypos; //read in the new coordinates

	if (checkMove(xpos, ypos, gameBoard))//if the move is valid check to see if player won
	{
		gameBoard[xpos][ypos] = current_player;//set spot in game to current player
		
		//check players to see if
		gameover = checkWin(current_player,gameBoard);
		//bool playerWon2 = checkDiagonals(current_player, gameBoard);

		mainLoopCount++;
		if (gameover == true)// if the game is over, print out the baord one more time and declare winner
		{
			
			a = 0;
			b = 0;
			cout << "\n\n";
		outer3:
		inner3:

			cout << gameBoard[a][b] << " ";
			b++;
			if (b < 3)
			{
				goto inner3;
			}
			a++;
			cout << "\n";
			if (a < 3)
			{
				b = 0;
				goto outer3;
			}

			cout << "Player " << current_player << " wins!";
		}
		else
		{
			//switch players
			if (current_player == 1)
			{
				current_player = 2;
				
			}
			else
			{
				current_player = 1;
			}
			
			if (mainLoopCount == 9)//if mainLoop count gets to 9 it is a tie
			{
				cout << " Its a tie!";
			}
			else
			{
				goto mainLoop;
			}
			
		}
	}
	else
	{
		
		goto mainLoop;
	}
}