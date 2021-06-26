#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	vector<bool> visit;
	queue<pair<int, string>> q;
	visit.resize(10000, false);
	int A, B;
	cin >> A >> B;

	q.push({ A,"" });
	visit[A] = true;
	while (!q.empty()) {
		int now = q.front().first;
		string result = q.front().second;
		q.pop();
		if (now == B) {
			cout << result << endl;
			return;
		}
		int D, S, L, R;
		D = (now * 2) % 10000;
		S = now - 1;
		if (S == -1)
			S = 9999;
		L = (now % 1000) * 10 + now / 1000;
		R = (now / 10) + (now % 10) * 1000;

		if (!visit[D]) {
			q.push({ D,result + "D" });
			visit[D] = true;
		}
		if (!visit[S]) {
			q.push({ S,result + "S" });
			visit[S] = true;
		}
		if (!visit[L]) {
			q.push({ L,result + "L" });
			visit[L] = true;
		}
		if (!visit[R]) {
			q.push({ R,result + "R" });
			visit[R] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
