#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 100000
#define INF 1000000001
#define endl '\n'

using namespace std;

int num[MAX];
int N;

void solve() {
	int left, right, resultL = INF, resultR = INF;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];
	sort(num, &num[N]);
	left = 0, right = N - 1;

	while (left < right) {
		if (abs(num[left] + num[right]) < abs(resultL + resultR)) {
			resultL = num[left];
			resultR = num[right];
		}
		if (num[left] + num[right] < 0) {
			left += 1;
		}
		else {
			right -= 1;
		}
	}
	cout << resultL << ' ' << resultR;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
