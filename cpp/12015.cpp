#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
    vector<int> v;
    int N, x;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        if (v.empty() || v.back() < x) {
            v.push_back(x);
        }
        else {
            vector<int>::iterator iter = lower_bound(v.begin(), v.end(), x);
            *iter = x;
        }
    }

    cout << v.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}