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

struct Result {
	long long a, b, c;
};

long long num[MAX];
int N;

void solve() {
	Result result;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];
	sort(num, &num[N]);
	result.a = num[0];
	result.b = num[1];
	result.c = num[2];

	for (int i = 0; i < N - 2; ++i) {
		int left = i + 1, right = N - 1;
		while (left < right) {
			long long tmp = abs(num[i] + num[left] + num[right]);
			if (abs(result.a + result.b + result.c) > tmp) {
				result.a = num[i];
				result.b = num[left];
				result.c = num[right];
			}

			if (num[left] + num[right] < -num[i]) {
				left += 1;
			}
			else {
				right -= 1;
			}
		}
	}
	cout << result.a << ' ' << result.b << ' ' << result.c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
