#include <iostream>
#include <cstring>
#define MAX_N 10001
#define endl '\n'

using namespace std;

void solve() {
    int N, A, B;
    int parent[MAX_N], check[MAX_N] = { 0, };
    memset(parent, -1, sizeof(parent));
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        cin >> A >> B;
        parent[B] = A;
    }
    cin >> A >> B;

    while (A != -1) {
        check[A] = 1;
        A = parent[A];
    }

    while (B != -1) {
        if (check[B]) {
            cout << B << endl;
            return;
        }
        B = parent[B];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}