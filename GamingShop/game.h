#pragma once

class Game 
{
private:
	friend class Сhain;
	char name[50];			//название
	char genre[20];			//жанр
	int year;				//год выпуска
	char platform[10];		//платформа (ПК, Xbox, PS)
	char sys_req[100];		//системные требования
	char developer[30];		//разработчик
	int quantity;			//количество

public:
	Game();
	Game(char* name1, char* genre1, int year1, char* platform1, char* sys_req1, char* developer1, int quantity1);
	void set_game(void);
	void show_game(void);
};