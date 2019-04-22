#include<iostream>
#include "TicTacToe.h"

using namespace std;

void TicTacToe::ClearBoard()
{
	system("CLS");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			Board[i][j] = ' ';
	}
}

TicTacToe::TicTacToe()
{
	ClearBoard();
}

void TicTacToe::PrintBoard(char Board[3][3])
{
	cout << "\t\t     |     |     \n";
	cout << "\t\t  "<<Board[0][0]<<"  |  "<<Board[0][1]<<"  |  "<<Board[0][2]<<"  \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  "<<Board[1][0]<<"  |  "<<Board[1][1]<<"  |  "<<Board[1][2]<<"  \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  "<<Board[2][0]<<"  |  "<<Board[2][1]<<"  |  "<<Board[2][2]<<"  \n";
	cout << "\t\t     |     |     \n";
}

int TicTacToe::GetMoveX()
{
	int positionX;
	bool isValidInput = false;

	while (isValidInput == false) {
		cout << "Please enter your move (X-axis):";
		cin >> positionX;

		if (positionX < 1 || positionX > 3)
			cout << "Invalid X coordinate" << endl;
		else
			isValidInput = true;
	}
	
	return positionX - 1;
}

int TicTacToe::GetMoveY()
{
	int positionY;
	bool isValidInput = false;

	while (isValidInput == false) {
		cout << "Please enter your move (Y-axis):";
		cin >> positionY;

		if (positionY < 1 || positionY > 3)
			cout << "Invalid Y coordinate" << endl;
		else
			isValidInput = true;
	}

	return positionY - 1;
}


bool TicTacToe::placeMarker(int x,int y, char currentPlayer)
{
	if (Board[x][y] != ' ')
		return false;

	Board[x][y] = currentPlayer;
	return true;
}

void TicTacToe::Mark(int x, int y, char currentPlayer)
{
	Board[x][y] = currentPlayer;
}

bool TicTacToe::checkWin()
{
	//win conditions

	//check rows "0 0 0" or "X X X"
	for (int i = 0; i < 3; i++) {
		if ((Board[i][0] == Board[i][1]) && (Board[i][1] == Board[i][2]) && Board[i][0] != ' ')
			return true;
	}

	//check columns
	//				0		X
	//				0		X
	//				0		X
	for (int i = 0; i < 3; i++) {
		if ((Board[i][0] == Board[i][1]) && (Board[i][1] == Board[i][2]) && Board[i][0] != ' ')
			return true;
	}

	//check diagonals
	//				O			X
	//					O			X
	//						O			X
	
	// OR
	
	//						O			X
	//					O			X
	//				O			X
	if ((Board[0][0] == Board[1][1]) && (Board[1][1] == Board[2][2]) && Board[0][0] != ' ')
		return true;

	if ((Board[2][0] == Board[1][1]) && (Board[1][1] == Board[0][2]) && Board[1][1] != ' ')
		return true;

	//else return false
	return false;
}

void TicTacToe::PlayGame()
{
	//system("pause");
	char Player1 = 'X';
	char Player2 = 'O';
	
	char currentPlayer = Player1;
	bool isDone = false;

	int x, y;
	int turn = 0;
	
	cout << "\t Tic-Tac-Toe GAME" << endl;
	cout << "Player 1 = <X>\t Player 2 = <O>" << endl;
	while (isDone == false) {
		PrintBoard(Board);
		cout << "Player " << currentPlayer << "'s turn" << endl;
		x = GetMoveX();
		y = GetMoveY();
		if (placeMarker(x, y, currentPlayer) == false) {
			cout << "That spot is taken!" << endl;
			system("pause");
		}
		else
		{
			turn++;
			if (checkWin() == true) {
				system("CLS");
				PrintBoard(Board);
				cout << "Game over. " << currentPlayer << " wins!" << endl;
				isDone = true;
				system("pause");
			}
			else if (turn == 9) {
				system("CLS");
				PrintBoard(Board);
				cout << "Its a tie!" << endl;
				isDone = true;
				system("pause");
			}
			else {
				Mark(x, y, currentPlayer);
				if (currentPlayer == Player1)
					currentPlayer = Player2;
				else
					currentPlayer = Player1;
			}
		}
		system("CLS");
	}
}