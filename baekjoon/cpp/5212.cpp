#include <iostream>
#include <string>
#define endl '\n'
#define MAX 10

using namespace std;

/*
	https://www.acmicpc.net/problem/5212
*/

int R, C, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
string arr[MAX];
bool tmp[MAX][MAX] = { false, };

void solve() {
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (arr[i][j] == 'X') {
				int cnt = 0;
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C) cnt += 1;
					else if (arr[nx][ny] == '.') cnt += 1;
				}
				if (cnt >= 3) tmp[i][j] = true;
			}
		}
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (arr[i][j] == 'X'&&tmp[i][j]) {
				arr[i][j] = '.';
			}
		}
	}

	pair<int, int>left = { -1,-1 }, right = { -1,-1 };
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (arr[i][j] == 'X') {
				if (left.first == -1) {
					left = { i,j };
				}
				else {
					left.first = (left.first > i ? i : left.first);
					left.second = (left.second > j ? j : left.second);
				}

				if (right.first == -1) {
					right = { i,j };
				}
				else {
					right.first = (right.first < i ? i : right.first);
					right.second = (right.second < j ? j : right.second);
				}
			}
		}
	}

	for (int i = left.first; i <= right.first; ++i) {
		for (int j = left.second; j <= right.second; ++j) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}