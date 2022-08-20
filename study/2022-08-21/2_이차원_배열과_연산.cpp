#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/17140
*/

vector<vector<int>> arr;
int r, c, k;

bool cmp(pair<int, int>p1, pair<int, int>p2) {
	return p1.second < p2.second;
}

void R() {
	vector<vector<int>> ret;
	vector<vector<pair<int, int>>> tmp(arr.size());
	//각각의 행에 대해서
	for (int i = 0; i < arr.size(); ++i) {
		vector<int> sortV;
		for (int j = 0; j < arr[i].size(); ++j) {
			sortV.push_back(arr[i][j]);
		}
		sort(sortV.begin(), sortV.end());

		for (int idx = 0; idx < sortV.size(); ++idx) {
			if (sortV[idx] == 0) continue;
			if (tmp[i].empty() || tmp[i].back().first != sortV[idx]) {
				tmp[i].push_back({ sortV[idx],1 });
			}
			else {
				tmp[i][tmp[i].size() - 1].second += 1;
			}
		}
	}
	//행 사이즈 조정
	int maxSize = 0;
	for (int i = 0; i < tmp.size(); ++i) {
		maxSize = max(maxSize, (int)tmp[i].size() * 2);
	}
	ret.resize(arr.size(), vector<int>(maxSize, 0));

	//각각의 행에 대해서
	for (int i = 0; i < tmp.size(); ++i) {
		sort(tmp[i].begin(), tmp[i].end(), cmp);
		for (int j = 0; j < tmp[i].size(); ++j) {
			ret[i][2 * j] = tmp[i][j].first;
			ret[i][2 * j + 1] = tmp[i][j].second;
		}
	}

	//최대 사이즈 조정
	while (ret.size() > 100) {
		ret.pop_back();
	}
	for (int i = 0; i < ret.size(); ++i) {
		while (ret[i].size() > 100) {
			ret[i].pop_back();
		}
	}

	arr = ret;
}

void C() {
	vector<vector<int>> ret;
	vector<vector<pair<int, int>>> tmp(arr[0].size());
	//각각의 열에 대해서
	for (int i = 0; i < arr[0].size(); ++i) {
		vector<int> sortV;
		for (int j = 0; j < arr.size(); ++j) {
			sortV.push_back(arr[j][i]);
		}
		sort(sortV.begin(), sortV.end());

		for (int idx = 0; idx < sortV.size(); ++idx) {
			if (sortV[idx] == 0) continue;
			if (tmp[i].empty() || tmp[i].back().first != sortV[idx]) {
				tmp[i].push_back({ sortV[idx],1 });
			}
			else {
				tmp[i][tmp[i].size() - 1].second += 1;
			}
		}
	}
	//열 사이즈 조정
	int maxSize = 0;
	for (int i = 0; i < tmp.size(); ++i) {
		maxSize = max(maxSize, (int)tmp[i].size() * 2);
	}
	ret.resize(maxSize, vector<int>(arr[0].size(), 0));

	//각각의 열에 대해서
	for (int i = 0; i < tmp.size(); ++i) {
		sort(tmp[i].begin(), tmp[i].end(), cmp);
		for (int j = 0; j < tmp[i].size(); ++j) {
			ret[2 * j][i] = tmp[i][j].first;
			ret[2 * j + 1][i] = tmp[i][j].second;
		}
	}

	//최대 사이즈 조정
	while (ret.size() > 100) {
		ret.pop_back();
	}
	for (int i = 0; i < ret.size(); ++i) {
		while (ret[i].size() > 100) {
			ret[i].pop_back();
		}
	}

	arr = ret;
}

void solve() {
	cin >> r >> c >> k;
	r -= 1, c -= 1;
	arr.resize(3, vector<int>(3));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> arr[i][j];
		}
	}

	int ret = 0;
	while (ret <= 100) {
		if (arr.size() - 1 >= r && arr[r].size() - 1 >= c && arr[r][c] == k) {
			cout << ret;
			return;
		}

		if (arr.size() >= arr[0].size()) {
			R();
		}
		else {
			C();
		}
		ret += 1;
	}
	cout << -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}