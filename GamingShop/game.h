#pragma once

class Game 
{
private:
	friend class �hain;
	string name;			//��������
	string genre;			//����
	int year;				//��� �������
	string platform;		//��������� (��, Xbox, PS)
	string sys_req;			//��������� ����������
	string developer;		//�����������
	int quantity;			//����������

public:
	Game();
	void set_game();
	void show_game();
};