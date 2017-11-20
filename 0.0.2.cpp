#include <iostream>
#include <sstream>

using namespace std;

int quit, stop;

void options(char turn, char *a)
{
	int j = 0;
	for (int i = 0; i < 25; i++)
	{
		if (!(a[i] == 'X' || a[i] == 'O'))
		{
			if (i < 5) 
				cout << ++j << ". mark cell a" << i + 1 << " as " << turn << endl;
			if (i > 4 && i < 10)
				cout << ++j << ". mark cell b" << i - 4 << " as " << turn << endl;
			if (i > 9 && i < 15) 
				cout << ++j << ". mark cell c" << i - 9 << " as " << turn << endl;
			if (i > 14 && i < 20)
				cout << ++j << ". mark cell d" << i - 14 << " as " << turn << endl;
			if (i > 19 && i < 25) 
				cout << ++j << ". mark cell e" << i - 19 << " as " << turn << endl;
		}
	}
	cout << ++j << ".quit" << endl;
	quit = j;
}

void cells(char *a)
{
	cout << "   1   2   3   4   5" << endl;
	cout << " +---+---+---+---+---+" << endl;
	cout << "a| " << a[0] << " | " << a[1] << " | " << a[2] << " | " << a[3] << " | " << a[4] << " |" << endl;
	cout << " +---+---+---+---+---+" << endl;
	cout << "b| " << a[5] << " | " << a[6] << " | " << a[7] << " | " << a[8] << " | " << a[9] << " |" << endl;
	cout << " +---+---+---+---+---+" << endl;
	cout << "c| " << a[10] << " | " << a[11] << " | " << a[12] << " | " << a[13] << " | " << a[14] << " |" << endl;
	cout << " +---+---+---+---+---+" << endl;
	cout << "d| " << a[15] << " | " << a[16] << " | " << a[17] << " | " << a[18] << " | " << a[19] << " |" << endl;
	cout << " +---+---+---+---+---+" << endl;
	cout << "e| " << a[20] << " | " << a[21] << " | " << a[22] << " | " << a[23] << " | " << a[24] << " |" << endl;
	cout << " +---+---+---+---+---+" << endl;
}

int choice(int move, char turn, char *a)
{
	int cell;
	string str;
	getline(cin, str);
	istringstream stream(str);
	stream >> cell;
	while (cell < 1 || cell >(27 - move))
	{
		cout << endl << "Wrong move!" << endl;
		getline(cin, str);
		istringstream stream(str);
		stream >> cell;
	}
	int j = 0;
	for (int i = 0; i < 25; i++)
	{
		if (a[i] == ' ')
			j++;
		if (j == cell)
		{
			a[i] = turn;
			cells(a);
			return 0;
		}
	}
	if (cell == quit)
	{
		cout << "GAME OVER!" << endl;
		stop = quit;
		return -1;
	}
	return 0;
}

char check(char *a)
{
	for (int i = 0; i <= 20; i += 5)
	{
		if ((a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i + 2] == a[i + 3] && a[i + 3] == a[i + 4]) && a[i] != ' ')
			return a[i];
	}
	for (int j = 0; j < 4; j++)
	{
		if ((a[j] == a[j + 5] && a[j + 5] == a[j + 10] && a[j + 10] == a[j + 15] && a[j + 15] == a[j + 20]) && a[j] != ' ') 
			return a[j];
	}
	if ((a[0] == a[6] && a[6] == a[12] && a[12] == a[18] && a[18] == a[24]) && a[0] != ' ')
		return a[0];
	if ((a[4] == a[8] && a[8] == a[12] && a[12] == a[16] && a[16] == a[20]) && a[4] != ' ') 
		return a[4];
	return ' ';
}

int main()
{
	char win;
	char a[25] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char turn;
	cells(a);
	for (int move = 1; move <= 25; move++)
	{
		if (move % 2)
		{
			turn = 'X';
			options(turn, a);
			choice(move, turn, a);
		}
		else
		{
			turn = 'O';
			options(turn, a);
			choice(move, turn, a);
		}
		if (quit == stop)
			return -1;
		if (move >= 9)
			check(a);
		char  win = check(a);
		if (win == 'X')
		{
			cout << "Player X wins!" << endl;
			return -1;
		}
		if (win == 'O')
		{
			cout << "Player O wins!" << endl;
			return -1;
		}
		if (move == 25 && win != 'X' && win != 'O')
		{
			cout << "Draw!" << endl;
			return -1;
		}
	}
	if (quit == stop)
		return -1;
	return 0;
}
