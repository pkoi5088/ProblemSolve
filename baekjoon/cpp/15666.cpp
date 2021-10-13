#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

vector<int> number, result;
int N, M;

void f() {
	if (result.size() == M) {
		for (int i = 0; i < result.size(); ++i) {
			cout << result[i] << ' ';
		}
		cout << endl;
	}
	else {
		//해당 단계에서 한번 방문한 숫자를 저장
		vector<int> check;
		for (int i = 0; i < N; ++i) {
			if (!result.empty() && result.back() > number[i])
				continue;
			bool c = false;
			for (int j = 0; j < check.size(); ++j) {
				if (number[i] == check[j])
					c = true;
			}
			if (!c) {
				check.push_back(number[i]);
				result.push_back(number[i]);
				f();
				result.pop_back();
			}
		}
	}
}

void solve() {
	cin >> N >> M;
	number.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> number[i];
	sort(number.begin(), number.end());
	f();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
