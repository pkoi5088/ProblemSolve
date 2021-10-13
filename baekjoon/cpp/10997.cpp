#include <iostream>
#include <string.h>

using namespace std;

char map[401][399] = { 'A' };

int main() {
	int N;
	cin >> N;
	if (N == 1)
		cout << '*';
	else {
		int side = 4 * (N - 2) + 5;
		int x = 1, y = side;
		{
			for (int i = 0; i < side + 4; i++) {
				memset(map[i], 'A', side + 2);
			}
			for (int i = 0; i <= side + 1; i++)
				map[0][i] = map[side + 3][i] = ' ';
			for (int i = 0; i <= side + 3; i++)
				map[i][0] = map[i][side + 1] = ' ';
		}

		map[x][y] = '*';
		map[x + 1][y] = ' ';
		while (N) {
			while (map[x][y - 1] != ' ') {
				map[x][y - 1] = '*';
				map[x + 1][y - 1] = ' ';
				y--;
			}
			map[x + 1][y] = '*';
			while (map[x + 1][y] != ' ') {
				map[x + 1][y] = '*';
				map[x + 1][y + 1] = ' ';
				x++;
			}
			if (!(y == (side / 2) + 1 && x == (side / 2) + 3))
				map[x][y + 1] = '*';
			else
				break;
			while (map[x][y + 1] != ' ') {
				map[x][y + 1] = '*';
				map[x - 1][y + 1] = ' ';
				y++;
			}
			map[x - 1][y] = '*';
			while (map[x - 1][y] != ' ') {
				map[x - 1][y] = '*';
				map[x - 1][y - 1] = ' ';
				x--;
			}
			map[x][y - 1] = '*';
			N--;
		}
		{
			for (int i = 1; i < side + 3; i++) {
				for (int j = 1; j < side + 1; j++) {
					cout << map[i][j];
					if (i == 2)
						break;
				}
				cout << endl;
			}
		}
	}
	return 0;
}