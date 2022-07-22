#include <iostream>
#include <cmath>
#define endl '\n'
#define MAX 10

using namespace std;

/*
	https://www.acmicpc.net/problem/14620
*/

int N;
int arr[MAX][MAX], dx[5]{ -1,1,0,0,0 }, dy[5] = { 0,0,-1,1,0 };

bool distCheck(int a, int b) {
	int ax = a / N, ay = a % N;
	int bx = b / N, by = b % N;
	if (abs(ax - bx) + abs(ay - by) <= 2) {
		return false;
	}
	return true;
}

bool idxCheck(int a) {
	int x = a / N, y = a % N;
	if (x == 0 || x == N - 1 || y == 0 || y == N - 1) return false;
	return true;
}

bool idxCheck(int a, int b, int c) {
	if (!idxCheck(a) || !idxCheck(b) || !idxCheck(c)) return false;
	if (!distCheck(a, b) || !distCheck(a, c) || !distCheck(b, c)) return false;
	return true;
}

int getCost(int a) {
	int x = a / N, y = a % N;
	int ret = 0;
	for (int i = 0; i < 5; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		ret += arr[nx][ny];
	}
	return ret;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	int ret = 300000;
	for (int i = 0; i < N * N - 2; ++i) {
		for (int j = i + 1; j < N * N - 1; ++j) {
			for (int k = j + 1; k < N * N; ++k) {
				if (!idxCheck(i, j, k)) continue;
				ret = min(ret, getCost(i) + getCost(j) + getCost(k));
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