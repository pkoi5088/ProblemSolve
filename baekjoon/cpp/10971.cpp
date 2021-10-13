#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10
#define endl "\n"

using namespace std;

void solve() {
	int N, graph[MAX][MAX], result = -1;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> graph[i][j];
		}
		arr[i] = i;
	}
	do {
		int tmp = 0, flag = 0;
		for (int i = 0; i < N; ++i) {
			if (graph[arr[i]][arr[(i + 1) % N]] == 0) flag = 1;
			tmp += graph[arr[i]][arr[(i + 1) % N]];
		}
		if (flag) continue;
		if (result == -1) result = tmp;
		else result = min(result, tmp);
	} while (next_permutation(arr.begin(), arr.end()));
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}