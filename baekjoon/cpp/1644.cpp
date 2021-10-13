#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 4000001
#define endl '\n'

using namespace std;

bool isPrime[MAX] = { false };
vector<int> prime;
int N, result = 0;

void solve() {
	cin >> N;
	for (int i = 2; i < N + 1; ++i) {
		if (isPrime[i] == false) {
			for (int j = i * 2; j < N + 1; j += i) {
				isPrime[j] = true;
			}
		}
	}
	for (int i = 2; i < N + 1; ++i) {
		if (isPrime[i] == false)
			prime.push_back(i);
	}

	int left = 0, right = 0, sum = 2;
	while (right < prime.size()) {
		if (sum == N) {
			result += 1;
			right += 1;
			if (right < prime.size())
				sum += prime[right];
		}
		else if (sum < N) {
			right += 1;
			if (right < prime.size())
				sum += prime[right];
		}
		else {
			sum -= prime[left];
			left += 1;
		}
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
