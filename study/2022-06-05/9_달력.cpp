#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/20207
*/

void solve() {
    vector<pair<int, int>> v;
    int cnt[366] = { 0, }, h = 0, w = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        for (int j = v[i].first; j <= v[i].second; ++j) {
            cnt[j] += 1;
        }
    }

    int ret = 0;
    for (int i = 1; i < 366; ++i) {
        if (cnt[i] > 0) {
            h = max(h, cnt[i]);
            w += 1;
        }
        if (cnt[i] == 0 || i == 365) {
            ret += h * w;
            h = w = 0;
        }
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