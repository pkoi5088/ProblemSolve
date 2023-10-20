#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'

using namespace std;

int N, M;
vector<vector<pair<int, int>>> graph;

bool able(int limit, int start, int end) {
	vector<bool> check(N, false);

	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == end) return true;

		for (pair<int, int> p : graph[now]) {
			int next = p.first, cost = p.second;
			if (cost < limit || check[next]) continue;
			q.push(next);
			check[next] = true;
		}
	}
	return false;
}

void solve() {
	cin >> N >> M;
	graph.resize(N);

	int low = 1000000001, high = -1, mid;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back({ b-1,c });
		graph[b - 1].push_back({ a-1,c });
		low = min(low, c);
		high = max(high, c);
	}

	int start, end;
	cin >> start >> end;
	start -= 1; end -= 1;

	int ret = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (able(mid, start, end)) {
			ret = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
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