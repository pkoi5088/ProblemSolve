#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/7576
*/

int N, M;
int arr[MAX][MAX];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

//true: 전이가 일어남
bool function(queue<pair<int, int>>& q) {
    queue<pair<int, int>> retq;
    bool ret = false;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != 0) continue;
            ret = true;
            retq.push({ nx,ny });
            arr[nx][ny] = 1;
        }
    }
    q = retq;
    return ret;
}

bool check() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

void solve() {
    queue<pair<int, int>> q;
    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({ i,j });
            }
        }
    }

    int ret = 0;
    while (!check()) {
        if (function(q)) {
            ret += 1;
        }
        else {
            cout << -1;
            return;
        }
    }
    cout << ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}