#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

void solve() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		arr[i] = i + 1;
	do {
		for (int i = 0; i < N; ++i)
			cout << arr[i] << ' ';
		cout << endl;
	} while (next_permutation(arr.begin(), arr.end()));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
