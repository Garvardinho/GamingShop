#pragma once
#include "Chain.h"

class Warehouse : public Chain 
{
protected:
	string filename;
	void result() override;

public:
	Warehouse();
	string get_filename();
};