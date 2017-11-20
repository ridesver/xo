#include <iostream>
#include <sstream>

using namespace std;

int quit, ex;

void options(char turn, char *a)
{
	int j = 0;
	for (int i = 0; i < 9; i++)
	{
		if (!(a[i] == 'X' || a[i] == 'O'))
		{
			if (i < 3) 
				cout << ++j << ".mark cell a" << i + 1 << " as " << turn << endl;
			if (i>2 && i<6) 
				cout << ++j << ".mark cell b" << i - 2 << " as " << turn << endl;
			if (i>5) 
				cout << ++j << ".mark cell c" << i - 5 << " as " << turn << endl;
		}
	}
	cout << ++j << ". quit" << endl;
	quit = j;
}

void cells(char *a)
{
	cout << "   1   2   3" << endl;
	cout << " +---+---+---+" << endl;
	cout << "a| " << a[0] << " | " << a[1] << " | " << a[2] << " |" << endl;
	cout << " +---+---+---+" << endl;
	cout << "b| " << a[3] << " | " << a[4] << " | " << a[5] << " |" << endl;
	cout << " +---+---+---+" << endl;
	cout << "c| " << a[6] << " | " << a[7] << " | " << a[8] << " |" << endl;
	cout << " +---+---+---+" << endl;
}

int choice(int move, char turn, char *a) {
	int cell;
	string str;
	getline(cin, str);
	istringstream stream(str);
	stream >> cell;
	while (cell < 1 || cell >(11 - move)) {
		cout << endl << "Wrong move!" << endl;
		getline(cin, str);
		istringstream stream(str);
		stream >> cell;
	}
	int j = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i] == ' ') {
			j++;
		}
		if (j == cell) {
			a[i] = turn;
			cells(a);
			return 0;
		}
	}
	if (cell == quit) {
		cout << "GAME OVER!" << endl;
		ex = quit;
		return -1;
	}
	return 0;
}

char check(char *a) {
	for (int i = 0; i < 3; i++) {

		if ((a[i * 3] == a[i * 3 + 1] && a[i * 3 + 1] == a[i * 3 + 2]) && a[i * 3] != ' ') {

			return a[i];;
		}

		if ((a[i] == a[i + 3] && a[i + 3] == a[i + 6]) && a[i] != ' ') {
			return a[i];
		}

		if (((a[2] == a[4] && a[4] == a[6]) && a[2] != ' ') || ((a[0] == a[4] && a[4] == a[8]) && a[0] != ' ')) {

			return a[i];
		}
	}

	return ' ';

}

int main() {
	char win;
	char a[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char turn;
	cells(a);
	for (int move = 1; move <= 9; move++)
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
		if (quit == ex)
			return -1;
		if (move >= 5) 
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
		if (move == 9 && win != 'X' && win != 'O')
		{
			cout << "Draw!" << endl;
				return -1;
		}
	}
	if (quit == ex)
		return -1;
	return 0;
}
