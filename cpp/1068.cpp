#include <iostream>
#include <queue>
#include <vector>
#define MAX 50
#define endl '\n'

using namespace std;

void solve() {
	bool graph[MAX][MAX] = { false };
	int N, del, cnt = 0;
	vector<int> start;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x == -1) start.push_back(i);
		else {
			graph[x][i] = true;
			graph[i][x] = true;
		}
	}
	cin >> del;
	for (int i = 0; i < start.size(); ++i) {
		queue<int> q;
		bool visit[MAX] = { false };
		if (start[i] != del) {
			q.push(start[i]);
			visit[start[i]] = true;
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			bool flag = false;
			for (int next = 0; next < N; ++next) {
				if (next != del && graph[now][next] == true && visit[next] != true) {
					q.push(next);
					visit[next] = true;
					flag = true;
				}
			}
			if (!flag) cnt += 1;
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
