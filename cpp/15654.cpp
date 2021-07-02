#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 1500
#define endl '\n'

using namespace std;

vector<int> number, result;
vector<bool> visit;
int N, M;

void f() {
	if (result.size() == M) {
		for (int i = 0; i < result.size(); ++i) {
			cout << result[i] << ' ';
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < number.size(); ++i) {
			if (visit[i] == false) {
				visit[i] = true;
				result.push_back(number[i]);
				f();
				result.pop_back();
				visit[i] = false;
			}
		}
	}
}

void solve() {
	cin >> N >> M;
	number.resize(N);
	visit.resize(N, false);
	for (int i = 0; i < N; ++i) {
		cin >> number[i];
	}
	sort(number.begin(), number.end());
	for (int i = 0; i < N; ++i) {
		visit[i] = true;
		result.push_back(number[i]);
		f();
		result.pop_back();
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
