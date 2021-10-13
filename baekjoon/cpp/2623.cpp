#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 1000
#define endl '\n'

using namespace std;

vector<int> graph[MAX];
int indeg[MAX] = { 0 };
int N, M;

vector<int> getResult() {
	vector<int> ret;
	queue<int> q;
	for (int i = 0; i < N; ++i) {
		if (indeg[i] == 0)
			q.push(i);
	}
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ret.push_back(now + 1);
		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i];
			if (--indeg[next] == 0) {
				q.push(next);
			}
		}
	}
	return ret;
}

void solve() {
	vector<int> v;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		v.clear();
		int a;
		cin >> a;
		v.resize(a);
		for (int j = 0; j < a; ++j)
			cin >> v[j];
		for (int j = 1; j < a; ++j) {
			graph[v[j - 1] - 1].push_back(v[j] - 1);
			indeg[v[j] - 1] += 1;
		}
	}
	v = getResult();
	if (v.size() != N) cout << 0 << endl;
	else {
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
