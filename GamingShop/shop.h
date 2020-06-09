#pragma once
#include "chain.h"

class Shop : public Chain
{
protected:
	std::string filename;
	void result() override;

public:
	Shop();
	std::string get_filename();
};