#pragma once

class Game 
{
private:
	friend class �hain;
	string title;
	string genre;
	int year;
	string platform;
	string sys_req;
	string developer;
	int quantity;

public:
	Game();
	~Game();
	void set_game();
};