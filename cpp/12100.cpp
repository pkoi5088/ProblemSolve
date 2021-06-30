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
#define endl '\n'

using namespace std;

int result = -1, N;

vector<vector<int>> Up(vector<vector<int>> M) {
	for (int l = 0; l < N; ++l) {
		//위에서부터 0이 아닌 값을 저장
		vector<int> tmp;
		for (int i = 0; i < N; ++i) {
			if (M[i][l] != 0)
				tmp.push_back(M[i][l]);
		}
		int tIdx = 0, mIdx = 0;
		while (tIdx < tmp.size()) {
			if (tIdx < tmp.size() - 1 && tmp[tIdx] == tmp[tIdx + 1]) {
				M[mIdx][l] = 2 * tmp[tIdx];
				tIdx += 2;
				mIdx += 1;
			}
			else {
				M[mIdx][l] = tmp[tIdx];
				tIdx += 1;
				mIdx += 1;
			}
		}
		while (mIdx < N) {
			M[mIdx][l] = 0;
			mIdx += 1;
		}
	}
	return M;
}

vector<vector<int>> Down(vector<vector<int>> M) {
	for (int l = 0; l < N; ++l) {
		//아래서부터 0이 아닌 값을 저장
		vector<int> tmp;
		for (int i = N - 1; i >= 0; --i) {
			if (M[i][l] != 0)
				tmp.push_back(M[i][l]);
		}
		int tIdx = 0, mIdx = N - 1;
		while (tIdx < tmp.size()) {
			if (tIdx < tmp.size() - 1 && tmp[tIdx] == tmp[tIdx + 1]) {
				M[mIdx][l] = 2 * tmp[tIdx];
				tIdx += 2;
				mIdx -= 1;
			}
			else {
				M[mIdx][l] = tmp[tIdx];
				tIdx += 1;
				mIdx -= 1;
			}
		}
		while (mIdx >= 0) {
			M[mIdx][l] = 0;
			mIdx -= 1;
		}
	}
	return M;
}

vector<vector<int>> Left(vector<vector<int>> M) {
	for (int l = 0; l < N; ++l) {
		//왼쪽에서부터 0이 아닌 값을 저장
		vector<int> tmp;
		for (int i = 0; i < N; ++i) {
			if (M[l][i] != 0)
				tmp.push_back(M[l][i]);
		}
		int tIdx = 0, mIdx = 0;
		while (tIdx < tmp.size()) {
			if (tIdx < tmp.size() - 1 && tmp[tIdx] == tmp[tIdx + 1]) {
				M[l][mIdx] = 2 * tmp[tIdx];
				tIdx += 2;
				mIdx += 1;
			}
			else {
				M[l][mIdx] = tmp[tIdx];
				tIdx += 1;
				mIdx += 1;
			}
		}
		while (mIdx < N) {
			M[l][mIdx] = 0;
			mIdx += 1;
		}
	}
	return M;
}

vector<vector<int>> Right(vector<vector<int>> M) {
	for (int l = 0; l < N; ++l) {
		//오른쪽에서부터 0이 아닌 값을 저장
		vector<int> tmp;
		for (int i = N - 1; i >= 0; --i) {
			if (M[l][i] != 0)
				tmp.push_back(M[l][i]);
		}
		int tIdx = 0, mIdx = N - 1;
		while (tIdx < tmp.size()) {
			if (tIdx < tmp.size() - 1 && tmp[tIdx] == tmp[tIdx + 1]) {
				M[l][mIdx] = 2 * tmp[tIdx];
				tIdx += 2;
				mIdx -= 1;
			}
			else {
				M[l][mIdx] = tmp[tIdx];
				tIdx += 1;
				mIdx -= 1;
			}
		}
		while (mIdx >= 0) {
			M[l][mIdx] = 0;
			mIdx -= 1;
		}
	}
	return M;
}

void dfs(vector<vector<int>> M, int depth) {
	if (depth == 5) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				result = max(result, M[i][j]);
			}
		}
	}
	else {
		dfs(Up(M), depth + 1);
		dfs(Down(M), depth + 1);
		dfs(Left(M), depth + 1);
		dfs(Right(M), depth + 1);
	}
}

void solve() {
	vector<vector<int>> M;
	cin >> N;
	M.resize(N);
	for (int i = 0; i < N; ++i)
		M[i].resize(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> M[i][j];
		}
	}
	dfs(M, 0);
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
