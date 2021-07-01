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
    string result = "";
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        if (result.empty() || result[0] < c) {
            result += c;
        }
        else {
            result = c + result;
        }
    }
    cout << result << endl;
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