#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#define INF 20000001
#define MAX 20
#define endl '\n'

using namespace std;

vector<int> v;
pair<int, int> points[MAX];
int N;
double result;

//a를 넣고 dfs연산
void dfs(int a) {
	if (v.size() == N / 2) {
		long long x = 0, y = 0;
		int vIdx = 0, idx = 0;
		while (vIdx < N / 2 && idx < N) {
			while (idx < v[vIdx]) {
				x -= points[idx].first;
				y -= points[idx].second;
				idx += 1;
			}
			x += points[idx].first;
			y += points[idx].second;
			vIdx += 1;
			idx += 1;
		}
		while (idx < N) {
			x -= points[idx].first;
			y -= points[idx].second;
			idx += 1;
		}
		result = min(result, sqrt((double)(x * x + y * y)));
	}
	else {
		for (int i = a + 1; i < N; ++i) {
			v.push_back(i);
			dfs(i);
			v.pop_back();
		}
	}
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		points[i] = { a,b };
	}
	result = INF;

	for (int i = 0; i < N; ++i) {
		v.push_back(i);
		dfs(i);
		v.pop_back();
	}
	printf("%.12lf\n", result);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
