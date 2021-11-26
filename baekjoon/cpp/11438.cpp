#include <iostream>
#include <vector>
#include <cstring>
#define MAX_N 100001
#define MAX_K 18
#define endl '\n'

using namespace std;

//0:없음, -1:모름
int level[MAX_N], parent[MAX_N], dp[MAX_N][MAX_K];
vector<int> graph[MAX_N];
int N, M;

void setLevel(int idx, int p) {
	if (p != -1) {
		level[idx] = level[p] + 1;
		parent[idx] = p;
	}
	for (int i = 0; i < graph[idx].size(); ++i) {
		if (graph[idx][i] != p)
			setLevel(graph[idx][i], idx);
	}
}

//n번 노드의 2^k번째 부모의 노드를 반환
int getDP(int n, int k) {
	if (n < 1) return 0;
	if (dp[n][k] != -1) return dp[n][k];

	if (k == 0) return dp[n][k] = parent[n];
	return dp[n][k] = getDP(getDP(n, k - 1), k - 1);
}

void solve() {
	memset(level, -1, sizeof(level));
	memset(parent, -1, sizeof(parent));
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	parent[1] = 0;
	level[1] = 1;
	setLevel(1, -1);

	cin >> M;
	while (M--) {
		int A, B;
		cin >> A >> B;
		//A가 더 깊은 노드		
		if (level[A] < level[B])
			swap(A, B);
		while (level[A] != level[B]) {
			int k = 0;
			while (getDP(A, k) != 0 && level[getDP(A, k)] >= level[B])
				k += 1;
			k -= 1;
			A = getDP(A, k);
		}
		while (A != B) {
			int k = 0;
			while (getDP(A, k) != 0 && getDP(A, k) != getDP(B, k))
				k += 1;
			if (k == 0) {
				A = parent[A];
				B = parent[B];
			}
			else {
				k -= 1;
				A = getDP(A, k);
				B = getDP(B, k);
			}
		}
		cout << A << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}