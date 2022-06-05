#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/1244
*/

vector<int> v;
int N, M;

void solve() {
    cin >> N;
    v.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }
    cin >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            for (int i = b; i <= N; i += b) {
                v[i] += 1;
            }
        }
        else {
            v[b] += 1;
            int idx = b - 1;
            while (idx >= 1 && b + (b - idx) <= N) {
                if (v[idx] % 2 != v[2 * b - idx] % 2) break;
                v[idx] += 1;
                v[2 * b - idx] += 1;
                idx -= 1;
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << v[i] % 2 << ' ';
        if (i % 20 == 0) cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}