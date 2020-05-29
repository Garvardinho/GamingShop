#include "header.h"
#include "chain.h"
#include "game.h"

�hain::�hain()
{
	next = nullptr;
	game_list = nullptr;
	game_list_size = 0;
}

�hain::~�hain()
{
	if (game_list)
		delete[] game_list;

	if (next)
		delete next;
}

�hain *�hain::setNext(�hain *�hain)
{
	next = �hain;
	return next;
}

int �hain::search()  // Search games by title and platform
{
	if (game_list_size == 0)
	{
		cout << "There are no games!" << endl;
		getchar();
		return -1;
	}

	bool flag = false;
	string title, platform;

	do
	{
		cout << "Title: " << endl;
		getline(cin, title);
	} while (!str_valid(title));

	while (true)
	{
		cout << "Gaming platform: ";
		getline(cin, platform);

		if (platform == "PC" || platform == "Xbox" || platform == "PS")
			break;
	}

	for (int i = 0; i < game_list_size; i++)
		if (game_list[i].title == title && game_list[i].platform == platform)
			flag = true;

	if (flag)
	{
		result();
		return 0;
	}
	else
	{
		if (next)
			return next->search();
		else
		{
			cout << "The game was not found" << endl;
			return -1;
		}
	}
}

void �hain::write_to_file(string file)
{
	int add_val;
	string tmp_str;

	while (true)
	{
		cout << "How much games do you want to add: ";
		getline(cin, tmp_str);
		add_val = atoi(tmp_str.c_str());
		if (num_valid(tmp_str))
			break;
	}

	game_list_size += add_val;

	ofstream out;
	Game tmp;
	try
	{
		out.open(file, ios::out);
		if (!out.is_open())
			throw exception("File can not be opened!");

		out.write(reinterpret_cast<char*>(&game_list_size), sizeof(int));

		for (int i = 0; i < game_list_size - add_val; i++)
			out.write(reinterpret_cast<char*>(&game_list[i]), sizeof(Game)); // �������������� ���������� gamelist

		for (int i = 0; i < add_val; i++)
		{
			tmp.set_game();
			out.write(reinterpret_cast<char*>(&tmp), sizeof(Game)); // ��������� ����� ������
		}
		out.close();
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}
}

void �hain::read_from_file(string file)
{
	ifstream in;
	try
	{
		in.open(file, ios::in);
		if (!in.is_open())
			throw exception("File can not be opened!");

		if (in.peek() == EOF)
			throw exception("File is empty!");

		in.read(reinterpret_cast<char*>(&game_list_size), sizeof(int));
		game_list = new Game[game_list_size];
		for (int i = 0; i < game_list_size; i++)
		{
			in.read(reinterpret_cast<char*>(&game_list[i]), sizeof(Game));
			game_list[i].show_game();
		}
		in.close();
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}
}