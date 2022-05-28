#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/1913
*/

vector<vector<int>> arr;
vector<pair<int, int>> route;
//상우하좌
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int N, M;

void init() {
    int x = 0, y = 0, dir = 2;
    arr.resize(N, vector<int>(N, 0));
    while (x != N / 2 || y != N / 2) {
        //넣고
        route.push_back({ x,y });
        arr[x][y] = N * N - route.size() + 1;

        int nx = x + dx[dir], ny = y + dy[dir];
        //위치이동
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] != 0) {
            dir = (dir + 3) % 4;
            nx = x + dx[dir], ny = y + dy[dir];
        }
        x = nx, y = ny;
        //방향이동
    }
    route.push_back({ N / 2,N / 2 });
    arr[N / 2][N / 2] = 1;
    reverse(route.begin(), route.end());
}

void solve() {
    cin >> N >> M;
    init();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << route[M - 1].first + 1 << ' ' << route[M - 1].second + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}