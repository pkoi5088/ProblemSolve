#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 100

using namespace std;

/*
    https://www.acmicpc.net/problem/17836
*/

struct Node {
    int x, y, type, time;
    Node(int ix, int iy, int it, int intype) {
        x = ix, y = iy, time = it;
        type = intype;
    }
};

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int N, M, T, arr[MAX][MAX];
bool check[MAX][MAX][2] = { false, };
queue<Node> q;

void solve() {
    cin >> N >> M >> T;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    q.push(Node(0, 0, 0, 0));
    check[0][0][0] = 0;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, time = q.front().time;
        int type = q.front().type;
        q.pop();

        if (arr[x][y] == 2) type = 1;
        if (x == N - 1 && y == M - 1) {
            if (time > T) cout << "Fail";
            else cout << time;
            return;
        }

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            //검이 없다
            if (type == 0) {
                if (arr[nx][ny] != 1 && check[nx][ny][type] == false) {
                    q.push(Node(nx, ny, time + 1, type));
                    check[nx][ny][type] = true;
                }
            }
            //검이 있다
            else {
                if (check[nx][ny][type] == false) {
                    q.push(Node(nx, ny, time + 1, type));
                    check[nx][ny][type] = true;
                }
            }
        }
    }
    cout << "Fail";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}