#include "header.h"
#include "site.h"

using namespace std;

void Site::result()
{
	cout << "ÒÎÂÀÐ ÍÀÉÄÅÍ ÍÀ ÑÀÉÒÅ" << endl;
}

Site::Site()
{
	filename = "site.txt";
	cout << endl << "~~~~~~~~~ ÑÎÄÅÐÆÈÌÎÅ ÑÀÉÒÀ ~~~~~~~~~" << endl << endl;
	read_from_file(filename); //çàïîëíåíèå ìàññèâà ñ èãðàìè â áàçîâîì êëàññå
}

string Site::get_filename()
{
	return filename;
}