#include "header.h"
#include "warehouse.h"

void Warehouse::result()
{
	cout << "����� ������ �� ������" << endl;
}

Warehouse::Warehouse()
{
	filename = "Warehouse.txt";
	cout << endl << "~~~~~~~~~ ���������� ������ ~~~~~~~~~" << endl << endl;
	read_from_file(filename); //���������� ������� � ������ � ������� ������
}

string Warehouse::get_filename() 
{ 
	return filename; 
}