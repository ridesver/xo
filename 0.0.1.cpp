#include <iostream>
#include<sstream>
#include <array>
using namespace std;

void choice(unsigned char turn)
{
	if (turn % 2)
		cout << "O";
	else
		cout << "X";
}

bool sign(unsigned char * a, unsigned char target, unsigned char turn)
{
	return ((a[target - 49] == 0) && (a[target - 49] = (turn % 2) + 1));
}

bool win(unsigned char * a)
{
	if ((a[4] && (a[0] == a[4]) && (a[4] == a[8])) || (a[4] && (a[2] == a[4]) && (a[4] == a[6])))
		return true;
	else
	{
		for (unsigned int i = 0; i < 3; i++)
		{
			if ((a[i + 3] && (a[i] == a[i + 3]) && (a[i + 3] == a[i + 6])) || (a[3 * i + 1] && (a[3 * i] == a[3 * i + 1]) && (a[3 * i + 1] == a[3 * i + 2])))
				return true;
		}
	}

	return false;
}

void print_frame(unsigned char * a);

void print_options(unsigned char * a, unsigned char turn);

int main()
{
	unsigned char  a[9] = {};
	unsigned char target;

	for (unsigned int i = 0; i < 9; i++)
	{
		print_frame(a);
		print_options(a, i);
		if (!(cin >> target) || target > '9' || target < '0')
		{
			cout << "An error has occured while reading input data";
			exit(EXIT_FAILURE);
		}
		cin.get();
		if (target == '0') 
		{
			cout << endl << "exit";
			exit(EXIT_SUCCESS);
		}

		if (!(sign(a, target, i)))
		{
			cout << endl << "Wrong move" << endl;
			i--;
		}
		else
		{
			if (win(a))
			{
				cout << endl << "Player ";
				choice(i);
				cout << " Won" << endl;
				print_frame(a);
				break;
			}
		}
	}
	cout << endl << "Game Over" << endl;
	return 0;
}

void print_options(unsigned char * a, unsigned char turn)
{
	for (unsigned int i = 0; i < 9; i++)
	{
		if (a[i] == 0)
		{
			cout << i + 1 << ". mark cell ";
			switch (i)
			{

			case  0: {cout << "a" << i + 1 << " as ";
				choice(turn);
				break; }
			case  1: {cout << "a" << i + 1 << " as ";
				choice(turn);
				break; }
			case  2: {cout << "a" << i + 1 << " as ";
				choice(turn);
				break; }
			case  3: {cout << "b" << (i % 3) + 1 << " as ";
				choice(turn);
				break; }
			case  4: {cout << "b" << (i % 3) + 1 << " as ";
				choice(turn);
				break; }
			case  5: {cout << "b" << (i % 3) + 1 << " as ";
				choice(turn);
				break; }
			case  6: {cout << "c" << (i % 3) + 1 << " as ";
				choice(turn);
				break; }
			case  7: {cout << "c" << (i % 3) + 1 << " as ";
				choice(turn);
				break; }
			case  8: {cout << "c" << (i % 3) + 1 << " as ";
				choice(turn);
				break; }
			}
			cout << endl;
		}
	}
	cout << "0. quit" << endl;
}

void print_frame(unsigned char * a)
{
	cout << " ";
	for (unsigned int i = 1; i < 4; i++)
	{
		cout.width(4);
		cout << i;
	}
	cout << endl;
	for (unsigned int i = 0; i < 9; i++)
	{
		switch (i)
		{
		case 0: {cout << "  +---+---+---+" << endl << "a |"; break; }
		case 3: {cout << endl << "  +---+---+---+" << endl << "b |"; break; }
		case 6: {cout << endl << "  +---+---+---+" << endl << "c |"; break; }
		}
		switch (a[i])
		{
		case 0: {cout << "   |"; break; }
		case 1: {cout << " X |"; break; }
		case 2: {cout << " O |"; break; }
		}
	}
	cout << endl << "  +---+---+---+" << endl;
}
