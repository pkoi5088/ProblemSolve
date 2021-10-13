#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 100001
#define endl '\n'

using namespace std;

void solve() {
	vector<bool> visit;
	int N, K;
	cin >> N >> K;
	visit.resize(MAX, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,N });
	while (!pq.empty()) {
		int time = pq.top().first, now = pq.top().second;
		pq.pop();
		if (now == K) {
			cout << time;
			return;
		}
		if (2 * now < MAX && visit[2 * now] == false) {
			pq.push({ time,2 * now });
			visit[2 * now] = true;
		}
		if (now + 1 < MAX && visit[now + 1] == false) {
			pq.push({ time + 1,now + 1 });
			visit[now + 1] = true;
		}
		if (now - 1 >= 0 && visit[now - 1] == false) {
			pq.push({ time + 1,now - 1 });
			visit[now - 1] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
