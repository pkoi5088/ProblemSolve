#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 100001
#define endl '\n'

using namespace std;

string goal;
int N;

void getCnt(string& s, int& cnt) {
	for (int i = 0; i < N - 1; ++i) {
		if (s[i] != goal[i]) {
			s[i + 1] = !(s[i + 1] - '0') + '0';
			if (i + 2 < N)
				s[i + 2] = !(s[i + 2] - '0') + '0';
			cnt += 1;
		}
	}
	if (s[N - 1] != goal[N - 1])
		cnt = INF;
}

void solve() {
	int cntPushFirst = 1, cntNotPushFirst = 0, result;
	string pushFirst, notPushFirst;
	cin >> N >> notPushFirst >> goal;
	pushFirst = notPushFirst;
	for (int i = 0; i < 2; ++i)
		pushFirst[i] = !(notPushFirst[i] - '0') + '0';
	getCnt(pushFirst, cntPushFirst);
	getCnt(notPushFirst, cntNotPushFirst);
	result = min(cntNotPushFirst, cntPushFirst);
	cout << (result == INF ? -1 : result);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
