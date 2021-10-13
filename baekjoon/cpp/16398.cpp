#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000

using namespace std;

struct Node {
	int f, t, w;

	bool operator < (Node const &e) {
		return w < e.w;
	}
};

int weight[MAX][MAX];
int parent[MAX] = { 0, };
vector<Node> v;

//N을 M으로
void c_p(int N, int A, int B) {
	for (int i = 0; i < N; i++) {
		if (parent[i] == A)
			parent[i] = B;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> weight[i][j];
			v.push_back({ i,j,weight[i][j] });
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
		parent[i] = i;

	long long result = 0;
	for (int i = 0; i < v.size(); i++) {
		int f = v[i].f, t = v[i].t, w = v[i].w;

		if (f == t || parent[f] == parent[t])
			continue;

		result += w;
		if (f > t)
			c_p(N, parent[f], parent[t]);
		else
			c_p(N, parent[t], parent[f]);
	}

	cout << result;
	return 0;
}