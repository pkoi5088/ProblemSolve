#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 401
#define endl '\n'

using namespace std;

vector<unsigned int> v;
int N, result = MAX;

void flipRow(int n) {
	unsigned int tmp = (1 << N) - 1;
	v[n] ^= tmp;
}

void flipCol(int n) {
	unsigned int tmp = (1 << n);
	for (int i = 0; i < N; ++i) {
		v[i] ^= tmp;
	}
}

void f() {
	//뒷면 개수 확인
	int check = 0;
	for (int i = 0; i < N; ++i) {
		unsigned int tmp = v[i];
		while (tmp > 0) {
			if (tmp % 2)
				check += 1;
			tmp /= 2;
		}
	}
	result = min(result, check);

	//행 확인
	for (int i = 0; i < N; ++i) {
		unsigned int tmp = v[i];
		int cnt = 0;
		while (tmp > 0) {
			if (tmp % 2)
				cnt += 1;
			tmp /= 2;
		}
		if (cnt > N / 2) {
			flipRow(i);
			f();
			flipRow(i);
		}
	}

	//열 확인
	for (int i = 0; i < N; ++i) {
		unsigned int tmp = (1 << i);
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			if (v[j] & tmp)
				cnt += 1;
		}
		if (cnt > N / 2) {
			flipCol(i);
			f();
			flipCol(i);
		}
	}
}

void solve() {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j) {
			if (s[j] == 'T') {
				v[i] |= (1 << j);
			}
		}
	}
	f();
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
