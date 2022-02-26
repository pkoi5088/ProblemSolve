#include <iostream>
#include <string>
#include <map>
#include <cstring>
#define MAX 1000
#define endl '\n'

using namespace std;

map<string, int> table;
string S;
int M, dp[MAX];

int getDP(int s) {
    if (s >= S.size()) return 0;
    int& ret = dp[s];
    if (ret != -1) return ret;

    string subStr;
    ret = 0;
    //s부터e까지 구간 탐색
    for (int i = s; i < S.size(); ++i) {
        subStr = S.substr(s, i - s + 1);
        if (table.find(subStr) != table.end()) {
            ret = max(ret, getDP(s + subStr.size()) + table[subStr]);
        }
        ret = max(ret, getDP(i + 1) + i - s + 1);
    }
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> S >> M;
    for (int i = 0; i < M; ++i) {
        string s;
        int t;
        cin >> s >> t;
        table[s] = t;
    }
    cout << getDP(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}