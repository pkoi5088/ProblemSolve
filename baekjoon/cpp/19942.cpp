#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 7501
#define MAX 15
#define endl '\n'

using namespace std;

int p[MAX], f[MAX], s[MAX], v[MAX], c[MAX];
int mp, mf, ms, mv;
int N;
pair<int, vector<int>> result;
vector<int> picks;

//num번 식재료를 골랐다.
void pick(int num) {
	int sump = 0, sumf = 0, sums = 0, sumv = 0, sumc = 0;
	for (int i = 0; i < picks.size(); ++i) {
		sump += p[picks[i]];
		sumf += f[picks[i]];
		sums += s[picks[i]];
		sumv += v[picks[i]];
		sumc += c[picks[i]];
	}
	if (sump >= mp && sumf >= mf && sums >= ms && sumv >= mv && result.first > sumc) {
		result.first = sumc;
		result.second = picks;
	}
	for (int i = num + 1; i < N; ++i) {
		picks.push_back(i);
		pick(i);
		picks.pop_back();
	}
}

void solve() {
	cin >> N >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; ++i) {
		cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
	}
	result.first = INF;

	for (int i = 0; i < N; ++i) {
		picks.push_back(i);
		pick(i);
		picks.pop_back();
	}
	if (result.first == INF) {
		cout << -1;
	}
	else {
		cout << result.first << endl;
		for (int i = 0; i < result.second.size(); ++i) {
			cout << result.second[i] + 1 << ' ';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
