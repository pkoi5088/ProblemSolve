#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/6416
	1. 부모가 없는 노드는 하나 뿐이다.
	2. 부모노드는 오직 하나만 존재한다.
	3. 사이클이 형성되면 안된다.
*/

int findRoot(vector<int>& indegree) {
	int ret = -1;
	for (int i = 0; i < indegree.size(); ++i) {
		if (indegree[i] == 0) {
			if (ret != -1) return -1;
			ret = i;
		}
	}
	return ret;
}

//cycle이 있다.
bool checkCycle(vector<vector<int>>& graph, int root) {
	vector<bool> check;
	check.resize(graph.size(), false);

	queue<int> q;
	q.push(root);
	check[root] = true;
	
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i];
			if (check[next]) return true;
			q.push(next);
			check[next] = true;
		}
	}

	for (int i = 0; i < check.size(); ++i) {
		if (check[i] == false) return true;
	}
	return false;
}

void solve() {
	int k = 0;
	while (true) {
		k += 1;
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		else if (u == 0 && v == 0) {
			cout << "Case " << k << " is a tree." << endl;
			continue;
		}

		map<int, int> table;
		vector<int> indegree;
		vector<vector<int>> graph;
		do {
			int uIdx, vIdx;
			if (table.find(u) == table.end()) {
				table[u] = graph.size();
				graph.push_back(vector<int>());
				indegree.push_back(0);
			}
			uIdx = table[u];

			if (table.find(v) == table.end()) {
				table[v] = graph.size();
				graph.push_back(vector<int>());
				indegree.push_back(0);
			}
			vIdx = table[v];

			graph[uIdx].push_back(vIdx);
			indegree[vIdx] += 1;
			cin >> u >> v;
		} while (u != 0 && v != 0);

		//1번
		int root = findRoot(indegree);
		if (root == -1) {
			cout << "Case " << k << " is not a tree." << endl;
			continue;
		}

		//2,3번
		if (checkCycle(graph, root)) {
			cout << "Case " << k << " is not a tree." << endl;
			continue;
		}
		cout << "Case " << k << " is a tree." << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
