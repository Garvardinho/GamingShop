#include "header.h"
#include "shop.h"

void Shop::result()
{
	cout << "»гра в магазине" << endl;
}

Shop::Shop()
{
	filename = "shop.txt";
	cout << endl << "=====ћј√ј«»Ќ=====" << endl << endl;
	read_from_file(filename); //заполнение массива с играми в базовом классе
}

string Shop::get_filename()
{
	return filename;
}