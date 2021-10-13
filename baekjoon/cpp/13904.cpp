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
#define MAX 1000
#define endl '\n'

using namespace std;

void solve() {
	vector<int> day;
	vector<pair<int, int>> hw;
	int N, result = 0;
	cin >> N;
	day.resize(MAX, 0);
	hw.resize(N);
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		hw[i] = { a,b };
	}
	sort(hw.begin(), hw.end());
	for (int i = 0; i < N; ++i) {
		int end = hw[i].first, grade = hw[i].second;
		int rest = 0, restIdx = -1;
		for (int j = 0; j < end; ++j) {
			if (grade - day[j] > rest) {
				restIdx = j;
				rest = grade - day[j];
			}
		}
		if (restIdx != -1) {
			day[restIdx] = grade;
		}
	}

	for (int i = 0; i < MAX; ++i) {
		result += day[i];
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
