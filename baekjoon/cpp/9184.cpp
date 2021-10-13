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

int dp[101][101][101] = { 0 };

int w(int a, int b, int c) {
    if (dp[a + 50][b + 50][c + 50] != -1) {
        return dp[a + 50][b + 50][c + 50];
    }
    else {
        if (a <= 0 || b <= 0 || c <= 0) {
            return dp[a + 50][b + 50][c + 50] = 1;
        }
        else if (a > 20 || b > 20 || c > 20) {
            return dp[a + 50][b + 50][c + 50] = w(20, 20, 20);
        }
        else if (a < b && b < c) {
            return dp[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        }
        else {
            return dp[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        }
    }
}

void solve() {
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            for (int k = 0; k < 101; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            return;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}