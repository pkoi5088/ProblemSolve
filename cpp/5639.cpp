#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

vector<int> board;
int N;

void f(int start, int end) {
	int root = board[start],mid;
	for (mid = start + 1; mid <= end && board[mid] < root; ++mid);

	if (start + 1 <= mid - 1)
		f(start + 1, mid - 1);
	if (mid <= end)
		f(mid, end);
	cout << root << endl;
}

void solve() {
	while (scanf("%d", &N) != EOF)
		board.push_back(N);
	N = board.size();
	f(0, N - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
