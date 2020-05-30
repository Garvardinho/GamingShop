/*
* num_valid and str_valid implementation
*/
#include "header.h"

bool num_valid(string str) // Check the number
{
	char tmp[1028];
	if (_itoa_s(atoi(str.c_str()), tmp, 10) == 0) // Convert string to number and then back to string
		if (str == tmp) // If strings are equal and no errors is found
			return true;

	return false;
}

bool str_valid(string str) // Check the string
{
	if (!str.empty() && str.find_first_not_of(' ') >= 0) // If the string is not empty and not just spaces
		return true;

	return false;
}