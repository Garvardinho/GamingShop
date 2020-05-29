#pragma once

class Game 
{
private:
	friend class Сhain;
	string name;			//название
	string genre;			//жанр
	int year;				//год выпуска
	string platform;		//платформа (ПК, Xbox, PS)
	string sys_req;			//системные требования
	string developer;		//разработчик
	int quantity;			//количество

public:
	Game();
	void set_game();
	void show_game();
};