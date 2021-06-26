#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
#define endl '\n'

using namespace std;

void solve() {
	int n, cnt = 0;
	map<string, int> m;
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s1;
		cin >> s1 >> s1;
		map<string, int>::iterator iter;
		iter = m.find(s1);
		if (iter != m.end()) {
			nums[iter->second] += 1;
		}
		else {
			nums.push_back(1);
			m.insert({ s1,cnt });
			cnt += 1;
		}
	}

	int result = 1;
	for (int i = 0; i < nums.size(); i++) {
		result *= nums[i] + 1;
	}
	cout << result - 1 << endl;
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
