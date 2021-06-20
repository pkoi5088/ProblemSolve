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
	int N, K, result = 0;
	cin >> N >> K;
	vector<int> v;
	v.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, less<int>>pq;
	for (int i = 1; i < N; ++i) {
		pq.push(v[i] - v[i - 1]);
	}
	
	while (!pq.empty() && (K - 1 > 0)) {
		pq.pop();
		--K;
	}

	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
