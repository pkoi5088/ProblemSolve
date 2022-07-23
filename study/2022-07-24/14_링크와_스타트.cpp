#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define MAX 20

using namespace std;

/*
	https://www.acmicpc.net/problem/15661
*/

int N;
int arr[MAX][MAX];

int min(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	return a < b ? a : b;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	int ret = -1;
	for (int i = 1; i < (1 << N) - 1; ++i) {
		int link = 0, start = 0;
		for (int from = 0; from < N; ++from) {
			for (int to = 0; to < N; ++to) {
				//같은 팀이면
				if ((i & (1 << from)) == 0 && (i & (1 << to)) == 0) {
					start += arr[from][to];
				}
				else if ((i & (1 << from)) != 0 && (i & (1 << to)) != 0) {
					link += arr[from][to];
				}
			}
		}
		ret = min(ret, abs(start - link));
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}