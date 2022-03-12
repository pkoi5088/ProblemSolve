#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

vector<int> v;
int N;

void solve() {
	vector<int> tmp;
	int R[2] = { 4001,-4001 }, F[8001] = { 0 };
	double S = 0;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		S += v[i];
		R[0] = min(R[0], v[i]);
		R[1] = max(R[1], v[i]);
		//-4000 ~ 4000 => 0 ~ 8000
		F[v[i] + 4000] += 1;
	}
	int a = 0;
	for (int i = 0; i <= 8000; i++) {
		if (F[i] > F[a]) {
			a = i;
		}
	}
	for (int i = 0; i <= 8000; i++) {
		if (F[i] == F[a]) {
			tmp.push_back(i - 4000);
		}
	}

	sort(v.begin(), v.end());
	sort(tmp.begin(), tmp.end());
	cout << (int)round(S / N) << endl;
	cout << v[v.size() / 2] << endl;
	cout << (tmp.size() >= 2 ? tmp[1] : tmp[0]) << endl;
	cout << abs(R[0]-R[1]) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
