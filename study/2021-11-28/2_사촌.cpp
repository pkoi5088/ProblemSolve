#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/9489
*/

//v[idx:]범위에서 처음으로 나오는 연속하는 수열의 범위를 반환
void getRange(vector<int>& v, int idx, int& ret) {
	ret = idx + 1;
	while (ret < v.size() && v[ret - 1] + 1 == v[ret])
		ret += 1;
}

void solve() {
	while (true) {
		int N, K, idx;
		int parent[MAX];
		vector<int> child[MAX];

		cin >> N >> K;

		vector<int> v;
		for (int i = 0; i < N; ++i) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
			if (v[i] == K)
				idx = i;
		}

		if (N == 0 && K == 0)
			break;
		else if (N == 1) {
			cout << 0 << endl;
			continue;
		}

		int root = 0, start = 1, end;
		parent[root] = -1;
		while (root < N) {
			if (start < N) {
				getRange(v, start, end);
				for (int i = start; i < end; ++i) {
					child[root].push_back(i);
					parent[i] = root;
				}
				start = end;
			}
			root += 1;
		}

		int p = parent[idx], pp;
		if (p == -1) {
			cout << 0 << endl;
			continue;
		}
		else if ((pp = parent[p]) == -1) {
			cout << 0 << endl;
			continue;
		}
		int cnt = 0;
		for (int i = 0; i < child[pp].size(); ++i) {
			if (child[pp][i] != p) {
				int next = child[pp][i];
				cnt += child[next].size();
			}
		}
		cout << cnt << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}