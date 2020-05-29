// Реализация функций num_valid и str_valid
#include "header.h"

bool num_valid(string str) // Функция проверки ввода числа на корректность
{
	char tmp[1028];
	if (_itoa_s(atoi(str.c_str()), tmp, 10) == 0) // Переводим строку в число, а затем обратно в строку и проверяем на ошибку
		if (str == tmp) // Если строки совпали и ошибки преобразования отсутствуют
			return true;

	return false;
}

bool str_valid(string str) // Проверка строки на пустоту
{
	if (!str.empty() && str.find_first_not_of(' ') >= 0) // Если строка не пуста и не состоит только из пробелов
		return true;

	return false;
}