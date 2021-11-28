#include <iostream>
#include <queue>
#define MAX 10001
#define endl '\n'

using namespace std;

//0:왼쪽, 1:오른쪽
int child[MAX][2], parent[MAX] = { 0, }, nodeCount[MAX], col[MAX] = { 0, }, width[MAX][2] = { 0, };
int N;

void setNodeCount(int idx) {
	if (idx == -1) return;
	setNodeCount(child[idx][0]);
	setNodeCount(child[idx][1]);
	nodeCount[idx] = 1;
	if (child[idx][0] != -1)
		nodeCount[idx] += nodeCount[child[idx][0]];
	if (child[idx][1] != -1)
		nodeCount[idx] += nodeCount[child[idx][1]];
}

void setCol(int idx, int offset) {
	if (idx == -1) return;
	int leftCnt = 0;
	if (child[idx][0] != -1)
		leftCnt = nodeCount[child[idx][0]];
	col[idx] = offset + leftCnt + 1;
	setCol(child[idx][0], offset);
	setCol(child[idx][1], col[idx]);
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int A, B, C;
		cin >> A >> B >> C;
		child[A][0] = B;
		child[A][1] = C;
		if (B != -1)
			parent[B] = A;
		if (C != -1)
			parent[C] = A;
	}

	int root = 1, maxLevel = -1, retLevel = 0, retWidth = -1;
	while (parent[root] != 0)
		root = parent[root];
	setNodeCount(root);
	setCol(root, 0);

	//first:idx, second:level
	queue<pair<int, int>> q;
	q.push({ root,1 });
	while (!q.empty()) {
		int idx = q.front().first, level = q.front().second;
		q.pop();

		if (width[level][0] == 0) width[level][0] = col[idx];
		else width[level][0] = min(width[level][0], col[idx]);
		if (width[level][1] == 0) width[level][1] = col[idx];
		else width[level][1] = max(width[level][1], col[idx]);

		maxLevel = max(maxLevel, level);

		if (child[idx][0] != -1)
			q.push({ child[idx][0],level + 1 });
		if (child[idx][1] != -1)
			q.push({ child[idx][1],level + 1 });
	}

	for (int i = 1; i <= maxLevel; ++i) {
		if (retWidth < width[i][1] - width[i][0] + 1) {
			retWidth = width[i][1] - width[i][0] + 1;
			retLevel = i;
		}
	}
	cout << retLevel << ' ' << retWidth << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}