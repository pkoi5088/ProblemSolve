#include <iostream>
#include <set>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/10815

*/

void solve() {
	set<int> s;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}
	cin >> M;
	while (M--) {
		int tmp;
		cin >> tmp;
		if (s.find(tmp) == s.end()) {
			cout << "0 ";
		}
		else {
			cout << "1 ";
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