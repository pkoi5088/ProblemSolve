#include <iostream>
#include <vector>
#define MAX 20
#define endl "\n"

using namespace std;

vector<int> start, link;
int graph[MAX][MAX] = { 0 };
int N;

int min(int a, int b) {
	if (a == -1) return b;
	return a < b ? a : b;
}

int abs(int a, int b) {
	return a - b < 0 ? -(a - b) : a - b;
}

void pick(int n, int& result) {
	if (n < N) {
		start.push_back(n);
		if (start.size() == N / 2) {
			int startVal = 0, linkVal = 0;
			for (int i = n + 1; i < N; ++i) {
				link.push_back(i);
			}
			for (int i = 0; i < N / 2; ++i) {
				for (int j = 0; j < N / 2; ++j) {
					startVal += graph[start[i]][start[j]];
					linkVal += graph[link[i]][link[j]];
				}
			}
			result = min(result, abs(startVal, linkVal));
			for (int i = n + 1; i < N; ++i) {
				link.pop_back();
			}
		}
		else {
			pick(n + 1, result);
		}
		start.pop_back();
		link.push_back(n);
		pick(n + 1, result);
		link.pop_back();
	}
}

void solve() {
	int result = -1;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> graph[i][j];
		}
	}
	pick(0, result);
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}