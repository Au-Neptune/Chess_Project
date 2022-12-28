#pragma once
#include "main.h"

class Chess
{
public:
	string type; // �Ѥl����
	char player; // �Ѥl�ݩ���� (White / Balck)
	Position pos; // �Ѥl��m
	char icon; // �Ѥl���N��Ÿ�
	bool moved;
	int specialPawn;
	bool isDanger;

	Chess()
	{
		this->pos.x = 1;
		this->pos.y = 1;
		this->type = "Nothing";
		this->icon = ' ';
		this->player = ' ';
		this->moved = false;
		this->specialPawn = 0;
		this->isDanger = false;
	}

	Chess(int x, int y)
	{
		this->pos.x = x;
		this->pos.y = y;
		this->type = "Nothing";
		this->icon = ' ';
		this->player = ' ';
		this->moved = false;
		this->specialPawn = 0;
		this->isDanger = false;
	}

	Chess(int x, int y, char player, string type, char icon)
	{
		this->pos.x = x;
		this->pos.y = y;
		this->type = type;
		this->icon = icon;
		this->player = player;
		this->moved = false;
		this->specialPawn = 0;
		this->isDanger = false;
	}

	Chess(Position& pos, char player, string type, char icon)
	{
		this->pos = pos;
		this->type = type;
		this->icon = icon;
		this->player = player;
		this->moved = false;
		this->specialPawn = 0;
		this->isDanger = false;
	}
};