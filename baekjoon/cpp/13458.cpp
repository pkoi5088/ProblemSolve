#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#define MAX 1000000
#define endl '\n'

using namespace std;

void solve() {
	int num[MAX];
	int N, B, C;
	long long mainS = 0, subS = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> num[i];
	cin >> B >> C;
	
	mainS = N;
	for (int i = 0; i < N; ++i) {
		num[i] -= B;
		if (num[i] > 0) subS += num[i] / C + (num[i] % C >= 1);
	}
	cout << mainS + subS;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
