#pragma once
#include "chain.h"

class Site : public Chain 
{
protected:
	string filename;
	void result() override;

public:
	Site();
	string get_filename();
};