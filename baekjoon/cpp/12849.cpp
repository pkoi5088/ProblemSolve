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

int dp[8] = { 0 }, tmp[8] = { 0 };
int D;

void solve() {
	cin >> D;
	dp[0] = 1;
	while (D--) {
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (graph[i][j]) {
					tmp[j] = (tmp[j] + dp[i]) % MOD;
				}
			}
		}
		for (int i = 0; i < 8; ++i) {
			dp[i] = tmp[i];
			tmp[i] = 0;
		}
	}
	cout << dp[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
