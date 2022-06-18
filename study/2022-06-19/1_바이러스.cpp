#include <iostream>
#include <vector>

using namespace std;

/*
    https://www.acmicpc.net/problem/2606
*/

int N, M;
vector<vector<int>> graph;
vector<bool> check;

void dfs(int idx, int p) {
    check[idx] = true;
    for (int i = 0; i < graph[idx].size(); ++i) {
        int next = graph[idx][i];
        if (next != p && !check[next]) {
            dfs(next, idx);
        }
    }
}

void solve() {
    cin >> N >> M;
    graph.resize(N);
    check.resize(N, false);
    while (M--) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    dfs(0, -1);

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        if (check[i])
            ret += 1;
    }
    cout << ret - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    solve();
    return 0;
}