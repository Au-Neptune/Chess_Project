#pragma once
#include "main.h"
#include "Board.h"

class Player {
public:
	virtual void OnMove(Board& board, Position& outFromPos, Position& outToPos) = 0; // 選擇要從 fromPos 走到 toPos
	virtual void OnPromote(Board& board, Position& pawnPos, string type) = 0; // 選擇升階類型
};

class HumanPlayer : public Player {
public:
	char color;

	HumanPlayer(char color)
	{
		this->color = color;
	}

	bool checkPlayer(Board& board, Position& pos)
	{
		if (board.board[pos.y][pos.x].player != this->color)
			return false;
		return true;
	}

	void OnMove(Board& board, Position& fromPos, Position& toPos)
	{
		if (!checkPlayer(board, fromPos))
			return;

		board.move(fromPos, toPos);

		if (board.board[toPos.y][toPos.x].specialPawn != 0)
		{
			Chess chess;
			if (board.board[toPos.y][toPos.x].player == 'W')
				board.board[toPos.y + 1][toPos.x] = chess;
			else
				board.board[toPos.y - 1][toPos.x] = chess;
		}

		if (board.board[toPos.y][toPos.x].type == "King")
		{
			if (board.board[toPos.y][toPos.x].player == 'W')
				board.whiteKing = toPos;
			else
				board.blackKing = toPos;
		}
	}

	void OnPromote(Board& board, Position& pawnPos, string type)
	{
		char icon = ' ';
		board.board[pawnPos.y][pawnPos.x].type = type;
		if (type == "Rook")
			icon = 'R';
		else if (type == "Knight")
			icon = 'N';
		else if (type == "Bishop")
			icon = 'B';
		else if (type == "Queen")
			icon = 'Q';
		board.board[pawnPos.y][pawnPos.x].icon = icon;
	}
};