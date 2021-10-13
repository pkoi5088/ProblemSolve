#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 1000000
#define endl '\n'

using namespace std;

int num[MAX], index[MAX];
int N;

int getLower(vector<int>& v, int number) {
	int low = 0, high = v.size() - 1, ret = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (v[mid] < number) {
			low = mid + 1;
		}
		else {
			ret = mid;
			high = mid - 1;
		}
	}
	return ret;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];

	vector<int> v;
	for (int i = 0; i < N; ++i) {
		if (v.empty() || v.back() < num[i]) {
			v.push_back(num[i]);
			index[i] = v.size() - 1;
		}
		else {
			int idx = getLower(v, num[i]);
			v[idx] = num[i];
			index[i] = idx;
		}
	}

	int target = v.size() - 1, idx = N - 1;
	cout << v.size() << endl;
	v.clear();
	while (idx >= 0) {
		if (index[idx] == target) {
			v.push_back(num[idx]);
			target -= 1;
		}
		idx -= 1;
	}

	for (int i = v.size() - 1; i >= 0; --i) {
		cout << v[i] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
