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

	�hain *chain;
	Site *site;
	Shop *shop;
	Warehouse *warehouse;
	string tmp;
	int menu = 1;

	while (menu != 0)
	{
		while (true) // ����� ����
		{
			cout << "�������� ��������:" << endl <<
				"1. ������� ��� ���� �� ���� ����������" << endl <<
				"2. ���������� ���" << endl <<
				"3. ����� ������������ ����" << endl <<
				"0. �����" << endl;

			getline(cin, tmp);
			menu = atoi(tmp.c_str());
			if (num_valid(tmp)) // ���� �������� �������� ������ �� �����
				if (menu >= 0 && menu <= 3) // ���� ��� ������� ���� ������������� ��� ���������� ��������
					break;
		}

		switch (menu)
		{
		case 1: /*������� ��� ������ �� �����*/
			chain = new Site;
			chain = new Shop;
			chain = new Warehouse;
			delete chain;
			break;

		case 2:
			cout << "�������� ��������:" << endl <<
				"1. �������� ���� �� ����" << endl <<
				"2. �������� ���� � �������" << endl <<
				"3. �������� ���� �� �����" << endl <<
				"0. �����" << endl;
			cin >> menu;
			switch (menu)
			{
			case 1: // ���������� ��� �� ����
				site = new Site;
				site->add_to_file(site->get_filename());
				delete site;
				break;
			case 2: // ���������� ��� � �������
				shop = new Shop;
				shop->add_to_file(shop->get_filename());
				delete shop;
				break;
			case 3: // ���������� ��� �� �����
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
			cout << endl << "������� ������ �� ���� ��� ������: " << endl;
			break;

		default:
			break;
		}
	}

	return 0;
}