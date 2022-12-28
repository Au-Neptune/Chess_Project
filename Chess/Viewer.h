#pragma once
#include "main.h"
#include "Board.h"

class Viewer
{
public:
	HANDLE hConsole;
	int originalColor;
	int backColor;

	Viewer();
	void changeBackColor();
	void printBlackPawn(int x, int y);
	void printBlackRook(int x, int y);
	void printBlackBishop(int x, int y);
	void printBlackKnight(int x, int y);
	void printBlackQueen(int x, int y);
	void printBlackKing(int x, int y);
	void printWhitePawn(int x, int y);
	void printWhiteRook(int x, int y);
	void printWhiteBishop(int x, int y);
	void printWhiteKnight(int x, int y);
	void printWhiteQueen(int x, int y);
	void printWhiteKing(int x, int y);
	void printNothing(int x, int y);
	void printBoard(Board &board);
	void printDisplayBoard(Board& board, vector<Position>& list);
	void printSurrenderButton();
	void printNowPlayer(int num);
	void printResult(Board& board, string winner);
	void goToEnd();
	void printMenu();
	void printPromoteList(char player);
	void printRedoButton();
	void printUndoButton();
	void printTime(int seconds);
};