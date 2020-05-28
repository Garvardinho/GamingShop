#include "header.h"
#include "warehouse.h"

void Warehouse::result()
{
	cout << "ÒÎÂÀÐ ÍÀÉÄÅÍ ÍÀ ÑÊËÀÄÅ" << endl;
}

Warehouse::Warehouse()
{
	filename = "Warehouse.txt";
	cout << endl << "~~~~~~~~~ ÑÎÄÅÐÆÈÌÎÅ ÑÊËÀÄÀ ~~~~~~~~~" << endl << endl;
	read_from_file(filename); //çàïîëíåíèå ìàññèâà ñ èãðàìè â áàçîâîì êëàññå
}

string Warehouse::get_filename() 
{ 
	return filename; 
}