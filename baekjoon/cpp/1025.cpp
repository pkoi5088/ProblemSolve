#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
#define MAX 9

using namespace std;

/*
	https://www.acmicpc.net/problem/1025
*/

string arr[MAX];
int N, M;
vector<long long> table;

bool check(long long t) {
	int left = 0, right = table.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (table[mid] == t) {
			return true;
		}
		else if (table[mid] < t) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	for (long long i = 0; i * i < 10000000000; ++i) {
		table.push_back(i * i);
	}

	long long ret = -1;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			for (int dx = -N; dx <= N; ++dx) {
				for (int dy = -M; dy <= M; ++dy) {
					if (dx == 0 && dy == 0) continue;
					int i = x, j = y;
					string tmp = "";
					while (i >= 0 && i < N && j >= 0 && j < M) {
						tmp += arr[i][j];
						if (check((long long)stoull(tmp))) {
							ret = max(ret, (long long)stoull(tmp));
						}
						i += dx;
						j += dy;
					}
				}
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