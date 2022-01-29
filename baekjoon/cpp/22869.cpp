#include <iostream>
#include <cstring>
#define MAX 5000
#define endl '\n'

using namespace std;

int K;
int dp[MAX], arr[MAX];

void solve() {
    memset(dp, -1, sizeof(dp));
    int N;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    dp[0] = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (dp[i] == -1) continue;
        for (int next = i + 1; next < N; ++next) {
            int power = (next - i) * (1 + abs(arr[i] - arr[next]));
            if (power > K) continue;
            if (dp[next] == -1) dp[next] = dp[i] + power;
            else dp[next] = min(dp[next], dp[i] + power);
        }
    }
    cout << (dp[N - 1] == -1 ? "NO" : "YES");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}