#include "header.h"
#include "game.h"
#include "chain.h"
#include "site.h"
#include "shop.h"
#include "warehouse.h"

using namespace std;

int main()
{
	Сhain *chain;
	Site *site;
	Shop *shop;
	Warehouse *warehouse;
	string tmp;
	int menu = 1;
	int search_res;

	while (menu != 0)
	{
		while (true) // Вывод меню
		{
			cout << "Select menu item:" << endl <<
				"1. Show all games from all sources" << endl <<
				"2. Add game" << endl <<
				"3. Find the game" << endl <<
				"0. Exit" << endl;

			getline(cin, tmp);
			menu = atoi(tmp.c_str());
			if (num_valid(tmp)) // Если пройдена проверка строки на число
				if (menu >= 0 && menu <= 3) // Если год выпуска игры соответствует его нормальным границам
					break;
		}

		switch (menu)
		{
		case 1: /*Вывести все данные на экран*/
			chain = new Site;
			chain = new Shop;
			chain = new Warehouse;
			delete chain;
			break;

		case 2:
			cout << "Select menu item:" << endl <<
				"1. Add the game to the site" << endl <<
				"2. Add the game to the shop" << endl <<
				"3. Add the game to the warehouse" << endl <<
				"0. Exit" << endl;
			cin >> menu;
			switch (menu)
			{
			case 1: // Добавление игр на сайт
				site = new Site;
				site->write_to_file(site->get_filename());
				delete site;
				break;
			case 2: // Добавление игр в магазин
				shop = new Shop;
				shop->write_to_file(shop->get_filename());
				delete shop;
				break;
			case 3: // Добавление игр на склад
				warehouse = new Warehouse;
				warehouse->write_to_file(warehouse->get_filename());
				delete warehouse;
				break;
			default:
				break;
			}
			break;

		case 3:
			chain = new Site;
			chain->setNext(new Shop)->setNext(new Warehouse);
			search_res = chain->search();
			if (search_res != -1)
				cout << endl << "Data to search: " << endl;

			break;

		default:
			break;
		}
	}

	return 0;
}