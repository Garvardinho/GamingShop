#include "header.h"
#include "game.h"

using namespace std;

Game::Game() {}

Game::~Game() {}

void Game::set_game()
{
	string tmp;

	do // Check for an empty string
	{
		cout << "Title: ";
		getline(cin, title);
	} while (!str_valid(title)); // Spaces are equal to empty string

	do
	{
		cout << "Genre: ";
		getline(cin, genre);
	} while (!str_valid(genre));

	while (true)
	{
		cout << "Year: ";
		getline(cin, tmp);
		year = atoi(tmp.c_str());
		if (num_valid(tmp)) // If the check for the number is passed
			if (year >= 1980 && year <= 2020) // If the year corresponds to real scopes
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
			if (quantity > 0)
				break;
	}
}