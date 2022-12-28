#pragma once
#include "main.h"
#include "Chess.h"

class Board
{
public:
	vector< vector<Chess> > board;
	Position whiteKing, blackKing;

	Board()
	{
		for (int i = 0; i < 8; i++)
		{
			vector <Chess> temp;
			for (int j = 0; j < 8; j++)
			{
				if (i == 1)
				{
					Chess chess(j, i, 'B', "Pawn", 'P');
					temp.push_back(chess);
				}
				else if (i == 6)
				{
					Chess chess(j, i, 'W', "Pawn", 'P');
					temp.push_back(chess);
				}
				else if (i == 0)
				{
					if (j == 0 || j == 7)
					{
						Chess chess(j, i, 'B', "Rook", 'R');
						temp.push_back(chess);
					}
					else if (j == 1 || j == 6)
					{
						Chess chess(j, i, 'B', "Knight", 'N');
						temp.push_back(chess);
					}
					else if (j == 2 || j == 5)
					{
						Chess chess(j, i, 'B', "Bishop", 'B');
						temp.push_back(chess);
					}
					else if (j == 3)
					{
						Chess chess(j, i, 'B', "Queen", 'Q');
						temp.push_back(chess);
					}
					else if (j == 4)
					{
						Chess chess(j, i, 'B', "King", 'K');
						Position king;
						king.x = j, king.y = i;
						this->blackKing = king;
						temp.push_back(chess);
					}
				}
				else if (i == 7)
				{
					if (j == 0 || j == 7)
					{
						Chess chess(j, i, 'W', "Rook", 'R');
						temp.push_back(chess);
					}
					else if (j == 1 || j == 6)
					{
						Chess chess(j, i, 'W', "Knight", 'N');
						temp.push_back(chess);
					}
					else if (j == 2 || j == 5)
					{
						Chess chess(j, i, 'W', "Bishop", 'B');
						temp.push_back(chess);
					}
					else if (j == 3)
					{
						Chess chess(j, i, 'W', "Queen", 'Q');
						temp.push_back(chess);
					}
					else if (j == 4)
					{
						Chess chess(j, i, 'W', "King", 'K');
						Position king;
						king.x = j, king.y = i;
						this->whiteKing = king;
						temp.push_back(chess);
					}
				}
				else
				{
					Chess chess(j, i);
					temp.push_back(chess);
				}
			}
			board.push_back(temp);
		}
	}

	//Board()
	//{
	//	for (int i = 0; i < 8; i++)// y
	//	{
	//		vector<Chess> temp;
	//		for (int j = 0; j < 8; j++)// x
	//		{
	//			if (j == 4 && i == 5)
	//			{
	//				Chess chess(4, 5, 'B', "King", 'K');
	//				this->blackKing = { 4,5 };
	//				temp.push_back(chess);
	//			}
	//			else if (j == 3 && i == 5)
	//			{
	//				Chess chess(3, 5, 'B', "Queen", 'Q');
	//				temp.push_back(chess);
	//			}
	//			else if (j == 0 && i == 7)
	//			{
	//				Chess chess(0, 7, 'B', "Rook", 'R');
	//				temp.push_back(chess);
	//			}
	//			else if (j == 4 && i == 7)
	//			{
	//				Chess chess(4, 7, 'W', "King", 'K');
	//				this->whiteKing = { 4,7 };
	//				temp.push_back(chess);
	//			}
	//			else if (j == 2 && i == 6)
	//			{
	//				Chess chess(2, 6, 'W', "Bishop", 'B');
	//				temp.push_back(chess);
	//			}
	//			else
	//			{
	//				Chess chess(j, i);
	//				temp.push_back(chess);
	//			}
	//		}
	//		board.push_back(temp);
	//	}
	//}

