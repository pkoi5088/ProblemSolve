#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

vector<int> v;

void merge(int left, int right) {
	vector<int> tmp;
	int mid = (left + right) / 2;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right) {
		if (v[i] < v[j]) {
			tmp.push_back(v[i++]);
		}
		else {
			tmp.push_back(v[j++]);
		}
	}

	while (i <= mid)
		tmp.push_back(v[i++]);
	while (j <= right)
		tmp.push_back(v[j++]);

	for (int i = 0; i < tmp.size(); i++) {
		v[left + i] = tmp[i];
	}
}

void mergeSort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, right);
	}
}

void solve() {
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	mergeSort(0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << v[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
