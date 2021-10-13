#include <iostream>
#define MAX 1000001
#define endl "\n"

using namespace std;

int parent[MAX];

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	parent[Find(a)] = parent[Find(b)];
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) parent[i] = i;
	while (m--) {
		int x, a, b;
		cin >> x >> a >> b;
		if (x) {
			if (Find(a) == Find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			Union(a, b);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}