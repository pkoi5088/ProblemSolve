#include <iostream>
#include <cstring>
#define MAX_P 350
#define MAX_D 100001
#define endl '\n'

using namespace std;

//arr.first: 길이, arr.second: 용량
int dp[MAX_D];
pair<int, int> arr[MAX_P];
int D, P;

void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> D >> P;
    for (int i = 0; i < P; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    dp[0] = (1 << 30);

    for (int i = 1; i < P; ++i) {
        for (int j = D; j >= 0; --j) {
            if (j - arr[i].first >= 0)
                dp[j] = max(dp[j], min(dp[j - arr[i].first],arr[i].second));
        }
    }
    cout << dp[D];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}