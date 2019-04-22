#pragma once
#ifndef TICTACTOE_H_
#define TICTACTOE_H_

class TicTacToe
{
private:
	char Board[3][3];
	void ClearBoard();
	void PrintBoard(char Board[3][3]);
										/*(1,1)|(1,2)|(1,3)
										 ------|-----|------
										  (2,1)|(2,2)|(2,3)
										 ------|-----|------
										  (3,1)|(3,2)|(3,3)*/
public:
	TicTacToe();
	
	void PlayGame();

	int GetMoveX();
	int GetMoveY();
	bool placeMarker(int x, int y, char currentPlayer);
	void Mark(int x, int y, char currentPlayer);
	bool checkWin();
};
#endif