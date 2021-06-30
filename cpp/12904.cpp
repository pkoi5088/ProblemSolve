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
    string a, b;
    cin >> a >> b;
    while (a.size() < b.size()) {
        if (b.back() == 'A') {
            b.pop_back();
        }
        else if (b.back() == 'B') {
            b.pop_back();
            reverse(b.begin(), b.end());
        }
        else {
            break;
        }
    }
    cout << (a == b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}