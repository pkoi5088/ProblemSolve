#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 10001
#define endl '\n'

using namespace std;

int idx[MAX], num[MAX];
int N;

void flip(int a, int b) {
	for (int i = a; i <= (a + b) / 2; ++i) {
		swap(num[i], num[b - i + a]);
		idx[num[i]] = i;
		idx[num[b - i + a]] = b - i + a;
	}
}

void solve() {
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> num[i];
		idx[num[i]] = i;
	}

	int correct = 1, cnt = 0;
	while (correct <= N) {
		if (num[correct] != correct) {
			v.push_back({ correct,idx[correct] });
			flip(correct, idx[correct]);
			cnt += 1;
		}
		correct += 1;
	}
	for (int i = cnt; i < 2; ++i)
		cout << "1 1" << endl;
	for (int i = 0; i < v.size(); ++i)
		cout << v[i].first << ' ' << v[i].second << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
