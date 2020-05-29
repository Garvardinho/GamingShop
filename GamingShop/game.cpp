#include "header.h"
#include "game.h"

using namespace std;

Game::Game()
{
	year = 0;
	quantity = 0;
}

void Game::set_game()
{
	string tmp;

	do // Так как здесь вполне может быть больше одного слова, следует ввести проверку на пустую строку
	{
		cout << "Введите название: " << endl;
		getline(cin, name);
	} while (!str_valid(name)); // Здесь и далее - проверка на пустую строку (пробелы == пустая строка)

	do
	{
		cout << "Введите жанр: " << endl;
		getline(cin, genre);
	} while (!str_valid(genre));

	while (true)
	{
		cout << "Введите год выпуска: ";
		getline(cin, tmp);
		year = atoi(tmp.c_str());
		if (num_valid(tmp)) // Если пройдена проверка строки на число
			if (year >= 1980 && year <= 2020) // Если год выпуска игры соответствует его нормальным границам
				break;
	}

	while (true)
	{
		cout << "Введите игровую платформу: ";
		getline(cin, platform);

		if (platform == "PC" || platform == "Xbox" || platform == "PS")
			break;
	}

	do
	{
		cout << "Введите системные требования: ";
		getline(cin, sys_req);
	} while (!str_valid(sys_req));
	
	do
	{
		cout << "Введите разработчика: ";
		getline(cin, developer);
	} while (!str_valid(developer));

	while (true)
	{
		cout << "Введите количество: ";
		getline(cin, tmp);
		year = atoi(tmp.c_str());
		if (num_valid(tmp))
			break;
	}
}

void Game::show_game()
{
	cout << "Название игры: " << name << "\nЖанр игры: " << genre << "\nГод выпуска: "
		<< year << "\nИгровая платформа: " << platform << "\nCистемные требования: " << sys_req
		<< "\nРазработчик: " << developer << "\nКоличество: " << quantity << endl << endl;
}