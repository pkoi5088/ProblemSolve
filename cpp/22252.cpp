#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#define MAX 1003
#define endl '\n'

using namespace std;

void solve() {
	vector<priority_queue<int>> v;
	map<string, int> m;
	int Q;
	long long ret = 0;
	cin >> Q;
	while (Q--) {
		string name;
		int x;
		cin >> x;
		if (x == 1) {
			int N, buffer, idx;
			cin >> name >> N;
			if (m.find(name) != m.end()) {
				idx = m[name];
			}
			else {
				v.push_back(priority_queue<int>());
				idx = m[name] = v.size() - 1;
			}
			for (int i = 0; i < N; ++i) {
				cin >> buffer;
				v[idx].push(buffer);
			}
		}
		else {
			int b, idx;
			cin >> name >> b;
			if (m.find(name) != m.end()) {
				idx = m[name];
				while (!v[idx].empty() && b--) {
					ret += (long long)v[idx].top();
					v[idx].pop();
				}
			}
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
