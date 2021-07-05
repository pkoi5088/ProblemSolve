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

bool f(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[n - i - 1] != s[i])
            return false;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[n - i - 1] != s[i]) {
            bool check = false;
            string tmp = s;
            tmp.erase(tmp.begin() + i);
            check |= f(tmp);
            tmp = s;
            tmp.erase(tmp.begin() + n - i - 1);
            check |= f(tmp);
            if (check)
                cout << 1 << endl;
            else
                cout << 2 << endl;
            return;
        }
    }
    cout << 0 << endl;
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