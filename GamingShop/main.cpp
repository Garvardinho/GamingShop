#include "header.h"
#include "game.h"
#include "chain.h"
#include "site.h"
#include "shop.h"
#include "warehouse.h"

using namespace std;

int main()
{
	Chain *chain;
	Site *site;
	Shop *shop;
	Warehouse *warehouse;
	string tmp;
	int menu = 1, submenu = 1;
	int search_res;

	while (menu != 0) // Main menu
	{
		cout << "Select menu item:" << endl <<
			"1. Show all games from all sources" << endl <<
			"2. Add game" << endl <<
			"3. Find the game" << endl <<
			"0. Exit" << endl << endl;

		while (true) // Main menu input checking
		{
			cout << "> ";
			getline(cin, tmp);
			menu = atoi(tmp.c_str());
			if (num_valid(tmp))
				if (menu >= 0 && menu <= 3)
					break;
		}

		cout << endl;
		switch (menu)
		{
		case 1: // Show all data
			chain = new Site;
			chain = new Shop;
			chain = new Warehouse;
			delete chain;
			break;

		case 2: // Add games submenu
			cout << "Select menu item:" << endl <<
				"1. Add the game to the site" << endl <<
				"2. Add the game to the shop" << endl <<
				"3. Add the game to the warehouse" << endl <<
				"0. Exit" << endl << endl;

			while (true)
			{
				cout << "> ";
				getline(cin, tmp);
				submenu = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (submenu >= 0 && submenu <= 3)
						break;
			}

			cout << endl;
			switch (submenu)
			{
			case 1: // Add games to site
				site = new Site;
				site->write_to_file(site->get_filename());
				delete site;
				break;
			case 2: // To shop
				shop = new Shop;
				shop->write_to_file(shop->get_filename());
				delete shop;
				break;
			case 3: // And to warehouse
				warehouse = new Warehouse;
				warehouse->write_to_file(warehouse->get_filename());
				delete warehouse;
				break;
			}
			break;

		case 3: // Search for the game
			chain = new Site;
			chain->setNext(new Shop)->setNext(new Warehouse);
			search_res = chain->search("", "");
			break;
		}
	}

	return 0;
}