#include <iostream>
#include <cstring>
#define MAX 20
#define endl '\n'

using namespace std;

pair<int, int> arr[MAX];
int dp[MAX][2], K;

int min(int a, int b) {
    if (a == -1) return b;
    else if (b == -1) return a;
    return a < b ? a : b;
}

int getDP(int N, int flag) {
    if (N < 0) return 1000000000;
    if (dp[N][flag] != -1) return dp[N][flag];

    if (flag) {
        dp[N][flag] = getDP(N - 3, 0) + K;
        dp[N][flag] = min(dp[N][flag], getDP(N - 1, 1) + arr[N - 1].first);
        dp[N][flag] = min(dp[N][flag], getDP(N - 2, 1) + arr[N - 2].second);
    }
    else {
        dp[N][flag] = getDP(N - 1, 0) + arr[N - 1].first;
        dp[N][flag] = min(dp[N][flag], getDP(N - 2, 0) + arr[N - 2].second);
    }
    return dp[N][flag];
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int N;
    cin >> N;
    for (int i = 0; i < N-1; ++i)
        cin >> arr[i].first >> arr[i].second;
    cin >> K;
    dp[0][0] = 0;
    dp[0][1] = dp[1][1] = dp[2][1] = 1000000000;

    cout << min(getDP(N - 1, 0), getDP(N - 1, 1)) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}