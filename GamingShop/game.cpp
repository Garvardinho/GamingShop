#include "header.h"
#include "game.h"

using namespace std;

Game::Game()
{
	year = 0;
	quantity = 0;
}

void Game::set_game()
{
	string tmp;

	do // ��� ��� ����� ������ ����� ���� ������ ������ �����, ������� ������ �������� �� ������ ������
	{
		cout << "������� ��������: " << endl;
		getline(cin, name);
	} while (!str_valid(name)); // ����� � ����� - �������� �� ������ ������ (������� == ������ ������)

	do
	{
		cout << "������� ����: " << endl;
		getline(cin, genre);
	} while (!str_valid(genre));

	while (true)
	{
		cout << "������� ��� �������: ";
		getline(cin, tmp);
		year = atoi(tmp.c_str());
		if (num_valid(tmp)) // ���� �������� �������� ������ �� �����
			if (year >= 1980 && year <= 2020) // ���� ��� ������� ���� ������������� ��� ���������� ��������
				break;
	}

	while (true)
	{
		cout << "������� ������� ���������: ";
		getline(cin, platform);

		if (platform == "PC" || platform == "Xbox" || platform == "PS")
			break;
	}

	do
	{
		cout << "������� ��������� ����������: ";
		getline(cin, sys_req);
	} while (!str_valid(sys_req));
	
	do
	{
		cout << "������� ������������: ";
		getline(cin, developer);
	} while (!str_valid(developer));

	while (true)
	{
		cout << "������� ����������: ";
		getline(cin, tmp);
		year = atoi(tmp.c_str());
		if (num_valid(tmp))
			break;
	}
}

void Game::show_game()
{
	cout << "�������� ����: " << name << "\n���� ����: " << genre << "\n��� �������: "
		<< year << "\n������� ���������: " << platform << "\nC�������� ����������: " << sys_req
		<< "\n�����������: " << developer << "\n����������: " << quantity << endl << endl;
}