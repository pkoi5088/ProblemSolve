#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#define MOD 1000000007
#define MAX 100001
#define endl '\n'

using namespace std;
/*
0: 정보과학관
1: 전산관
2: 미래관
3: 신양관
4: 한경직기념관
5: 진리관
6. 형남공학관
7. 학생회관
*/
bool graph[8][8] = {
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,1,0},
	{0,0,0,1,1,0,0,1},
	{0,0,0,0,1,0,0,1},
	{0,0,0,0,0,1,1,0}
};

vector<vector<int>> matProduct(vector<vector<int>> m1, vector<vector<int>> m2) {
	vector<vector<int>> ret = m1;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			long long tmp = 0;
			for (int k = 0; k < 8; ++k) {
				tmp += m1[i][k] * (long long)m2[k][j];
				tmp %= MOD;
			}
			ret[i][j] = tmp;
		}
	}
	return ret;
}

vector<vector<int>> getMat(vector<vector<int>> m, int N) {
	if (N == 1) return m;
	vector<vector<int>> t = getMat(m, N / 2);
	if (N % 2) {
		return matProduct(m, matProduct(t, t));
	}
	else {
		return matProduct(t, t);
	}
}

void solve() {
	vector<vector<int>> M(8);
	int D;
	cin >> D;
	for (int i = 0; i < 8; ++i)
		M[i].resize(8);
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			M[i][j] = graph[i][j];
		}
	}
	M = getMat(M, D);
	cout << M[0][0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
