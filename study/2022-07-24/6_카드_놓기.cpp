#include <iostream>
#include <string>
#include <vector>
#include <map>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/5568
*/

bool check[10];
int arr[10];
int N, K;
string tmp;
map<string, int> table;

void dfs(int idx, int length) {
	string before = tmp;
	tmp += to_string(arr[idx]);
	if (length >= K) {
		table[tmp] = 1;
	}
	else {
		check[idx] = true;
		for (int i = 0; i < N; ++i) {
			if (check[i]) continue;
			dfs(i, length + 1);
		}
		check[idx] = false;
	}
	tmp = before;
}

void solve() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; ++i) {
		dfs(i, 1);
	}
	cout << table.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}