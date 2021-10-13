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
    int cnt = 0;
    while (true) {
        int result = 0;
        string s;
        cin >> s;
        if (s[0] == '-') break;
        cout << ++cnt << ". ";
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if (st.empty()) {
                    result += 1;
                    st.push('{');
                }
                else {
                    st.pop();
                }
            }
        }
        result += st.size() / 2;
        cout << result << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}