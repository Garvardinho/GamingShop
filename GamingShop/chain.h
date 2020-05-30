#pragma once
#include "header.h"
#include "game.h"

class Ñhain 
{
protected:
	Ñhain *next;				// Next link
	list <Game>game_list;		// Game list
	virtual void result() = 0;	// Search result

public:
	Ñhain();
	virtual ~Ñhain();

	Ñhain* setNext(Ñhain* ñhain);
	int search(string title, string platform);
	void write_to_file(string file);
	void read_from_file(string file);
};