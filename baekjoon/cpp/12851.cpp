#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 1000000
#define endl '\n'

using namespace std;

void solve() {
	int N, K, cnt, time = INF;
	cin >> N >> K;
	vector<bool> visit;
	visit.resize(100001, false);

	queue<pair<int, int>> q;
	q.push({ N,0 });
	while (!q.empty()) {
		int now = q.front().first, t = q.front().second;
		q.pop();
		visit[now] = true;
		//갱신부분
		if (now == K) {
			if (time > t) {
				time = t;
				cnt = 1;
			}
			else if (time == t) {
				++cnt;
			}
		}

		//추가 탐색
		if (now >= 1 && visit[now - 1] == false) {
			q.push({ now - 1,t + 1 });
		}
		if (now < 100000 && visit[now + 1] == false) {
			q.push({ now + 1 ,t + 1 });
		}
		if (2 * now <= 100000 && visit[2 * now] == false) {
			q.push({ 2 * now  ,t + 1 });
		}
	}
	cout << time << endl << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
