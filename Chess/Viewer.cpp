#include "Viewer.h"

void gotoxy(short x, short y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void Viewer::goToEnd()
{
	gotoxy(0, 8 * 8);
}

Viewer::Viewer()
{
	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbInfo;
	GetConsoleScreenBufferInfo(hConsole, &cbInfo);
	this->originalColor = cbInfo.wAttributes;
	this->backColor = 153; // 102
}

void Viewer::changeBackColor()
{
	if (backColor == 153)
		backColor = 102;
	else
		backColor = 153;
}

void Viewer::printBlackPawn(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 3)
			{
				if (j >= 5 && j <= 7)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 5 && j <= 7)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printBlackRook(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j == 4 || j == 6 || j == 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 5 && j <= 7)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printBlackBishop(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j == 6)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if (j >= 5 && j <= 7)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 4 && j <= 7 || j==9)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 5 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printBlackKnight(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if ((j >= 3 && j <= 4) || (j >= 6 && j <= 9))
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 5 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printBlackQueen(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j == 3 || j == 5 || j == 7 || j == 9)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if (j == 4 || j == 6 || j == 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 5 && j <= 7)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printBlackKing(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j == 4 || j == 6 || j == 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if (j == 3 || (j >= 5 && j <= 7) || j == 9)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j == 4 || j == 6 || j == 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, originalColor);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printWhitePawn(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 3)
			{
				if (j >= 5 && j <= 7)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 5 && j <= 7)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printWhiteRook(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j == 4 || j == 6 || j == 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 5 && j <= 7)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printWhiteBishop(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j == 6)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if (j >= 5 && j <= 7)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 4 && j <= 7 || j == 9)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 5 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printWhiteKnight(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if ((j >= 3 && j <= 4) || (j >= 6 && j <= 9))
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 5 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printWhiteQueen(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j == 3 || j == 5 || j == 7 || j == 9)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if (j == 4 || j == 6 || j == 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 5 && j <= 7)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printWhiteKing(int x, int y)
{
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j == 4 || j == 6 || j == 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if (j == 3 || (j >= 5 && j <= 7) || j == 9)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j == 4 || j == 6 || j == 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j >= 4 && j <= 8)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, 119);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, backColor);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, backColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(x, y + i);
	}
}

void Viewer::printNothing(int x, int y)
{
	SetConsoleTextAttribute(hConsole, backColor);
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			cout << ' ';
		}
		gotoxy(x, y + i);
	}
	SetConsoleTextAttribute(hConsole, originalColor);
}

void Viewer::printBoard(Board& board)
{
	//system("cls");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board.board[i][j].player == 'B')
			{
				if (board.board[i][j].type == "Pawn")
				{
					gotoxy(j * 11, i * 8);
					printBlackPawn(j * 11, i * 8);
				}
				else if (board.board[i][j].type == "Rook")
				{
					gotoxy(j * 11, i * 8);
					printBlackRook(j * 11, i * 8);
				}
				else if (board.board[i][j].type == "Knight")
				{
					gotoxy(j * 11, i * 8);
					printBlackKnight(j * 11, i * 8);
				}
				else if (board.board[i][j].type == "Bishop")
				{
					gotoxy(j * 11, i * 8);
					printBlackBishop(j * 11, i * 8);
				}
				else if (board.board[i][j].type == "Queen")
				{
					gotoxy(j * 11, i * 8);
					printBlackQueen(j * 11, i * 8);
				}
				else if (board.board[i][j].type == "King")
				{
					gotoxy(j * 11, i * 8);
					printBlackKing(j * 11, i * 8);
					if (board.board[i][j].isDanger)
					{
						gotoxy(j * 11, (i + 1) * 8 - 1);
						for (int i = 0; i < 11; i++)
						{
							SetConsoleTextAttribute(hConsole, 68);
							cout << ' ';
						}
						SetConsoleTextAttribute(hConsole, originalColor);
					}
				}
			}
			else if (board.board[i][j].player == 'W')
			{
				if (board.board[i][j].type == "Pawn")
				{
					gotoxy(j * 11, i * 8);
					printWhitePawn(j * 11, i * 8);
				}
				else if (board.board[i][j].type == "Rook")
				{
					gotoxy(j * 11, i * 8);
					printWhiteRook(j * 11, i * 8);
				}
				else if (board.board[i][j].type == "Knight")
				{
					gotoxy(j * 11, i * 8);
					printWhiteKnight(j * 11, i * 8);
				}
				else if (board.board[i][j].type == "Bishop")
				{
					gotoxy(j * 11, i * 8);
					printWhiteBishop(j * 11, i * 8);
				}
				else if (board.board[i][j].type == "Queen")
				{
					gotoxy(j * 11, i * 8);
					printWhiteQueen(j * 11, i * 8);
				}
				else if (board.board[i][j].type == "King")
				{
					gotoxy(j * 11, i * 8);
					printWhiteKing(j * 11, i * 8);
					if (board.board[i][j].isDanger)
					{
						gotoxy(j * 11, (i + 1) * 8 - 1);
						for (int i = 0; i < 11; i++)
						{
							SetConsoleTextAttribute(hConsole, 68);
							cout << ' ';
						}
					}
				}
			}
			else
			{
				gotoxy(j * 11, i * 8);
				printNothing(j * 11, i * 8);
			}

			if (j != 7)
				changeBackColor();
		}
	}
	printSurrenderButton();
	printUndoButton();
	printRedoButton();
	goToEnd();
}

