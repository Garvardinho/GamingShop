#pragma once
#include "header.h"
#include "game.h"

class Сhain 
{
protected:
	Сhain *next;						// следущее звено
	Game *game_list;					// массив с играми
	int size_of_game_list;				// размер массива с играми
	virtual void result() = 0;			// результат найденной игры

public:
	Сhain();
	virtual ~Сhain();

	Сhain* setNext(Сhain* сhain);
	void search(Game* game);
	void add_to_file(string file);
	void write_to_file(string file, int add_val);
	void read_from_file(string file);
};