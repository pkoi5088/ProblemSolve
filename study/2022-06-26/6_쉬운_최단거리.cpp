#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 1000

using namespace std;

/*
    https://www.acmicpc.net/problem/14940
*/

int dist[MAX][MAX], arr[MAX][MAX];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void solve() {
    queue<pair<pair<int, int>, int>> q;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dist[i][j] = -1;
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                q.push({ { i,j },0 });
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second, d = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 0 || dist[nx][ny] != -1)
                continue;
            q.push({ {nx,ny},d + 1 });
            dist[nx][ny] = d + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 0) {
                cout << 0 << ' ';
            }
            else {
                cout << dist[i][j] << ' ';
            }
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}