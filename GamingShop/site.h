#pragma once
#include "chain.h"

class Site : public Сhain 
{
protected:
	string filename;
	void result();

public:
	Site(); //конструктор
	string get_filename();
};
