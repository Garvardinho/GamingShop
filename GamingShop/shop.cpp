#include "header.h"
#include "shop.h"

void Shop::result()
{
	cout << "����� ������ � ��������" << endl;
}

Shop::Shop()
{
	filename = "shop.txt";
	cout << endl << "~~~~~~~~~ ���������� �������� ~~~~~~~~~" << endl << endl;
	read_from_file(filename); //���������� ������� � ������ � ������� ������
}

string Shop::get_filename()
{
	return filename;
}