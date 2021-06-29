#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	vector<int> v;
	int N, result = -1;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());

	deque<int> deq;
	deq.push_back(v[0]);
	for (int i = 1; i < N; i += 2) {
		deq.push_front(v[i]);
		if (i + 1 < N)
			deq.push_back(v[i + 1]);
	}

	for (int i = 0; i < deq.size(); ++i) {
		int left = i - 1, right = i + 1;
		if (left >= 0)
			result = max(result, abs(deq[i] - deq[left]));
		if (right < N)
			result = max(result, abs(deq[i] - deq[right]));
	}
	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
