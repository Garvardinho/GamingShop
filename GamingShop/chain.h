#pragma once
#include "header.h"
#include "game.h"

class �hain 
{
protected:
	�hain *next;						// �������� �����
	Game *game_list;					// ������ � ������
	int size_of_game_list;				// ������ ������� � ������
	virtual void result() = 0;			// ��������� ��������� ����

public:
	�hain();
	virtual ~�hain();

	�hain* setNext(�hain* �hain);
	void search(Game* game);
	void add_to_file(string file);
	void write_to_file(string file, int add_val);
	void read_from_file(string file);
};