#include "header.h"
#include "site.h"

using namespace std;

void Site::result()
{
	cout << "Игра на сайте" << endl;
}

Site::Site()
{
	filename = "site.txt";
	cout << endl << "=====САЙТ=====" << endl << endl;
	read_from_file(filename); //заполнение массива с играми в базовом классе
}

string Site::get_filename()
{
	return filename;
}