	//void draw()
	//{
	//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//	for (int i = 0; i < 8; i++)
	//	{
	//		for (int j = 0; j < 8; j++)
	//		{
	//			if (board[i][j].player == 'B')
	//			{
	//				if (board[i][j].isDanger)
	//				{
	//					SetConsoleTextAttribute(hConsole, 12);
	//					cout << board[i][j].icon;
	//				}
	//				else
	//				{
	//					SetConsoleTextAttribute(hConsole, 11);
	//					cout << board[i][j].icon;
	//				}
	//			}
	//			else if (board[i][j].player == 'W')
	//			{
	//				if (board[i][j].isDanger)
	//				{
	//					SetConsoleTextAttribute(hConsole, 12);
	//					cout << board[i][j].icon;
	//				}
	//				else
	//				{
	//					SetConsoleTextAttribute(hConsole, 7);
	//					cout << board[i][j].icon;
	//				}
	//			}
	//			else
	//			{
	//				//SetConsoleTextAttribute(hConsole, 12);
	//				cout << board[i][j].icon;
	//			}
	//		}
	//		cout << endl;
	//	}
	//}

	void move(Position& fromPos, Position& toPos)
	{
		Chess chess;

		// 白棋短易位
		if(fromPos.x == 4 && fromPos.y == 7 && toPos.x == 6 && toPos.y == 7 && board[fromPos.y][fromPos.x].type == "King")
		{
			// Move Rook
			board[7][7].pos.y = 7;
			board[7][7].pos.x = 5;
			board[7][7].moved = true;

			board[7][5] = board[7][7];
			board[7][7] = chess;
		}
		// 黑棋短易位
		if (fromPos.x == 4 && fromPos.y == 0 && toPos.x == 6 && toPos.y == 0 && board[fromPos.y][fromPos.x].type == "King")
		{
			// Move Rook
			board[0][7].pos.y = 0;
			board[0][7].pos.x = 5;
			board[0][7].moved = true;

			board[0][5] = board[0][7];
			board[0][7] = chess;
		}
		// 白棋長易位
		if (fromPos.x == 4 && fromPos.y == 7 && toPos.x == 2 && toPos.y == 7 && board[fromPos.y][fromPos.x].type == "King")
		{
			// Move Rook
			board[7][0].pos.y = 7;
			board[7][0].pos.x = 3;
			board[7][0].moved = true;

			board[7][3] = board[7][0];
			board[7][0] = chess;
		}
		// 黑棋長易位
		if (fromPos.x == 4 && fromPos.y == 0 && toPos.x == 2 && toPos.y == 0 && board[fromPos.y][fromPos.x].type == "King")
		{
			// Move Rook
			board[0][0].pos.y = 0;
			board[0][0].pos.x = 3;
			board[0][0].moved = true;

			board[0][3] = board[0][0];
			board[0][0] = chess;
		}

		board[fromPos.y][fromPos.x].pos.y = toPos.y;
		board[fromPos.y][fromPos.x].pos.x = toPos.x;
		board[fromPos.y][fromPos.x].moved = true;

		board[toPos.y][toPos.x] = board[fromPos.y][fromPos.x];
		board[fromPos.y][fromPos.x] = chess;
	}

	bool isValid(Position& pos)
	{
		if (pos.x >= 0 && pos.x <= 7 && pos.y >= 0 && pos.y <= 7)
			return true;
		return false;
	}

	bool isValid(int x, int y)
	{
		if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
			return true;
		return false;
	}

