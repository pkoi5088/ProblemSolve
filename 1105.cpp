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
    int result = 0;
    string L, R;
    cin >> L >> R;
    if (L.size() != R.size()) {
        cout << 0;
        return;
    }
    for (int i = 0; i < R.size(); ++i) {
        if (L[i] == R[i] && L[i] == '8') {
            result += 1;
        }
        else if (L[i] != R[i]) {
            break;
        }
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