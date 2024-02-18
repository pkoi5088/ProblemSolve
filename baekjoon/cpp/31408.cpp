#include <iostream>
#include <unordered_map>
#include <algorithm>
#define endl '\n'

using namespace std;

void solve() {
	int N;
	unordered_map<int,int> uod;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (uod.find(a) == uod.end()) {
			uod[a] = 1;
		}
		else {
			uod[a] += 1;
		}
	}

	int t = -1;
	for (auto a : uod) {
		t = max(t, a.second);
	}
	
	if (t > N / 2 + N % 2) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}