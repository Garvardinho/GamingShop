#pragma once
#include "header.h"
#include "game.h"

class Chain 
{
protected:
	Chain *next;				// Next link
	list <Game>game_list;		// Game list
	virtual void result() = 0;	// Search result

public:
	Chain();
	virtual ~Chain();

	Chain* setNext(Chain* Chain);
	int search(string title, string platform);
	void write_to_file(string file);
	void read_from_file(string file);
};