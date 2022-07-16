#include <iostream>
#define endl '\n'
#define MAX 100

using namespace std;

/*
	https://www.acmicpc.net/problem/2798
*/

int N, M;
int arr[MAX];

void solve() {
	int ret = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j < N - 1; ++j) {
			for (int k = j + 1; k < N; ++k) {
				if (ret < arr[i] + arr[j] + arr[k] && arr[i] + arr[j] + arr[k] <= M) {
					ret = arr[i] + arr[j] + arr[k];
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