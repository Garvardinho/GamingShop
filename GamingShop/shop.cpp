#include "header.h"
#include "shop.h"

void Shop::result()
{
	cout << endl << "==The game is in the shop==" << endl << endl;
}

Shop::Shop()
{
	filename = "shop.txt";
	cout << endl << "=====SHOP=====" << endl << endl;
	read_from_file(filename);
}

string Shop::get_filename()
{
	return filename;
}