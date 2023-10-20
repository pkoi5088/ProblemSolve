#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

void swap(vector<int>& v, int a, int b) {
	int tmp = v[b];
	for (int i = b; i > a; --i) {
		v[i] = v[i - 1];
	}
	v[a] = tmp;
}

void solve() {
	int N, S;
	cin >> N;
	vector<int> v;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	cin >> S;

	for (int start = 0; start < N && S>0; ++start) {
		int idx = start;
		for (int end = start; end < N && end <= start + S; ++end) {
			if (v[idx] < v[end]) idx = end;
		}
		swap(v, start, idx);
		S -= idx - start;
	}

	for (int a : v) {
		cout << a << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}