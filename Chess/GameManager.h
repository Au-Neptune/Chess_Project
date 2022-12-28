#pragma once
#include "main.h"
#include "Player.h"
#include "Viewer.h"
#include "Board.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_LBUTTON) & 0x01) ? 1:0)

class GameManager
{
public:
	Player* player[2];
	int current_player; // 0 white, 1 black
	Board board;
	Viewer viewer;
	string winner;
	vector<Board> history;
	bool pressUndo;
	int nowBoard;
	clock_t startT;
	vector<string> log;

	GameManager()
	{
		this->current_player = 0;
		player[0] = new HumanPlayer('W');
		player[1] = new HumanPlayer('B');
		this->winner = "";
		this->pressUndo = false;
		this->history.clear();
		this->nowBoard = 0;
		this->startT = clock();
		this->log.clear();
	}

	void changePlayer()
	{
		if (current_player == 0)
			current_player = 1;
		else
			current_player = 0;
	}

	bool isMoveVaild(Position pos, vector <Position> list)
	{
		for (int i = 0; i < list.size(); i++)
			if (list[i].x == pos.x && list[i].y == pos.y)
				return true;
		//cout << "移動不合法！" << endl;
		return false;
	}

	bool reachEnd(Position pos, int player)
	{
		if (player == 0 && pos.y == 0) // 白
			return true;
		else if (player == 1 && pos.y == 7)
			return true;
		return false;
	}

	bool checkPlayer(Position pos, int player)
	{
		if (player == 0 && board.board[pos.y][pos.x].player == 'W') // 白
			return true;
		else if (player == 1 && board.board[pos.y][pos.x].player == 'B')
			return true;

		//cout << "該棋子不是你的" << endl;
		return false;
	}

	bool isPosValid(int x, int y)
	{
		if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
			return true;
		return false;
	}

	bool isInList(Position pos, vector<Position>list)
	{
		for (int i = 0; i < list.size(); i++)
			if (pos.x == list[i].x && pos.y == list[i].y)
				return true;
		return false;
	}

