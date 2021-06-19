#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

vector<int> v;
stack<int> s;
int N;

void solve() {
	vector<char> result;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int target = 0;
	for (int i = 1; i <= N; i++) {
		s.push(i);
		result.push_back('+');
		while (!s.empty() && target < N && s.top() == v[target]) {
			s.pop();
			result.push_back('-');
			target += 1;
		}
	}
	if (!s.empty()) {
		cout << "NO";
	}
	else {
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
