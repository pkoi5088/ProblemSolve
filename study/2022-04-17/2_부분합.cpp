#include <iostream>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/1806
*/

int nums[MAX];
int N, S;

void solve() {
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}

	int left = 0, right = 0, sum = nums[0], result = MAX + 1;
	while (right < N) {
		if (sum >= S) {
			result = min(result, right - left + 1);
			sum -= nums[left];
			left += 1;
		}
		else {
			right += 1;
			if (right < N)
				sum += nums[right];
		}
	}
	cout << (result == (MAX + 1) ? 0 : result);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}