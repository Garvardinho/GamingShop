#include "header.h"
#include "warehouse.h"

void Warehouse::result()
{
	cout << "Игра на складе" << endl;
}

Warehouse::Warehouse()
{
	filename = "warehouse.txt";
	cout << endl << "=====СКЛАД=====" << endl << endl;
	read_from_file(filename); //заполнение массива с играми в базовом классе
}

string Warehouse::get_filename() 
{ 
	return filename; 
}