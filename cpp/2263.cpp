#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

vector<int> in, post, idx;
stack<int> result;

void f(int start, int end) {
	int root = post.back(), rootIndex = idx[root];
	post.pop_back();
	if (rootIndex + 1 <= end) {
		f(rootIndex + 1, end);
	}
	if (rootIndex - 1 >= start) {
		f(start, rootIndex - 1);
	}
	result.push(root);
}

void solve() {
	int n;
	cin >> n;
	in.resize(n);
	post.resize(n);
	idx.resize(n + 1);
	for (int i = 0; i < n; ++i)
		cin >> in[i];
	for (int i = 0; i < n; ++i)
		cin >> post[i];
	for (int i = 0; i < n; ++i)
		idx[in[i]] = i;
	f(0, n - 1);
	while (!result.empty()) {
		cout << result.top() << ' ';
		result.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
