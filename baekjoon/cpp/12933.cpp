#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/12933
*/

vector<bool> check;
string s, target = "quack";

//-1 오류, 0+ 정상종료
int function() {
    int idx = 0, tIdx = 0, ret = 0;
    while (idx < s.size()) {
        while (idx < s.size() && (s[idx] != target[tIdx] || check[idx] == false)) {
            idx += 1;
        }
        if (idx < s.size()) {
            check[idx] = false;
            tIdx += 1;
        }
        if (tIdx >= target.size()) {
            ret += 1;
            tIdx = 0;
        }
    }
    if (tIdx != 0) return -1;
    return ret;
}

void solve() {
    cin >> s;
    check.resize(s.size(), true);
    int ret = 0, tmp;
    while ((tmp = function()) != -1) {
        if (tmp == 0) break;
        ret += 1;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (check[i] == true) tmp = -1;
    }
    if (tmp == -1 || ret == 0) cout << -1;
    else cout << ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}