void Viewer::printDisplayBoard(Board& board, vector<Position>& list)
{
	//system("cls");
	printBoard(board);

	if (board.board[board.blackKing.y][board.blackKing.x].isDanger)
	{
		gotoxy(board.blackKing.x * 11, (board.blackKing.y + 1) * 8 - 1);
		for (int i = 0; i < 11; i++)
		{
			SetConsoleTextAttribute(hConsole, 68);
			cout << ' ';
		}
		SetConsoleTextAttribute(hConsole, originalColor);
	}

	if (board.board[board.whiteKing.y][board.whiteKing.x].isDanger)
	{
		gotoxy(board.whiteKing.x * 11, (board.whiteKing.y + 1) * 8 - 1);
		for (int i = 0; i < 11; i++)
		{
			SetConsoleTextAttribute(hConsole, 68);
			cout << ' ';
		}
		SetConsoleTextAttribute(hConsole, originalColor);
	}

	for (int i = 0; i < list.size(); i++)
	{
		gotoxy(list[i].x * 11, (list[i].y + 1) * 8 - 1);

		if (board.board[list[i].y][list[i].x].player != ' ')
			SetConsoleTextAttribute(hConsole, 170);
		else
			SetConsoleTextAttribute(hConsole, 85);

		for (int i = 0; i < 11; i++)
		{
			cout << ' ';
		}
		SetConsoleTextAttribute(hConsole, originalColor);
	}
	goToEnd();
}

void Viewer::printNowPlayer(int num)
{
	gotoxy(9 * 11, 1 * 8);
	SetConsoleTextAttribute(hConsole, originalColor);
	cout << "目前玩家:" << (num == 0 ? "白方" : "黑方");
	goToEnd();
}

void Viewer::printSurrenderButton()
{
	gotoxy(8 * 11 + 1, 2 * 8 + 4);

	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2 || i == 3)
			{
				if (j == 3)
				{
					SetConsoleTextAttribute(hConsole, 238);
					cout << ' ';
				}
				else if (j >= 4 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 204);
					cout << ' ';
				}
			}
			else if (i >= 4 && i <= 7)
			{
				if (j == 3)
				{
					SetConsoleTextAttribute(hConsole, 238);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 204);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 204);
				cout << ' ';
			}
		}
		gotoxy(8 * 11 + 1, 2 * 8 + 4 + i);
	}
}

