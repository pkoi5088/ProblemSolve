#include <iostream>
#include <cstring>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/9465
*/

int getDP(int N, int flag, int arr[MAX][2], int dp[MAX][2]) {
    if (N < 0) return 0;
    if (dp[N][flag] != -1) return dp[N][flag];

    dp[N][flag] = max(getDP(N - 1, !flag, arr, dp), getDP(N - 2, !flag, arr, dp)) + arr[N][flag];
    return dp[N][flag];
}

void solve() {
    int arr[MAX][2], dp[MAX][2] = { 0, };
    int N, ret = -1;
    cin >> N;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[j][i];
        }
    }
    memset(dp, -1, sizeof(dp));
    getDP(N - 1, 0, arr, dp);
    getDP(N - 1, 1, arr, dp);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            ret = max(ret, dp[i][j]);
        }
    }
    cout << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}