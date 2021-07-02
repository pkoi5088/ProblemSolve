#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
#define endl "\n"

using namespace std;

vector<int> arr;
int nums[MAX];
int N, M;

void pick(int n) {
	if (n < N) {
		arr.push_back(n);
		if (arr.size() == M) {
			for (int i = 0; i < M; ++i) cout << nums[arr[i]] << ' ';
			cout << endl;
		}
		else {
			pick(n + 1);
		}
		arr.pop_back();
		pick(n + 1);
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> nums[i];
	sort(nums, nums + N);
	pick(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}