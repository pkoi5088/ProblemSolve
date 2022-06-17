#include <iostream>
#include <vector>

using namespace std;

/*
    https://www.acmicpc.net/problem/22856
*/

int N;
vector<pair<int, int>> child;

void solve() {
    cin >> N;
    child.resize(N);
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        child[a - 1].first = (b == -1 ? b : b - 1);
        child[a - 1].second = (c == -1 ? c : c - 1);
    }

    int count = 0, now = 0;
    while (child[now].second != -1) {
        now = child[now].second;
        count += 1;
    }
    cout << 2 * (N - 1) - count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}