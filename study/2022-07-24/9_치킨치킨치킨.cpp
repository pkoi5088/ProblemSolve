#include <iostream>
#define endl '\n'
#define MAX 30

using namespace std;

/*
	https://www.acmicpc.net/problem/16439
*/

int N, M;
int arr[MAX][MAX];

int max(int a, int b) {
	return a < b ? b : a;
}

int max(int a, int b,int c) {
	if (a < b) {
		return b < c ? c : b;
	}
	else {
		return a < c ? c : a;
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	int ret = 0;
	for (int i = 0; i < M - 2; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			for (int k = 0; k < M; ++k) {
				int tmp = 0;
				for (int x = 0; x < N; ++x) {
					tmp += max(arr[x][i], arr[x][j], arr[x][k]);
				}
				ret = max(ret, tmp);
			}
		}
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