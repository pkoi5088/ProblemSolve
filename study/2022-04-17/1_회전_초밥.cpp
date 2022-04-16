#include <iostream>
#define MAX_ARR 3000000
#define MAX_CNT 3001
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/15961
*/

int arr[MAX_ARR], cnt[MAX_CNT] = { 0, };

int getRange(int l, int r, int N) {
    if (l <= r) {
        return r - l + 1;
    }
    else {
        return r + 1 + N - l;
    }
}

void solve() {
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int ret = 1, nowCnt = 1;
    int left = 0, right = 0;
    cnt[arr[0]] = 1;

    while (left < N) {
        if (getRange(left, right, N) >= k) {
            cnt[arr[left]] -= 1;
            if (cnt[arr[left]] == 0) {
                nowCnt -= 1;
            }
            left += 1;
        }
        else {
            right = (right + 1) % N;
            cnt[arr[right]] += 1;
            if (cnt[arr[right]] == 1) {
                nowCnt += 1;
            }
        }
        ret = max(ret, nowCnt + (cnt[c] == 0 ? 1 : 0));
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