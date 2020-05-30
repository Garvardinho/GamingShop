#include "header.h"
#include "chain.h"
#include "game.h"

Ñhain::Ñhain()
{
	next = nullptr;
}

Ñhain::~Ñhain()
{
	if (next)
		delete next;
}

Ñhain *Ñhain::setNext(Ñhain *ñhain)
{
	next = ñhain;
	return next;
}

int Ñhain::search(string title_s = "", string platform_s = "") // Search games by title and platform
{
	bool flag = false;
	string title, platform;
	
	if (!title_s.empty())
	{
		title = title_s;
		platform = platform_s;
	}
	else
	{
		do
		{
			cout << "Title: ";
			getline(cin, title);
		} while (!str_valid(title));

		while (true)
		{
			cout << "Gaming platform: ";
			getline(cin, platform);

			if (platform == "PC" || platform == "Xbox" || platform == "PS")
				break;
		}
	}

	for (auto it : game_list)
		if (it.title == title && it.platform == platform)
			flag = true;

	if (flag)
	{
		result();
		return 0;
	}
	else
	{
		if (next)
			return next->search(title, platform);
		else
		{
			cout << "The game was not found" << endl << endl;
			return -1;
		}
	}
}

void Ñhain::write_to_file(string file)
{
	int add_val;
	string tmp_str;

	while (true)
	{
		cout << "How much games do you want to add: ";
		getline(cin, tmp_str);
		add_val = atoi(tmp_str.c_str());
		if (num_valid(tmp_str))
			break;
	}
	
	cout << endl;
	ofstream out;
	Game tmp;
	try
	{
		out.open(file, ios_base::app);
		if (!out.is_open())
			throw exception("File can not be opened!");
		
		for (int i = 0; i < add_val; i++)
		{
			tmp.set_game();
			out << "Title: " << tmp.title << "\nGenre: " << tmp.genre << "\nYear: "
				<< tmp.year << "\nGaming platform: " << tmp.platform << "\nSystem requirements: " 
				<< tmp.sys_req << "\nDeveloper: " << tmp.developer << "\nQuantity: " << tmp.quantity << endl << endl;

			game_list.push_back(tmp);
		}
		out.close();
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}
}

void Ñhain::read_from_file(string file)
{
	ifstream in;
	string tmp;
	Game game;
	int pos;
	int flag = 1;

	try
	{
		in.open(file, ios::in);
		if (!in.is_open())
			throw exception("File can not be opened!\n");

		if (in.peek() == EOF)
			throw exception("File is empty!\n");

		while (in.peek() != EOF) // Data have been reading from file
		{
			getline(in, tmp);
			if (tmp.empty())
				continue;

			cout << tmp << endl;

			switch (flag)
			{
			case 1:
				if (pos = tmp.find("Title: ") != 0)
					throw exception("There is an error in file\n");

				game.title = tmp.substr(7);
				break;

			case 2:
				if (pos = tmp.find("Genre: ") != 0)
					throw exception("There is an error in file\n");

				game.genre = tmp.substr(7);
				break;

			case 3:
				if (pos = tmp.find("Year: ") != 0)
					throw exception("There is an error in file\n");

				tmp = tmp.substr(6);
				if (!num_valid(tmp))
					throw exception("There is an error in file\n");

				game.year = atoi(tmp.c_str()); // Convert string to integer
				if (game.year < 1980 || game.year > 2020)
					throw exception("There is a year error in file\n");
				break;

			case 4:
				if (pos = tmp.find("Gaming platform: ") != 0)
					throw exception("There is an error in file\n");

				game.platform = tmp.substr(17);
				if (game.platform != "PC" && game.platform != "Xbox" && game.platform != "PS")
					throw exception("There is a game platform error in file\n");
				break;

			case 5:
				if (pos = tmp.find("System requirements: ") != 0)
					throw exception("There is an error in file\n");

				game.sys_req = tmp.substr(21);
				break;

			case 6:
				if (pos = tmp.find("Developer: ") != 0)
					throw exception("There is an error in file\n");

				game.developer = tmp.substr(11);
				break;

			case 7:
				if (pos = tmp.find("Quantity: ") != 0)
					throw exception("There is an error in file\n");

				tmp = tmp.substr(10);
				if (!num_valid(tmp))
					throw exception("There is an error in file\n");

				game.quantity = atoi(tmp.c_str());
				if (game.quantity <= 0)
					throw exception("There is a quantity error in file\n");
				break;
			}

			if (flag == 7)
			{
				cout << endl;
				flag = 0; // Zero because of increment below
				game_list.push_back(game);
			}

			flag++;
		}
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}

	in.close();
}