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
	map<string, string> m;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		m.insert({ s1,s2 });
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		cout << m.find(s)->second << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
