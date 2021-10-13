#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 10000
#define endl '\n'

using namespace std;

double num[MAX], result;

void solve() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];
	result = num[0];
	for (int i = 1; i < N; ++i) {
		if (num[i] < num[i] * num[i - 1]) {
			num[i] *= num[i - 1];
		}
		result = max(result, num[i]);
	}
	printf("%.3lf", result);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
