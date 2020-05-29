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

	do // ��� ��� ����� ������ ����� ���� ������ ������ �����, ������� ������ �������� �� ������ ������
	{
		cout << "Title: " << endl;
		getline(cin, title);
	} while (!str_valid(title)); // ����� � ����� - �������� �� ������ ������ (������� == ������ ������)

	do
	{
		cout << "Genre: " << endl;
		getline(cin, genre);
	} while (!str_valid(genre));

	while (true)
	{
		cout << "Year: ";
		getline(cin, tmp);
		year = atoi(tmp.c_str());
		if (num_valid(tmp)) // ���� �������� �������� ������ �� �����
			if (year >= 1980 && year <= 2020) // ���� ��� ������� ���� ������������� ��� ���������� ��������
				break;
	}

	while (true)
	{
		cout << "Gaming platform: ";
		getline(cin, platform);

		if (platform == "PC" || platform == "Xbox" || platform == "PS")
			break;
	}

	do
	{
		cout << "System requirments: ";
		getline(cin, sys_req);
	} while (!str_valid(sys_req));
	
	do
	{
		cout << "Developer: ";
		getline(cin, developer);
	} while (!str_valid(developer));

	while (true)
	{
		cout << "Quantity: ";
		getline(cin, tmp);
		quantity = atoi(tmp.c_str());
		if (num_valid(tmp))
			break;
	}
}

void Game::show_game()
{
	cout << "Title: " << title << "\nGenre: " << genre << "\nYear: "
		<< year << "\nGaming platform: " << platform << "\nSystem requirements: " << sys_req
		<< "\nDeveloper: " << developer << "\nQuantity: " << quantity << endl << endl;
}