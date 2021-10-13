#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 100000
#define endl '\n'

using namespace std;

pair<int, int> num[MAX];
int idx[MAX];
int N;

//v에서 v[i]>a를 만족하는 최소 i찾기
int getLower(vector<int>& v, int a) {
	int low = 0, high = v.size() - 1;
	int ret = high + 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (v[mid] < a) {
			low = mid + 1;
		}
		else {
			ret = min(ret, mid);
			high = mid - 1;
		}
	}
	return ret;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		num[i] = { a - 1,b - 1 };
	}
	sort(num, &num[N]);

	//수열 찾기
	vector<int> v;
	for (int i = 0; i < N; ++i) {
		if (v.empty() || v.back() < num[i].second) {
			v.push_back(num[i].second);
			idx[i] = v.size();
		}
		else {
			int lower = getLower(v, num[i].second);
			v[lower] = num[i].second;
			idx[i] = lower + 1;
		}
	}
	
	//원소 추적
	int target = -1;
	v.clear();
	for (int i = 0; i < N; ++i) {
		if (target < idx[i])
			target = idx[i];
	}

	for (int i = N - 1; i >= 0; --i) {
		if (idx[i] == target) {
			target -= 1;
		}
		else {
			v.push_back(num[i].first + 1);
		}
	}
	cout << v.size() << endl;
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
