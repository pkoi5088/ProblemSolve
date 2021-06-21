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

int N, M;

void solve() {
	map<string, int> hash;
	vector<string> v;
	cin >> N >> M;
	v.resize(N);
	
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		hash.insert({ s, i + 1 });
		v[i] = s;
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (isalpha(s[0])) {
			cout << hash.find(s)->second << endl;
		}
		else {
			cout << v[stoi(s) - 1] << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
