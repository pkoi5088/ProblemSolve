#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
    https://www.acmicpc.net/problem/14719
*/

void solve() {
    int H, W;
    cin >> H >> W;
    vector<int> left(W), right(W), arr(W);
    for (int i = 0; i < W; ++i)
        cin >> arr[i];

    left[0] = arr[0];
    for (int i = 1; i < W; ++i)
        left[i] = max(left[i - 1], arr[i]);
    right[W - 1] = arr[W - 1];
    for (int i = W - 2; i >= 0; --i)
        right[i] = max(right[i + 1], arr[i]);

    int ret = 0;
    for (int i = 0; i < W; ++i) {
        int lMax = 0, rMax = 0;
        if (i != 0) {
            lMax = left[i - 1];
        }
        if (i != W - 1) {
            rMax = right[i + 1];
        }
        ret += (min(lMax, rMax) - arr[i]) < 0 ? 0 : (min(lMax, rMax) - arr[i]);
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