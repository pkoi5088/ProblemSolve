#include <iostream>
#include <string>
#include <vector>
#define MAX 20
#define endl '\n'

using namespace std;

int N;

void flip(vector<string>& arr, int type) {
	for (int i = 0; i < N; ++i)
		arr[i][type] ^= ('H' ^ 'T');
}

int count(vector<string> arr, int type) {
	for (int i = 0; i < N; ++i) {
		if (type & (1 << i)) {
			flip(arr, i);
		}
	}

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		int tmp = 0;
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] == 'T') tmp++;
		}
		ret += min(tmp, N - tmp);
	}
	return ret;
}

void solve() {
	vector<string> arr;
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int result = MAX * MAX + 1;
	for (int i = 0; i < (1 << N); ++i) {
		result = min(result, count(arr, i));
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
