#pragma once
#include "header.h"
#include "game.h"

class �hain 
{
protected:
	�hain *next;				// �������� �����
	Game *game_list;			// ������ � ������
	int game_list_size;			// ������ ������� � ������
	virtual void result() = 0;	// ��������� ��������� ����

public:
	�hain();
	virtual ~�hain();

	�hain* setNext(�hain* �hain);
	int search();
	void write_to_file(string file);
	void read_from_file(string file);
};