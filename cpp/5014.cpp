#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	vector<bool> visit;
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	visit.resize(F + 1, false);

	queue<pair<int, int>> q;
	q.push({ S,0 });
	visit[S] = true;
	while (!q.empty()) {
		int now = q.front().first, dist = q.front().second;
		q.pop();
		if (now == G) {
			cout << dist;
			return;
		}
		if (now + U <= F && visit[now + U] == false) {
			q.push({ now + U,dist + 1 });
			visit[now + U] = true;
		}
		if (now - D >= 1 && visit[now - D] == false) {
			q.push({ now - D,dist + 1 });
			visit[now - D] = true;
		}
	}
	cout << "use the stairs";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
