#include <iostream>
#include <cstring>
#define MAX 11
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/9095
*/

int dp[MAX];

int getDP(int n) {
    if (n < 1) return 0;
    if (dp[n] != -1) return dp[n];

    return dp[n] = getDP(n - 1) + getDP(n - 2) + getDP(n - 3);
}

void solve() {
    int n;
    cin >> n;
    cout << getDP(n) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}