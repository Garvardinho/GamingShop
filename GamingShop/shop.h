#pragma once
#include <string>
#include "chain.h"

class Shop : public �hain
{
protected:
	std::string filename;
	void result() override;

public:

	Shop();
	std::string get_filename();
};