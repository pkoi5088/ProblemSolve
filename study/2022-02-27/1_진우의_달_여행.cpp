#include <iostream>
#include <cstring>
#define MAX 1000
#define INF 1000000000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/17485
*/

//0: 왼대각선, 1: 아래, 2: 오른대각선
int dp[MAX][MAX][3], arr[MAX][MAX];
int N, M;

int getDP(int n, int m, int dir) {
    if (m < 0 || m >= M) return INF;
    int& ret = dp[n][m][dir];
    if (ret != INF) return ret;
    
    if (dir == 0) {
        ret = min(getDP(n - 1, m + 1, 1), getDP(n - 1, m + 1, 2)) + arr[n][m];
    }
    else if (dir == 1) {
        ret = min(getDP(n - 1, m, 0), getDP(n - 1, m, 2)) + arr[n][m];
    }
    else {
        ret = min(getDP(n - 1, m - 1, 0), getDP(n - 1, m - 1, 1)) + arr[n][m];
    }
    return ret;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = INF;
        }
    }
    for (int j = 0; j < M; ++j) {
        dp[0][j][0] = dp[0][j][1] = dp[0][j][2] = arr[0][j];
    }

    int ret = INF;
    for (int j = 0; j < M; ++j) {
        for (int d = 0; d < 3; ++d)
            ret = min(ret, getDP(N - 1, j, d));
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