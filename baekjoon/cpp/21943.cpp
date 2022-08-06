#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/21943
*/

int N, P, Q;
vector<int> num, op;
int ret = -1;

int calculation() {
	int ret = 1;
	int nIdx = 0, oIdx = 0;
	vector<int> tmp;
	while (nIdx < N) {
		if (nIdx == 0) {
			tmp.push_back(num[nIdx]);
			nIdx += 1;
		}
		else {
			//덧셈
			if (op[oIdx]) {
				int t = tmp.back();
				tmp.pop_back();
				tmp.push_back(t + num[nIdx]);
			}
			//곱셈
			else {
				tmp.push_back(num[nIdx]);
			}
			nIdx += 1;
			oIdx += 1;
		}
	}

	for (int a : tmp) {
		ret *= a;
	}
	return ret;
}

void solve() {
	cin >> N;
	num.resize(N);
	op.resize(N - 1);
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	cin >> P >> Q;
	for (int i = 0; i < P; ++i) {
		op[i] = 1;
	}

	do {
		do {
			ret = max(ret, calculation());
		} while (prev_permutation(op.begin(), op.end()));
	} while (next_permutation(num.begin(), num.end()));
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}