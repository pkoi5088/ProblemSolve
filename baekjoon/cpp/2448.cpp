#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

vector<vector<bool>> star;

//(a,b)에서 높이가 h인 별찍기
void starPoint(int a, int b, int h) {
	if (h == 3) {
		star[a][b + 2] = star[a + 1][b + 1] = star[a + 1][b + 3] = true;
		for (int i = 0; i < 5; i++) {
			star[a + 2][b + i] = true;
		}
	}
	else {
		int bottom = 2 * h - 1;
		starPoint(a, b + h / 2, h / 2);
		starPoint(a + h / 2, b, h / 2);
		starPoint(a + h / 2, b + h, h / 2);
	}
}

void solve() {
	int N;
	cin >> N;

	star.resize(N);
	for (int i = 0; i < N; i++) {
		star[i].resize(2 * N - 1);
	}
	starPoint(0, 0, N);

	for (int i = 0; i < star.size(); i++) {
		for (int j = 0; j < star[i].size(); j++) {
			cout << (star[i][j] ? '*' : ' ');
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
