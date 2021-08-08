#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200000
#define endl '\n'

using namespace std;

int arr[MAX];
int N, C;

int check(int limit) {
	//limit를 넘기면 공유기를 설치한다.
	vector<int> v;
	v.push_back(0);
	int idx = 1;
	while (idx < N && v.size() < C) {
		if (arr[idx]-arr[v.back()] >= limit) {
			v.push_back(idx);
		}
		idx++;
	}

	if (v.size() != C)
		return -1;
	v.back() = N - 1;

	int ret = -1;
	for (int i = 0; i < v.size() - 1; ++i) {
		if (ret == -1) ret = arr[v[i + 1]] - arr[v[i]];
		else ret = min(ret, arr[v[i + 1]] - arr[v[i]]);
	}
	return ret;
}

void solve() {
	int result = -1;
	cin >> N >> C;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
    
	int maximum = arr[N - 1] - arr[0], minimum = 1;
	while (minimum <= maximum) {
		int mid = (minimum + maximum) / 2, tmp = -1;
		if ((tmp = check(mid)) != -1) {
			if (result == -1)
				result = tmp;
			else
				result = max(result, tmp);
			minimum = mid + 1;
		}
		else {
			maximum = mid - 1;
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
