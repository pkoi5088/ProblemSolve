#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
#define MAX 100000

using namespace std;

/*
	https://www.acmicpc.net/problem/19637

*/

int N, M;
pair<string, int> arr[MAX];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	while (M--) {
		int num, left = 0, right = N - 1, ret = 0;
		cin >> num;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (num > arr[mid].second) {
				left = mid + 1;
			}
			else {
				ret = mid;
				right = mid - 1;
			}
		}
		cout << arr[ret].first << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}