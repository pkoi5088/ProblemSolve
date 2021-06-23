#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#define endl '\n'

using namespace std;

string board[9];

vector<int> getAble(int num) {
	vector<int> ret;
	int x = num / 9, y = num % 9;
	for (int n = 1; n < 10; ++n) {
		bool flag = true;
		//가로
		for (int i = 0; i < 9; ++i) {
			if (board[x][i] == n + '0')
				flag = false;
		}
		//세로
		for (int i = 0; i < 9; ++i) {
			if (board[i][y] == n + '0')
				flag = false;
		}
		//3x3
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (board[(x / 3) * 3 + i][(y / 3) * 3 + j] == n + '0')
					flag = false;
			}
		}

		if (flag) {
			ret.push_back(n);
		}
	}
	return ret;
}

void pick(int num) {
	if (num == 81) {
		for (int i = 0; i < 9; ++i) {
			cout << board[i] << endl;
		}
		exit(0);
	}
	else {
		int x = num / 9, y = num % 9;
		if (board[x][y] != '0') {
			pick(num + 1);
		}
		else {
			vector<int> able = getAble(num);
			for (int i = 0; i < able.size(); ++i) {
				board[x][y] = able[i] + '0';
				pick(num + 1);
				board[x][y] = '0';
			}
		}
	}
}

void solve() {
	for (int i = 0; i < 9; ++i) {
		cin >> board[i];
	}
	pick(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
