#include <iostream>
#define MAX 101
#define endl '\n'

using namespace std;

bool arr[MAX][MAX] = { false };

void solve() {
	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int a = x1; a < x2; ++a) {
			for (int b = y1; b < y2; ++b) {
				arr[a][b] = true;
			}
		}
	}
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (arr[i][j])
				cnt++;
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
