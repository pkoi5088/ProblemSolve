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
    int N, result = 0;
    cin >> N;
    vector<pair<int, int>> v;
    v.resize(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        v[i] = { a,b };
    }
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; ++i) {
        if (pq.empty() || pq.size() < v[i].first) {
            pq.push(v[i].second);
        }
        else if (pq.top() < v[i].second) {
            pq.pop();
            pq.push(v[i].second);
        }
    }

    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}