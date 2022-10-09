#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 2000

using namespace std;

/*
	https://www.acmicpc.net/problem/1253
*/

int N;
int arr[MAX];
vector<int> v;

bool check(int num) {
	int left = 0, right = v.size() - 1;
	while (left < right) {
		int tmp = v[left] + v[right];
		if (v[left] + v[right] == num) {
			return true;
		}
		else if (v[left] + v[right] < num) {
			left += 1;
		}
		else {
			right -= 1;
		}
	}
	return false;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int ret = 0;
	for (int i = 0; i < N; ++i) {
		v.clear();
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			v.push_back(arr[j]);
		}
		if (check(arr[i]))
			ret += 1;
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}