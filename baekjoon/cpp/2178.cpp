#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define MAX 100
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/2178
*/

struct Node {
    int x, y, dist;
    Node(int ix, int iy, int id) {
        x = ix, y = iy, dist = id;
    }
};

int N, M;
string arr[MAX];
bool visit[MAX][MAX];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void solve() {
    memset(visit, false, sizeof(visit));
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    queue<Node> q;
    q.push(Node(0, 0, 1));
    visit[0][0] = true;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, dist = q.front().dist;
        q.pop();
        if (x == N - 1 && y == M - 1) {
            cout << dist;
            return;
        }

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny] || arr[nx][ny] == '0') continue;
            q.push(Node(nx, ny, dist + 1));
            visit[nx][ny] = true;
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