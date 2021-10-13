#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 5000
#define endl '\n'

using namespace std;

int nums[MAX];

void solve() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}

	int result = 0;
	sort(nums, nums + N);
	for (int i = N - K; i < N; ++i) {
		result += nums[i];
	}
	result -= (K - 1) * K / 2;
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
