#pragma once
#include "chain.h"

class Site : public Ñhain 
{
protected:
	string filename;
	void result() override;

public:
	Site();
	string get_filename();
};
