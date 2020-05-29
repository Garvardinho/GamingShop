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

int �hain::search()
{
	if (game_list_size == 0)
	{
		cout << "���� �����������!" << endl;
		getchar();
		return -1;
	}

	bool flag = false;
	string name, platform;

	do
	{
		cout << "������� ��������: " << endl;
		getline(cin, name);
	} while (!str_valid(name));

	while (true)
	{
		cout << "������� ������� ���������: ";
		getline(cin, platform);

		if (platform == "PC" || platform == "Xbox" || platform == "PS")
			break;
	}

	for (int i = 0; i < game_list_size; i++)
		if (game_list[i].name == name && game_list[i].platform == platform) // ����� �� �������� � ���������
			flag = true;

	if (flag)
	{
		result();
		return 0;
	}
	else
	{
		if (next)
			next->search();
		else
		{
			cout << "���� ����� �� ���� �������." << endl;
			return -1;
		}
	}
}

void �hain::add_to_file(string file)
{
	int add_value; //������� ��� ����� ��������

	cout << "������� ��� �� ������ �������� � ����? " << endl;
	cin >> add_value;
	game_list_size += add_value;
	write_to_file(file, add_value);
}

void �hain::write_to_file(string file, int add_val)
{
	ofstream out;
	Game tmp;
	try
	{
		out.open(file, ios::out);
		if (!out.is_open())
			throw exception("���� �� ����� ���� ������!");

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
			throw exception("���� �� ����� ���� ������!");

		if (in.peek() == EOF)
			throw exception("���� ����!");

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