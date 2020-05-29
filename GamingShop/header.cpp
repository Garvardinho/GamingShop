// ���������� ������� num_valid � str_valid
#include "header.h"

bool num_valid(string str) // ������� �������� ����� ����� �� ������������
{
	char tmp[1028];
	if (_itoa_s(atoi(str.c_str()), tmp, 10) == 0) // ��������� ������ � �����, � ����� ������� � ������ � ��������� �� ������
		if (str == tmp) // ���� ������ ������� � ������ �������������� �����������
			return true;

	return false;
}

bool str_valid(string str) // �������� ������ �� �������
{
	if (!str.empty() && str.find_first_not_of(' ') >= 0) // ���� ������ �� ����� � �� ������� ������ �� ��������
		return true;

	return false;
}