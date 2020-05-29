#include "header.h"
#include "game.h"
#include "chain.h"
#include "site.h"
#include "shop.h"
#include "warehouse.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	Сhain *chain;
	Site *site;
	Shop *shop;
	Warehouse *warehouse;
	string tmp;
	int menu = 1;

	while (menu != 0)
	{
		while (true) // Вывод меню
		{
			cout << "Выберите действие:" << endl <<
				"1. Вывести все игры из всех источников" << endl <<
				"2. Добавление игр" << endl <<
				"3. Найти определенную игру" << endl <<
				"0. Выход" << endl;

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
			cout << "Выберите действие:" << endl <<
				"1. Добавить игру на сайт" << endl <<
				"2. Добавить игру в магазин" << endl <<
				"3. Добавить игру на склад" << endl <<
				"0. Выход" << endl;
			cin >> menu;
			switch (menu)
			{
			case 1: // Добавление игр на сайт
				site = new Site;
				site->add_to_file(site->get_filename());
				delete site;
				break;
			case 2: // Добавление игр в магазин
				shop = new Shop;
				shop->add_to_file(shop->get_filename());
				delete shop;
				break;
			case 3: // Добавление игр на склад
				warehouse = new Warehouse;
				warehouse->add_to_file(warehouse->get_filename());
				delete warehouse;
				break;
			default:
				break;
			}
			break;

		case 3:
			chain = new Site;
			chain->setNext(new Shop)->setNext(new Warehouse);
			chain->search();
			cout << endl << "Введите данные об игре для поиска: " << endl;
			break;

		default:
			break;
		}
	}

	return 0;
}