void Viewer::printResult(Board& board, string winner)
{
//   ____                         ___
//  / ___| __ _ _ __ ___   ___   / _ \__   _____ _ __
// | |  _ / _` | '_ ` _ \ / _ \ | | | \ \ / / _ \ '__|
// | |_| | (_| | | | | | |  __/ | |_| |\ V /  __/ |
//  \____|\__,_|_| |_| |_|\___|  \___/  \_/ \___|_|
	printBoard(board);

	gotoxy(1 * 11, 3 * 8);
	for (int i = 1; i <= 16; i++)
	{
		for (int j = 1; j <= 66; j++)
		{
			if (i == 1 || i == 16 || j == 1 || j == 66)
			{
				SetConsoleTextAttribute(hConsole, 136);
				cout << ' ';
			}
			else if (i == 2)
			{
				SetConsoleTextAttribute(hConsole, originalColor);
				cout << "        ____                         ___                        ";
				SetConsoleTextAttribute(hConsole, 136);
				cout << ' ';
				break;
			}
			else if (i == 3)
			{
				SetConsoleTextAttribute(hConsole, originalColor);
				cout << "       / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __        ";
				SetConsoleTextAttribute(hConsole, 136);
				cout << ' ';
				break;
			}
			else if (i == 4)
			{
				SetConsoleTextAttribute(hConsole, originalColor);
				cout << "      | |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|       ";
				SetConsoleTextAttribute(hConsole, 136);
				cout << ' ';
				break;
			}
			else if (i == 5)
			{
				SetConsoleTextAttribute(hConsole, originalColor);
				cout << "      | |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |          ";
				SetConsoleTextAttribute(hConsole, 136);
				cout << ' ';
				break;
			}
			else if (i == 6)
			{
				SetConsoleTextAttribute(hConsole, originalColor);
				cout << "       \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|          ";
				SetConsoleTextAttribute(hConsole, 136);
				cout << ' ';
				break;
			}
			else
			{
				SetConsoleTextAttribute(hConsole, originalColor);
				cout << ' ';
			}
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		gotoxy(1 * 11, 3 * 8 + i);
	}

	gotoxy(3 * 11, 4 * 8);
	if (winner == "Draw")
		cout << "Draw！";
	else if(winner == "Times Up！")
		cout << "Times Up！";
	else
		cout << "The Winner is " << winner << "！";

	gotoxy(3 * 11, 4 * 8 + 3);
	cout << "Press Any Key To Menu";
	goToEnd();
}

void Viewer::printMenu()
{
	system("cls");
	cout << "          _____                    _____                    _____                    _____                    _____          " << endl;
	cout << "         /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\" << endl;
	cout << "        /::\\    \\                /::\\____\\                /::\\    \\                /::\\    \\                /::\\    \\" << endl;
	cout << "       /::::\\    \\              /:::/    /               /::::\\    \\              /::::\\    \\              /::::\\    \\" << endl;
	cout << "      /::::::\\    \\            /:::/    /               /::::::\\    \\            /::::::\\    \\            /::::::\\    \\" << endl;
	cout << "     /:::/\\:::\\    \\          /:::/    /               /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\" << endl;
	cout << "    /:::/  \\:::\\    \\        /:::/____/               /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\" << endl;
	cout << "   /:::/    \\:::\\    \\      /::::\\    \\              /::::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\" << endl;
	cout << "  /:::/    / \\:::\\    \\    /::::::\\    \\   _____    /::::::\\   \\:::\\    \\    ___\\:::\\   \\:::\\    \\    ___\\:::\\   \\:::\\    \\" << endl;
	cout << " /:::/    /   \\:::\\    \\  /:::/\\:::\\    \\ /\\    \\  /:::/\\:::\\   \\:::\\    \\  /\\   \\:::\\   \\:::\\    \\  /\\   \\:::\\   \\:::\\    \\" << endl;
	cout << "/:::/____/     \\:::\\____\\/:::/  \\:::\\    /::\\____\\/:::/__\\:::\\   \\:::\\____\\/::\\   \\:::\\   \\:::\\____\\/::\\   \\:::\\   \\:::\\____\\" << endl;
	cout << "\\:::\\    \\      \\::/    /\\::/    \\:::\\  /:::/    /\\:::\\   \\:::\\   \\::/    /\\:::\\   \\:::\\   \\::/    /\\:::\\   \\:::\\   \\::/    /" << endl;
	cout << " \\:::\\    \\      \\/____/  \\/____/ \\:::\\/:::/    /  \\:::\\   \\:::\\   \\/____/  \\:::\\   \\:::\\   \\/____/  \\:::\\   \\:::\\   \\/____/" << endl;
	cout << "  \\:::\\    \\                       \\::::::/    /    \\:::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\       \\:::\\   \\:::\\    \\" << endl;
	cout << "   \\:::\\    \\                       \\::::/    /      \\:::\\   \\:::\\____\\       \\:::\\   \\:::\\____\\       \\:::\\   \\:::\\____\\" << endl;
	cout << "    \\:::\\    \\                      /:::/    /        \\:::\\   \\::/    /        \\:::\\  /:::/    /        \\:::\\  /:::/    /" << endl;
	cout << "     \\:::\\    \\                    /:::/    /          \\:::\\   \\/____/          \\:::\\/:::/    /          \\:::\\/:::/    /" << endl;
	cout << "      \\:::\\    \\                  /:::/    /            \\:::\\    \\               \\::::::/    /            \\::::::/    /" << endl;
	cout << "       \\:::\\____\\                /:::/    /              \\:::\\____\\               \\::::/    /              \\::::/    /" << endl;
	cout << "        \\::/    /                \\::/    /                \\::/    /                \\::/    /                \\::/    /" << endl;
	cout << "         \\/____/                  \\/____/                  \\/____/                  \\/____/                  \\/____/" << endl;
	
	gotoxy(53, 25);
	cout << "第12組 西洋棋專案";
	gotoxy(58, 27);
	cout << "請選擇";
	gotoxy(56, 28);
	cout << "0 本機對戰";
	gotoxy(58, 29);
	cout << "1 離開\n>";
}

void Viewer::printPromoteList(char player)
{
	int color = this->backColor;
	gotoxy(2 * 11 - 1, 3 * 8 - 1);

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 46; j++)
		{
			if (i == 1 || i == 10 || j == 1 || j == 45)
			{
				SetConsoleTextAttribute(hConsole, 136);
				cout << ' ';
			}
			else
				cout << ' ';
		}
		gotoxy(2 * 11 - 1, 3 * 8 - 1 + i);
	}

	if (player == 'W')
	{
		gotoxy(2 * 11, 3 * 8);
		this->backColor = 221;
		printWhiteRook(2 * 11, 3 * 8);
		gotoxy(3 * 11, 3 * 8);
		this->backColor = 204;
		printWhiteKnight(3 * 11, 3 * 8);
		gotoxy(4 * 11, 3 * 8);
		this->backColor = 221;
		printWhiteBishop(4 * 11, 3 * 8);
		gotoxy(5 * 11, 3 * 8);
		this->backColor = 204;
		printWhiteQueen(5 * 11, 3 * 8);
	}
	else if (player == 'B')
	{
		gotoxy(2 * 11, 3 * 8);
		this->backColor = 221;
		printBlackRook(2 * 11, 3 * 8);
		gotoxy(3 * 11, 3 * 8);
		this->backColor = 204;
		printBlackKnight(3 * 11, 3 * 8);
		gotoxy(4 * 11, 3 * 8);
		this->backColor = 221;
		printBlackBishop(4 * 11, 3 * 8);
		gotoxy(5 * 11, 3 * 8);
		this->backColor = 204;
		printBlackQueen(5 * 11, 3 * 8);
	}
	this->backColor = color;

	goToEnd();
}

