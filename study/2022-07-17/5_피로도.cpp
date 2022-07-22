#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/22864
*/

void solve() {
	int A, B, C, M, ret = 0, fatigue = 0;
	cin >> A >> B >> C >> M;
	for (int i = 0; i < 24; ++i) {
		if (fatigue + A <= M) {
			ret += B;
			fatigue += A;
		}
		else {
			fatigue -= C;
			if (fatigue < 0) fatigue = 0;
		}
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}