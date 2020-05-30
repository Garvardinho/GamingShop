#pragma once
#include "header.h"
#include "game.h"

class �hain 
{
protected:
	�hain *next;				// Next link
	list <Game>game_list;		// Game list
	virtual void result() = 0;	// Search result

public:
	�hain();
	virtual ~�hain();

	�hain* setNext(�hain* �hain);
	int search(string title, string platform);
	void write_to_file(string file);
	void read_from_file(string file);
};