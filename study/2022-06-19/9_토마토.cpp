#include <iostream>
#include <vector>
#include <queue>
#define MAX 100
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/7569
*/

struct Node {
    int x, y, z;
    Node(int ix, int iy, int iz) {
        x = ix, y = iy, z = iz;
    }
};

int N, M, H;
int arr[MAX][MAX][MAX];
int dx[6] = { -1,1,0,0,0,0 }, dy[6] = { 0,0,-1,1,0,0 }, dz[6] = { 0,0,0,0,-1,1 };

//true: 전이가 일어남
bool function(queue<Node>& q) {
    queue<Node> retq;
    bool ret = false;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, z = q.front().z;
        q.pop();
        for (int k = 0; k < 6; ++k) {
            int nx = x + dx[k], ny = y + dy[k], nz = z + dz[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H || arr[nx][ny][nz] != 0)
                continue;
            ret = true;
            retq.push(Node(nx, ny, nz));
            arr[nx][ny][nz] = 1;
        }
    }
    q = retq;
    return ret;
}

bool check() {
    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (arr[i][j][k] == 0) return false;
            }
        }
    }
    return true;
}

void solve() {
    queue<Node> q;
    cin >> M >> N >> H;
    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) {
                    q.push(Node(i, j, k));
                }
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