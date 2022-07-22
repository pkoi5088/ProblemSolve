#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1969
*/

int N, M;
vector<string> v;
vector<int> cnt[4];

void solve() {
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	for (int i = 0; i < 4; ++i)
		cnt[i].resize(M, 0);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (v[i][j] == 'A') {
				cnt[0][j] += 1;
			}
			else if (v[i][j] == 'C') {
				cnt[1][j] += 1;
			}
			else if (v[i][j] == 'G') {
				cnt[2][j] += 1;
			}
			else if (v[i][j] == 'T') {
				cnt[3][j] += 1;
			}
		}
	}

	int iret = 0;
	string sret = "";
	for (int i = 0; i < M; ++i) {
		int idx = 0;
		for (int j = 0; j < 4; ++j) {
			if (cnt[j][i] > cnt[idx][i]) {
				idx = j;
			}
		}
		iret += (N - cnt[idx][i]);
		if (idx == 0) {
			sret.push_back('A');
		}
		else if (idx == 1) {
			sret.push_back('C');
		}
		else if (idx == 2) {
			sret.push_back('G');
		}
		else if (idx == 3) {
			sret.push_back('T');
		}
	}
	cout << sret << endl << iret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}