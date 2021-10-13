#include <iostream>

using namespace std;

int main() {
	char board[101][101];
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	for (int j = m; j >= 1; j--) {
		for (int i = 1; i <= n; i++) {
			switch (board[i][j]) {
			case '-':
				cout << '|';
				break;
			case '|':
				cout << '-';
				break;
			case '/':
				cout << '\\';
				break;
			case '\\':
				cout << '/';
				break;
			case '^':
				cout << '<';
				break;
			case '<':
				cout << 'v';
				break;
			case 'v':
				cout << '>';
				break;
			case '>':
				cout << '^';
				break;
			default:
				cout << board[i][j];
				break;
			}
		}
		cout << endl;
	}
	return 0;
}