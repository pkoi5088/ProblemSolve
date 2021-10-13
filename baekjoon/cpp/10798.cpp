#include <iostream>
#include <string>

using namespace std;

int main() {
	string t;
	char board[5][15] = { ' ' };
	for (int i = 0; i < 5; i++) {
		cin >> t;
		for (int j = 0; j < t.size(); j++)
			board[i][j] = t[j];
	}
	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < 5; i++) {
			if ((int)board[i][j] != 0)
				cout << board[i][j];
		}
	}
	return 0;
}