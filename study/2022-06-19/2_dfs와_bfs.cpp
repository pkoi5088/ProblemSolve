#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
    https://www.acmicpc.net/problem/1260
*/

void dfs(int idx, vector<vector<int>>& graph, vector<bool>& check) {
    if (check[idx]) return;
    check[idx] = true;
    cout << idx + 1 << ' ';
    for (int i = 0; i < graph[idx].size(); ++i) {
        int next = graph[idx][i];
        if (check[next]) continue;
        dfs(next, graph, check);
    }
}

void solve() {
    int N, M, V;
    cin >> N >> M >> V;
    vector<vector<int>> graph(N);
    vector<bool> check;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    check.resize(N, false);
    dfs(V - 1, graph, check);
    cout << endl;

    queue<int> q;
    check.clear();
    check.resize(N, false);
    q.push(V - 1);
    check[V - 1] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now + 1 << ' ';
        for (int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i];
            if (check[next]) continue;
            q.push(next);
            check[next] = true;
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