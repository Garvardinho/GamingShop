#include "header.h"
#include "site.h"

using namespace std;

void Site::result()
{
	cout << "���� �� �����" << endl;
}

Site::Site()
{
	filename = "site.txt";
	cout << endl << "=====����=====" << endl << endl;
	read_from_file(filename); //���������� ������� � ������ � ������� ������
}

string Site::get_filename()
{
	return filename;
}