	bool isCheckMate()
	{
		if (!board.isBlackKingDanger() && !board.isWhiteKingDanger())
			return false;

		char player = (current_player == 0 ? 'W' : 'B'); // 看能不能動
		bool result = true;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board.board[i][j].player == player)
				{
					Position pos;
					pos.x = j, pos.y = i;
					vector<Position> list = board.getValidPos(pos); // 棋子可走路徑
					// 每一步都試過
					for (int k = 0; k < list.size(); k++)
					{
						if (current_player == testMove(pos, list[k]))
							result = result && true;
						else
							result = result && false;
					}
				}
			}
		}
		if (result)
			winner = (player == 'W' ? "Black" : "White");

		return result;
	}

	bool isNothingCanMove()
	{
		if (board.isBlackKingDanger() || board.isWhiteKingDanger())
			return false;
		
		char player = (current_player == 0 ? 'W' : 'B'); // 看能不能動
		bool result = true;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board.board[i][j].player == player)
				{
					Position pos;
					pos.x = j, pos.y = i;
					vector<Position> list = board.getValidPos(pos); // 棋子可走路徑
					// 每一步都試過
					for (int k = 0; k < list.size(); k++)
					{
						if (current_player == testMove(pos, list[k]))
							result = result && true;
						else
							result = result && false;
					}
				}
			}
		}
		if (result)
			winner = "Draw";
		
		return result;
	}

	bool clickMyChess(Position pos)
	{
		if (!isPosValid(pos.x, pos.y))
			return false;

		if (current_player == 0)
		{
			if (board.board[pos.y][pos.x].player == 'W')
				return true;
		}
		else
		{
			if (board.board[pos.y][pos.x].player == 'B')
				return true;
		}
		return false;
	}

	void specialPawn(Position pos1, Position pos2)
	{
		if (current_player == 0) // White
		{
			if (pos1.y == 6 && pos2.y == 4 && board.board[pos2.y][pos2.x].type == "Pawn")
			{
				// 左右
				for (int i = -1; i < 2; i += 2)
				{
					if (isPosValid(pos2.x + i, pos2.y))
					{
						if (board.board[pos2.y][pos2.x + i].type == "Pawn" && board.board[pos2.y][pos2.x + i].player == 'B')
							board.board[pos2.y][pos2.x + i].specialPawn = -i;
					}
				}
			}
		}
		else if (current_player == 1)
		{
			if (pos1.y == 1 && pos2.y == 3 && board.board[pos2.y][pos2.x].type == "Pawn")
			{
				// 左右
				for (int i = -1; i < 2; i += 2)
				{
					if (isPosValid(pos2.x + i, pos2.y))
					{
						if (board.board[pos2.y][pos2.x + i].type == "Pawn" && board.board[pos2.y][pos2.x + i].player == 'W')
							board.board[pos2.y][pos2.x + i].specialPawn = -i;
					}
				}
			}
		}
	}

	/*void printDisplayBoard(vector<Position> list)
	{
		char displayBoard[8][8];
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				displayBoard[i][j] = ' ';

		for (int i = 0; i < list.size(); i++)
			displayBoard[list[i].y][list[i].x] = 'X';

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (displayBoard[i][j] == ' ')
					displayBoard[i][j] = board.board[i][j].icon;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board.board[i][j].player == 'B')
				{
					if (board.board[i][j].isDanger)
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout << displayBoard[i][j];
					}
					else
					{
						SetConsoleTextAttribute(hConsole, 11);
						cout << displayBoard[i][j];
					}
				}
				else if (board.board[i][j].player == 'W')
				{
					if (board.board[i][j].isDanger)
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout << displayBoard[i][j];
					}
					else
					{
						SetConsoleTextAttribute(hConsole, 7);
						cout << displayBoard[i][j];
					}
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 14);
					cout << displayBoard[i][j];
				}
			}
			cout << endl;
		}
	}*/

	Position getMousePosition()
	{
		Position pos;
		clock_t second = clock();
		while (1)
		{
			clock_t endT = clock();
			if ((600 - (endT - startT) / (CLOCKS_PER_SEC)) <= 0)
			{
				pos = { -1,-1 };
				return pos;
			}
			if (endT > (second + 1))
			{
				viewer.printTime((endT - startT) / (CLOCKS_PER_SEC));
				second = endT;
			}
			if (KEY_DOWN(MOUSE_EVENT))
			{
				POINT p;
				if (GetCursorPos(&p))
				{
					// Y 起始值 23 一格 113
					// X 起始值  0 一格 77
					// cout << p.x << " " << p.y << endl;
					if (p.x >= 623 && p.x <= 699 && p.y >= 302 && p.y <= 414)
					{
						pos = { 10,0 };
						return pos;
					}
					if (p.x >= 623 && p.x <= 699 && p.y >= 415 && p.y <= 527)
					{
						pos = { 10,1 };
						return pos;
					}
					if (p.x >= 623 && p.x <= 699 && p.y >= 528 && p.y <= 640)
					{
						pos = { 10,2 };
						return pos;
					}
					pos.x = p.x / 77;
					pos.y = (p.y - 22) / 112;

					//cout << pos.x << " " << pos.y << endl;
					if (pos.x > 7 || pos.y > 7)
						continue;

					return pos;
				}
			}
		}
	}

	// 開獨立板子試走看看會不會導致王被將軍
	// 回傳值為只要被將軍就回傳player代碼
	int testMove(Position fromPos, Position toPos)
	{
		Board newboard;

		newboard.board = board.board;
		newboard.blackKing = board.blackKing;
		newboard.whiteKing = board.whiteKing;

		player[current_player]->OnMove(newboard, fromPos, toPos);

		newboard.update();

		if (current_player == 0)
		{
			if (newboard.isWhiteKingDanger())
				return 0;
			if (newboard.isBlackKingDanger())
				return 1;
		}
		else
		{
			if (newboard.isBlackKingDanger())
				return 1;
			if (newboard.isWhiteKingDanger())
				return 0;
		}
	}

	void saveLogFile()
	{
		fstream file("log.txt", ios::out);
		for (int i = 0; i < log.size(); i++)
			file << log[i] << endl;
		file.close();
	}

	void gameLoop()
	{
		while (1)
		{
			vector<Position> list;
			Position pos, pos2;
			pos2.x = 8, pos2.y = 8;
			clock_t endT = clock();
			int index = history.size();// history資料數
			history.push_back(board);

			if (isNothingCanMove()) // 檢查無子可動
			{
				string result = winner;
				log.push_back(result);
				saveLogFile();
				viewer.printResult(board, winner);
				_getch();
				break;
			}
			if (isCheckMate()) // 檢查將死
			{
				string result = winner + " Win！";
				log.push_back(result);
				saveLogFile();
				viewer.printResult(board, winner);
				_getch();
				break;
			}

			// 滑鼠點擊後事件，如有不符合正常動作就會continue
			while(1)
			{
				viewer.printBoard(board);
				viewer.printNowPlayer(current_player);

				if (clickMyChess(pos2))
					pos = pos2;
				else
					pos = getMousePosition();

				if (pos.x == 10 && pos.y == 0)// 投降
				{
					winner = (current_player == 0 ? "Black" : "White");
					string result = winner + " Surrender";
					log.push_back(result);
					saveLogFile();
					viewer.printResult(board, winner);
					_getch();
					break;
				}
				if (pos.x == 10 && pos.y == 1)// Undo
				{
					if (index > 0)
					{
						this->board = history[--index];
						this->pressUndo = true;
						this->nowBoard = index;
						changePlayer();
						continue;
					}
					else
						continue;
				}
				if (pos.x == 10 && pos.y == 2)// Redo
				{
					if (index < history.size() - 1)
					{
						board = history[++index];
						changePlayer();
						continue;
					}
					else
						continue;
				}
				if (pos.x == -1 && pos.y == -1)// 時間到
				{
					winner = "Times Up！";
					string result = winner;
					log.push_back(result);
					saveLogFile();
					viewer.printResult(board, winner);
					_getch();
					break;
				}
				if (pressUndo)// 按Undo後行動要把多的分支pop掉
				{
					for (int i = history.size() - 1; i > index; i--)
					{
						history.pop_back();
						log.pop_back();
					}
				}

				pressUndo = false;
				if (!checkPlayer(pos, current_player)) // 確認棋子是不是自己的
					continue;

				list = board.getValidPos(pos); // 可走路徑
				if (list.empty())
				{
					// 死棋
					pos2 = { 8,8 };
					continue;
				}

				viewer.printDisplayBoard(board, list);
				viewer.printNowPlayer(current_player);

				pos2 = getMousePosition();

				if (clickMyChess(pos2)) // 點自己的棋 = 換棋子走
					continue;

				while (!isMoveVaild(pos2, list))
				{
					// 取得合法位置
					pos2 = getMousePosition();
				}

				// 假設移動後
				if (current_player == testMove(pos, pos2))
					continue;

				break;
			}
			
			if (winner != "") // 已經有贏家
				break;
			
			player[current_player]->OnMove(board, pos, pos2);
			string nowPlayer = (current_player == 0 ? "White" : "Black");
			string nowLog = "Player " + nowPlayer + " Moved " + board.board[pos2.y][pos2.x].type + " From " + to_string(pos.x) + "." + to_string(pos.y) + " to " + to_string(pos2.x) + "." + to_string(pos2.y);
			log.push_back(nowLog);

			if (board.board[pos2.y][pos2.x].type == "Pawn") // 晉升事件
			{
				if (reachEnd(pos2, current_player))
				{
					Position pos;
					string str;
					viewer.printPromoteList((current_player == 0) ? 'W' : 'B');
					pos = getMousePosition();

					if (pos.x == 2 && pos.y == 3)
						str = "Rook";
					else if (pos.x == 3 && pos.y == 3)
						str = "Knight";
					else if (pos.x == 4 && pos.y == 3)
						str = "Bishop";
					else if (pos.x == 5 && pos.y == 3)
						str = "Queen";

					string promoteLog = "Player " + nowPlayer + " Promoted to " + str + " At " + to_string(pos2.x) + "." + to_string(pos2.y);
					log.push_back(promoteLog);
					player[current_player]->OnPromote(board, pos2, str);
				}
			}

			board.update(); // 一些重置
			specialPawn(pos, pos2); // 過路兵事件
			changePlayer();
		}
	}

	int menu()
	{
		char selection;
		viewer.printMenu();
		cin >> selection;

		if (selection == '1')
			return 1;
		else if(selection == '0')
		{
			system("cls");
			this->startT = clock();
			gameLoop();
		}
	}
};