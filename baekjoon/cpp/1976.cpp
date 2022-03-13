#include <iostream>
#define MAX 200
#define endl '\n'

using namespace std;

int parent[MAX];

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	parent[Find(a)] = parent[Find(b)];
}

void solve() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		parent[i] = i;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int tmp;
			cin >> tmp;
			if (tmp) {
				Union(i, j);
			}
		}
	}

	int ret=0, start;
	cin >> start;
	start = Find(start - 1);
	M -= 1;
	while (M--) {
		int tmp;
		cin >> tmp;
		if (start != Find(tmp - 1)) ret = 1;
	}
	if (ret) cout << "NO";
	else cout << "YES";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}