	void update()
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				board[i][j].specialPawn = false;
			}
		}

		if (isBlackKingDanger())
			board[blackKing.y][blackKing.x].isDanger = true;
		else
			board[blackKing.y][blackKing.x].isDanger = false;

		if (isWhiteKingDanger())
			board[whiteKing.y][whiteKing.x].isDanger = true;
		else
			board[whiteKing.y][whiteKing.x].isDanger = false;

	}

	vector<Position> getOpponetAllValid(char player)
	{
		vector<Position> list;
		char opponent = (player == 'W' ? 'B' : 'W');
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j].player == opponent)
				{
					vector<Position> temp;
					temp = getValidPos(board[i][j].pos);
					list.insert(list.end(), temp.begin(), temp.end());
				}
			}
		}
		return list;
	}

	bool isBlackKingDanger()
	{
		bool danger = false;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j].player == 'W')
				{
					vector<Position> temp;
					temp = getValidPos(board[i][j].pos);
					for (int k = 0; k < temp.size(); k++)
					{
						if (temp[k].x == blackKing.x && temp[k].y == blackKing.y)
							danger = true;
					}
				}
			}
		}
		return danger;
	}

	bool isWhiteKingDanger()
	{
		bool danger = false;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j].player == 'B')
				{
					vector<Position> temp;
					temp = getValidPos(board[i][j].pos);

					for (int k = 0; k < temp.size(); k++)
					{
						if (temp[k].x == whiteKing.x && temp[k].y == whiteKing.y)
							danger = true;
					}
				}
			}
		}
		return danger;
	}

	bool isBeingAttack(Position pos,char player)
	{
		vector<Position> list = getOpponetAllValid(player);

		for (int i = 0; i < list.size(); i++)
		{
			if (pos.x == list[i].x && pos.y == list[i].y)
				return true;
		}
		return false;
	}

	vector<Position> getRookPos(Position& pos, char player)
	{
		Position newPos;
		vector <Position> posList;
		char opponent = ' ';

		if (player == 'B')
			opponent = 'W';
		else if (player == 'W')
			opponent = 'B';

		// 向右找
		for (int i = 1; i < 8; i++)
		{
			if (isValid(pos.x + i, pos.y))
			{
				if (board[pos.y][pos.x + i].type == "Nothing")
				{
					newPos.x = pos.x + i;
					newPos.y = pos.y;
					posList.push_back(newPos);
				}
				else
				{
					if (board[pos.y][pos.x + i].player == opponent)
					{
						newPos.x = pos.x + i;
						newPos.y = pos.y;
						posList.push_back(newPos);
					}
					break;
				}
			}
			else
				break;
		}
		// 向左找
		for (int i = 1; i < 8; i++)
		{
			if (isValid(pos.x - i, pos.y))
			{
				if (board[pos.y][pos.x - i].type == "Nothing")
				{
					newPos.x = pos.x - i;
					newPos.y = pos.y;
					posList.push_back(newPos);
				}
				else
				{
					if (board[pos.y][pos.x - i].player == opponent)
					{
						newPos.x = pos.x - i;
						newPos.y = pos.y;
						posList.push_back(newPos);
					}
					break;
				}
			}
			else
				break;
		}
		// 向下找
		for (int i = 1; i < 8; i++)
		{
			if (isValid(pos.x, pos.y + i))
			{
				if (board[pos.y + i][pos.x].type == "Nothing")
				{
					newPos.x = pos.x;
					newPos.y = pos.y + i;
					posList.push_back(newPos);
				}
				else
				{
					if (board[pos.y + i][pos.x].player == opponent)
					{
						newPos.x = pos.x;
						newPos.y = pos.y + i;
						posList.push_back(newPos);
					}
					break;
				}
			}
			else
				break;
		}
		// 向上找
		for (int i = 1; i < 8; i++)
		{
			if (isValid(pos.x, pos.y - i))
			{
				if (board[pos.y - i][pos.x].type == "Nothing")
				{
					newPos.x = pos.x;
					newPos.y = pos.y - i;
					posList.push_back(newPos);
				}
				else
				{
					if (board[pos.y - i][pos.x].player == opponent)
					{
						newPos.x = pos.x;
						newPos.y = pos.y - i;
						posList.push_back(newPos);
					}
					break;
				}
			}
			else
				break;
		}

		return posList;
	}

	vector<Position> getKnightPos(Position& pos, char player)
	{
		Position newPos;
		vector <Position> posList;
		char opponent = ' ';

		if (player == 'B')
			opponent = 'W';
		else if (player == 'W')
			opponent = 'B';

		newPos.x = pos.x + 1;
		newPos.y = pos.y + 2;
		if (isValid(newPos))
			if (board[newPos.y][newPos.x].player == opponent || board[newPos.y][newPos.x].type == "Nothing")
				posList.push_back(newPos);

		newPos.x = pos.x + 1;
		newPos.y = pos.y - 2;
		if (isValid(newPos))
			if (board[newPos.y][newPos.x].player == opponent || board[newPos.y][newPos.x].type == "Nothing")
				posList.push_back(newPos);

		newPos.x = pos.x - 1;
		newPos.y = pos.y + 2;
		if (isValid(newPos))
			if (board[newPos.y][newPos.x].player == opponent || board[newPos.y][newPos.x].type == "Nothing")
				posList.push_back(newPos);

		newPos.x = pos.x - 1;
		newPos.y = pos.y - 2;
		if (isValid(newPos))
			if (board[newPos.y][newPos.x].player == opponent || board[newPos.y][newPos.x].type == "Nothing")
				posList.push_back(newPos);

		newPos.x = pos.x + 2;
		newPos.y = pos.y + 1;
		if (isValid(newPos))
			if (board[newPos.y][newPos.x].player == opponent || board[newPos.y][newPos.x].type == "Nothing")
				posList.push_back(newPos);

		newPos.x = pos.x + 2;
		newPos.y = pos.y - 1;
		if (isValid(newPos))
			if (board[newPos.y][newPos.x].player == opponent || board[newPos.y][newPos.x].type == "Nothing")
				posList.push_back(newPos);

		newPos.x = pos.x - 2;
		newPos.y = pos.y + 1;
		if (isValid(newPos))
			if (board[newPos.y][newPos.x].player == opponent || board[newPos.y][newPos.x].type == "Nothing")
				posList.push_back(newPos);

		newPos.x = pos.x - 2;
		newPos.y = pos.y - 1;
		if (isValid(newPos))
			if (board[newPos.y][newPos.x].player == opponent || board[newPos.y][newPos.x].type == "Nothing")
				posList.push_back(newPos);

		return posList;
	}

	vector<Position> getBishopPos(Position& pos, char player)
	{
		Position newPos;
		vector <Position> posList;
		char opponent = ' ';

		if (player == 'B')
			opponent = 'W';
		else if (player == 'W')
			opponent = 'B';

		for (int i = 1; i < 8; i++)
		{
			if (isValid(pos.x + i, pos.y + i))
			{
				if (board[pos.y + i][pos.x + i].type == "Nothing")
				{
					newPos.x = pos.x + i;
					newPos.y = pos.y + i;
					posList.push_back(newPos);
				}
				else
				{
					if (board[pos.y + i][pos.x + i].player == opponent)
					{
						newPos.x = pos.x + i;
						newPos.y = pos.y + i;
						posList.push_back(newPos);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++)
		{
			if (isValid(pos.x + i, pos.y - i))
			{
				if (board[pos.y - i][pos.x + i].type == "Nothing")
				{
					newPos.x = pos.x + i;
					newPos.y = pos.y - i;
					posList.push_back(newPos);
				}
				else
				{
					if (board[pos.y - i][pos.x + i].player == opponent)
					{
						newPos.x = pos.x + i;
						newPos.y = pos.y - i;
						posList.push_back(newPos);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++)
		{
			if (isValid(pos.x - i, pos.y + i))
			{
				if (board[pos.y + i][pos.x - i].type == "Nothing")
				{
					newPos.x = pos.x - i;
					newPos.y = pos.y + i;
					posList.push_back(newPos);
				}
				else
				{
					if (board[pos.y + i][pos.x - i].player == opponent)
					{
						newPos.x = pos.x - i;
						newPos.y = pos.y + i;
						posList.push_back(newPos);
					}
					break;
				}
			}
			else
				break;
		}
		for (int i = 1; i < 8; i++)
		{
			if (isValid(pos.x - i, pos.y - i))
			{
				if (board[pos.y - i][pos.x - i].type == "Nothing")
				{
					newPos.x = pos.x - i;
					newPos.y = pos.y - i;
					posList.push_back(newPos);
				}
				else
				{
					if (board[pos.y - i][pos.x - i].player == opponent)
					{
						newPos.x = pos.x - i;
						newPos.y = pos.y - i;
						posList.push_back(newPos);
					}
					break;
				}
			}
			else
				break;
		}

		return posList;
	}

	vector<Position> getQueenPos(Position& pos, char player)
	{
		vector<Position> posList1;
		vector<Position> posList2;

		posList1 = getRookPos(pos, player);
		posList2 = getBishopPos(pos, player);

		posList1.insert(posList1.end(), posList2.begin(), posList2.end());

		return posList1;
	}

	vector<Position> getKingPos(Position& pos, char player)
	{
		Position newPos;
		vector <Position> posList;
		char opponent = ' ';

		if (player == 'B')
			opponent = 'W';
		else if (player == 'W')
			opponent = 'B';

		// 左上
		if (isValid(pos.x - 1, pos.y - 1))
			if (board[pos.y - 1][pos.x - 1].type == "Nothing" || board[pos.y - 1][pos.x - 1].player == opponent)
			{
				newPos.x = pos.x - 1;
				newPos.y = pos.y - 1;
				posList.push_back(newPos);
			}
		// 上
		if (isValid(pos.x, pos.y - 1))
			if (board[pos.y - 1][pos.x].type == "Nothing" || board[pos.y - 1][pos.x].player == opponent)
			{
				newPos.x = pos.x;
				newPos.y = pos.y - 1;
				posList.push_back(newPos);
			}
		// 右上
		if (isValid(pos.x + 1, pos.y - 1))
			if (board[pos.y - 1][pos.x + 1].type == "Nothing" || board[pos.y - 1][pos.x + 1].player == opponent)
			{
				newPos.x = pos.x + 1;
				newPos.y = pos.y - 1;
				posList.push_back(newPos);
			}
		// 左
		if (isValid(pos.x - 1, pos.y))
			if (board[pos.y][pos.x - 1].type == "Nothing" || board[pos.y][pos.x - 1].player == opponent)
			{
				newPos.x = pos.x - 1;
				newPos.y = pos.y;
				posList.push_back(newPos);
			}
		// 右
		if (isValid(pos.x + 1, pos.y))
			if (board[pos.y][pos.x + 1].type == "Nothing" || board[pos.y][pos.x + 1].player == opponent)
			{
				newPos.x = pos.x + 1;
				newPos.y = pos.y;
				posList.push_back(newPos);
			}
		// 左下
		if (isValid(pos.x - 1, pos.y + 1))
			if (board[pos.y + 1][pos.x - 1].type == "Nothing" || board[pos.y + 1][pos.x - 1].player == opponent)
			{
				newPos.x = pos.x - 1;
				newPos.y = pos.y + 1;
				posList.push_back(newPos);
			}
		// 下
		if (isValid(pos.x, pos.y + 1))
			if (board[pos.y + 1][pos.x].type == "Nothing" || board[pos.y + 1][pos.x].player == opponent)
			{
				newPos.x = pos.x;
				newPos.y = pos.y + 1;
				posList.push_back(newPos);
			}
		// 右下
		if (isValid(pos.x + 1, pos.y + 1))
			if (board[pos.y + 1][pos.x + 1].type == "Nothing" || board[pos.y + 1][pos.x + 1].player == opponent)
			{
				newPos.x = pos.x + 1;
				newPos.y = pos.y + 1;
				posList.push_back(newPos);
			}

		// 白棋短易位
		if (!board[pos.y][pos.x].moved && !board[7][7].moved && board[7][7].type == "Rook")
		{
			Position test1,test2;
			test1.x = pos.x + 1, test1.y = pos.y;
			test2.x = pos.x + 2, test2.y = pos.y;
			if (board[test1.y][test1.x].type == "Nothing" && board[test2.y][test2.x].type == "Nothing")
			{
				if (!isBeingAttack(test1, player) && !isBeingAttack(test2, player))
				{
					posList.push_back(test2);
				}
			}
		}

		// 黑棋短易位
		if (!board[pos.y][pos.x].moved && !board[0][7].moved && board[0][7].type == "Rook")
		{
			Position test1, test2;
			test1.x = pos.x + 1, test1.y = pos.y;
			test2.x = pos.x + 2, test2.y = pos.y;
			if (board[test1.y][test1.x].type == "Nothing" && board[test2.y][test2.x].type == "Nothing")
			{
				if (!isBeingAttack(test1, player) && !isBeingAttack(test2, player))
				{
					posList.push_back(test2);
				}
			}
		}

		// 白棋長易位
		if (!board[pos.y][pos.x].moved && !board[7][0].moved && board[7][0].type == "Rook")
		{
			Position test1, test2, test3;
			test1.x = pos.x - 1, test1.y = pos.y;
			test2.x = pos.x - 2, test2.y = pos.y;
			test3.x = pos.x - 3, test3.y = pos.y;

			if (board[test1.y][test1.x].type == "Nothing" && board[test2.y][test2.x].type == "Nothing" && board[test3.y][test3.x].type == "Nothing")
				if (!isBeingAttack(test1, player) && !isBeingAttack(test2, player))
					posList.push_back(test2);
		}

		// 黑棋長易位
		if (!board[pos.y][pos.x].moved && !board[0][0].moved && board[0][0].type == "Rook")
		{
			Position test1, test2, test3;
			test1.x = pos.x - 1, test1.y = pos.y;
			test2.x = pos.x - 2, test2.y = pos.y;
			test3.x = pos.x - 3, test3.y = pos.y;

			if (board[test1.y][test1.x].type == "Nothing" && board[test2.y][test2.x].type == "Nothing" && board[test3.y][test3.x].type == "Nothing")
				if (!isBeingAttack(test1, player) && !isBeingAttack(test2, player))
					posList.push_back(test2);
		}

		return posList;
	}

	vector<Position> getValidPos(Position& pos)
	{
		vector<Position> posList;

		if (board[pos.y][pos.x].type == "Pawn")
		{
			if (board[pos.y][pos.x].player == 'W')
			{
				if (!board[pos.y][pos.x].moved)
				{
					for (int i = 1; i <= 2; i++)
					{
						Position newPos;
						newPos.x = pos.x;
						newPos.y = pos.y - i;

						if (board[newPos.y][newPos.x].type == "Nothing")
							posList.push_back(newPos);
						else if (board[newPos.y][newPos.x].player == 'B')
							break;
					}
				}
				else
				{
					Position newPos;
					newPos.x = pos.x;
					newPos.y = pos.y - 1;

					// 往前
					if (isValid(newPos))
						if (board[newPos.y][newPos.x].type == "Nothing")
							posList.push_back(newPos);
				}
				// 斜角看是不是對手棋子
				for (int i = -1; i < 2; i += 2)
				{
					Position targetPos;
					targetPos.x = pos.x + i;
					targetPos.y = pos.y - 1;

					if (isValid(targetPos))
						if (board[targetPos.y][targetPos.x].player == 'B')
							posList.push_back(targetPos);
				}
				
				// 過路兵
				if (board[pos.y][pos.x].specialPawn != 0)
				{
					Position newPos;
					newPos.x = pos.x + board[pos.y][pos.x].specialPawn;
					newPos.y = pos.y;

					if (isValid(newPos))
					{
						if (board[newPos.y][newPos.x].type == "Pawn" && board[newPos.y][newPos.x].player == 'B')
						{
							newPos.y--;
							posList.push_back(newPos);
						}
					}
				}
			}
			else if (board[pos.y][pos.x].player == 'B')
			{
				if (!board[pos.y][pos.x].moved)
				{
					for (int i = 1; i <= 2; i++)
					{
						Position newPos;
						newPos.x = pos.x;
						newPos.y = pos.y + i;

						if (board[newPos.y][newPos.x].type == "Nothing")
							posList.push_back(newPos);
						else if (board[newPos.y][newPos.x].player == 'W')
							break;
					}
				}
				else
				{
					Position newPos;
					newPos.x = pos.x;
					newPos.y = pos.y + 1;

					// 往前
					if (isValid(newPos))
						if (board[newPos.y][newPos.x].type == "Nothing")
							posList.push_back(newPos);
				}
				// 斜角看是不是對手棋子
				for (int i = -1; i < 2; i += 2)
				{
					Position targetPos;
					targetPos.x = pos.x + i;
					targetPos.y = pos.y + 1;

					if (isValid(targetPos))
						if (board[targetPos.y][targetPos.x].player == 'W')
							posList.push_back(targetPos);
				}
				// 過路兵
				if (board[pos.y][pos.x].specialPawn != 0)
				{
					Position newPos;
					newPos.x = pos.x + board[pos.y][pos.x].specialPawn;
					newPos.y = pos.y;

					if (isValid(newPos))
					{
						if (board[newPos.y][newPos.x].type == "Pawn" && board[newPos.y][newPos.x].player == 'W')
						{
							newPos.y++;
							posList.push_back(newPos);
						}
					}
				}
			}
		}
		else if (board[pos.y][pos.x].type == "Knight")
		{
			posList = getKnightPos(pos, board[pos.y][pos.x].player);
		}
		else if (board[pos.y][pos.x].type == "Rook")
		{
			posList = getRookPos(pos, board[pos.y][pos.x].player);
		}
		else if (board[pos.y][pos.x].type == "Bishop")
		{
			posList = getBishopPos(pos, board[pos.y][pos.x].player);
		}
		else if (board[pos.y][pos.x].type == "Queen")
		{
			posList = getQueenPos(pos, board[pos.y][pos.x].player);
		}
		else if (board[pos.y][pos.x].type == "King")
		{
			posList = getKingPos(pos, board[pos.y][pos.x].player);
		}

		return posList;
	}
};