#pragma once
#include "Chain.h"

class Warehouse : public Сhain 
{
protected:
	string filename;
	void result();

public:
	Warehouse(); //конструктор
	string get_filename();
};