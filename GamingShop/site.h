#pragma once
#include "chain.h"

class Site : public �hain 
{
protected:
	string filename;
	void result() override;

public:
	Site();
	string get_filename();
};
