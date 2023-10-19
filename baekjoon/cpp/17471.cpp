#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
#define MAX 10
#define INF 1000000000

using namespace std;

int N, answer = INF;
vector<int> people, graph;

bool IsValid(int t) {
	int start = 0;
	while (true) {
		if (t & (1 << start))
			break;
		start += 1;
	}

	int ret = 0;
	queue<int> q;
	q.push(start);
	ret |= (1 << start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next = 0; next < N; ++next) {
			if ((ret & (1 << next)) || !(t & (1 << next)))
				continue;
			if (!(graph[now] & (1 << next)))
				continue;

			q.push(next);
			ret |= (1 << next);
		}
	}

	return ret == t;
}

void solve() {
	cin >> N;
	people.resize(N);
	graph.resize(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> people[i];
	}
	for (int i = 0; i < N; ++i) {
		int M;
		cin >> M;
		while (M--) {
			int a;
			cin >> a;
			a -= 1;
			graph[i] = graph[i] | (1 << a);
		}
	}

	for (int state = 0; state < (1 << N); ++state) {
		int red = state, blue = ~state & ((1 << N) - 1);
		if (red == 0 || blue == 0) continue;

		// 둘다 유효 해야함
		if (!IsValid(red) || !IsValid(blue)) {
			continue;
		}

		int redPeople = 0, bluePeople = 0;
		for (int i = 0; i < N; ++i) {
			if (red & (1 << i)) {
				redPeople += people[i];
			}
		}
		for (int i = 0; i < N; ++i) {
			if (blue & (1 << i)) {
				bluePeople += people[i];
			}
		}

		answer = min(answer, abs(redPeople - bluePeople));
	}
	if (answer == INF) cout << -1;
	else cout << answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}