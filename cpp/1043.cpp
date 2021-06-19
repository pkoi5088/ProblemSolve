#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 100
#define endl '\n'

using namespace std;

vector<vector<int>> party;
vector<int> parent, know;
int N, M;

int Find(int x) {
	return x == parent[x] ? x : (parent[x] = Find(parent[x]));
}

void Union(int x, int y) {
	parent[Find(x)] = parent[Find(y)];
}

bool check(const vector<int>& v, const int& target) {
	for (int i = 0; i < v.size(); i++) {
		if (Find(v[i]) == target) {
			return false;
		}
	}
	return true;
}

void solve() {
	int x;
	cin >> N >> M >> x;
	parent.resize(N);
	if (x > 0)
		know.resize(x);
	party.resize(M);

	//부모 초기화
	for (int i = 0; i < N; i++)
		parent[i] = i;

	//이야기를 아는사람 합집합
	for (int i = 0; i < x; i++) {
		cin >> know[i];
		know[i] -= 1;
		if (i > 0) {
			Union(know[i], know[i - 1]);
		}
	}

	//각 파티에 대해서 전체 합집합
	for (int i = 0; i < M; i++) {
		int repeat;
		cin >> repeat;
		party[i].resize(repeat);
		for (int j = 0; j < repeat; j++) {
			cin >> party[i][j];
			party[i][j] -= 1;
		}
		for (int j = 1; j < repeat; j++)
			Union(party[i][j], party[i][j - 1]);
	}

	int target = INF, result = 0;
	if (!know.empty()) {
		target = Find(know[0]);
	}
	for (int i = 0; i < M; i++) {
		if (check(party[i], target)) {
			result += 1;
		}
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