void Viewer::printUndoButton()
{
	gotoxy(8 * 11 + 1, 3 * 8 + 4);
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j == 5)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 221);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if (j == 4 || j == 5)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 221);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 221);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j == 4 || j == 5)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 221);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j == 5)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 221);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 221);
				cout << ' ';
			}
		}
		gotoxy(8 * 11 + 1, 3 * 8 + 4 + i);
	}
}

void Viewer::printRedoButton()
{
	gotoxy(8 * 11 + 1, 4 * 8 + 4);
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 11; j++)
		{
			if (i == 2)
			{
				if (j == 7)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 204);
					cout << ' ';
				}
			}
			else if (i == 3)
			{
				if (j == 7 || j == 8)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 204);
					cout << ' ';
				}
			}
			else if (i == 4)
			{
				if (j >= 3 && j <= 9)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 204);
					cout << ' ';
				}
			}
			else if (i == 5)
			{
				if (j == 7 || j == 8)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 204);
					cout << ' ';
				}
			}
			else if (i == 6)
			{
				if (j == 7)
				{
					SetConsoleTextAttribute(hConsole, 240);
					cout << ' ';
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 204);
					cout << ' ';
				}
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 204);
				cout << ' ';
			}
		}
		gotoxy(8 * 11 + 1, 4 * 8 + 4 + i);
	}
}

void Viewer::printTime(int seconds) // 傳進經過秒數
{
	gotoxy(9 * 11, 1 * 8 + 1);
	SetConsoleTextAttribute(hConsole, originalColor);
	cout << (600 - seconds) / 60 << " Minutes " << (600 - seconds) % 60 << " Seconds Remaining        ";
	goToEnd();
}