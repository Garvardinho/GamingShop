#include "header.h"
#include "chain.h"
#include "game.h"

Сhain::Сhain()
{
	next = nullptr;
	game_list = nullptr;
	game_list_size = 0;
}

Сhain::~Сhain()
{
	if (game_list)
		delete[] game_list;

	if (next)
		delete next;
}

Сhain *Сhain::setNext(Сhain *сhain)
{
	next = сhain;
	return next;
}

int Сhain::search()
{
	if (game_list_size == 0)
	{
		cout << "Игры отсутствуют!" << endl;
		getchar();
		return -1;
	}

	bool flag = false;
	string name, platform;

	do
	{
		cout << "Введите название: " << endl;
		getline(cin, name);
	} while (!str_valid(name));

	while (true)
	{
		cout << "Введите игровую платформу: ";
		getline(cin, platform);

		if (platform == "PC" || platform == "Xbox" || platform == "PS")
			break;
	}

	for (int i = 0; i < game_list_size; i++)
		if (game_list[i].name == name && game_list[i].platform == platform) // Поиск по названию и платформе
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
			cout << "Игра нигде не была найдена." << endl;
			return -1;
		}
	}
}

void Сhain::add_to_file(string file)
{
	int add_value; //сколько игр хотим добавить

	cout << "Сколько игр вы хотите добавить в базу? " << endl;
	cin >> add_value;
	game_list_size += add_value;
	write_to_file(file, add_value);
}

void Сhain::write_to_file(string file, int add_val)
{
	ofstream out;
	Game tmp;
	try
	{
		out.open(file, ios::out);
		if (!out.is_open())
			throw exception("Файл не может быть открыт!");

		out.write(reinterpret_cast<char*>(&game_list_size), sizeof(int));

		for (int i = 0; i < game_list_size - add_val; i++)
			out.write(reinterpret_cast<char*>(&game_list[i]), sizeof(Game)); // Перезаписываем содержимое gamelist

		for (int i = 0; i < add_val; i++)
		{
			tmp.set_game();
			out.write(reinterpret_cast<char*>(&tmp), sizeof(Game)); // Добавляем новые данные
		}
		out.close();
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}
}

void Сhain::read_from_file(string file)
{
	ifstream in;
	try
	{
		in.open(file, ios::in);
		if (!in.is_open())
			throw exception("Файл не может быть открыт!");

		if (in.peek() == EOF)
			throw exception("Файл пуст!");

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