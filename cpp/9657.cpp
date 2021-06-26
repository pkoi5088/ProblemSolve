#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#define MAX 1001
#define endl '\n'

using namespace std;

//1: 상근이가 이긴다.
int visit[MAX] = { 0 };

void solve() {
	int N;
	cin >> N;
	visit[1] = visit[3] = visit[4] = 1;
	visit[2] = 0;
	for (int i = 5; i <= N; ++i) {
		int tmp = visit[i - 1] + visit[i - 3] + visit[i - 4];
		if (tmp < 3) visit[i] = 1;
		else visit[i] = 0;
	}
	cout << (visit[N] == 1 ? "SK" : "CY");
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
