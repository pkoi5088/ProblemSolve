#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	vector<int> mileage;
	int n, m, R = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		vector<int> people;
		int P, L;
		cin >> P >> L;
		people.resize(P);
		for (int j = 0; j < P; ++j)
			cin >> people[j];
		sort(people.begin(), people.end());
		if (P < L) {
			mileage.push_back(1);
		}
		else if (P == L) {
			mileage.push_back(people[0]);
		}
		else {
			mileage.push_back(people[P - L]);
		}
	}
	sort(mileage.begin(), mileage.end());

	int i;
	for (i = 0; i < n; ++i) {
		if (mileage[i] > m) {
			break;
		}
		m -= mileage[i];
	}
	cout << i;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
