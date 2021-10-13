#include <iostream>
#include <vector>
#define MAX 12
#define endl "\n"

using namespace std;

int nums[MAX];

void pick(int n, int& k, vector<int>& arr) {
	if (n < k) {
		arr.push_back(nums[n]);
		if (arr.size() == 6) {
			for (int i = 0; i < 6; ++i) {
				cout << arr[i] << ' ';
			}
			cout << endl;
		}
		else {
			pick(n + 1, k, arr);
		}
		arr.pop_back();
		pick(n + 1, k, arr);
	}
}

void solve() {
	int k;
	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; ++i) cin >> nums[i];
		vector<int> arr;
		pick(0, k, arr);
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}