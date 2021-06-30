#include <iostream>
#define MAX 100000
#define endl '\n'

using namespace std;

void solve() {
	int N, idx = 0;
	int nums[MAX];
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> nums[i];
	//증가
	while (idx < N - 1) {
		if (nums[idx] > nums[idx + 1])
			break;
		else if (nums[idx] == nums[idx + 1]) {
			cout << "NO";
			return;
		}
		idx++;
	}
	//감소
	while (idx < N - 1) {
		if (nums[idx] < nums[idx + 1] || nums[idx] == nums[idx + 1]) {
			cout << "NO";
			return;
		}
		idx++;
	}
	cout << "YES";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
