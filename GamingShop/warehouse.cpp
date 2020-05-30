#include "header.h"
#include "warehouse.h"

void Warehouse::result()
{
	cout << endl << "==The game is in the warehouse==" << endl << endl;
}

Warehouse::Warehouse()
{
	filename = "warehouse.txt";
	cout << endl << "=====WAREHOUSE=====" << endl << endl;
	read_from_file(filename);
}

string Warehouse::get_filename() 
{ 
	return filename; 
}