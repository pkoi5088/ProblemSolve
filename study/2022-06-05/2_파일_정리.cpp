#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/20291
*/

string getExtension(string s, char del) {
    string ret;
    bool flag = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == del) flag = true;
        else if (flag) {
            ret.push_back(s[i]);
        }
    }
    return ret;
}

bool cmp(pair<string, int> p1, pair<string, int>p2) {
    return p1.first < p2.first;
}

void solve() {
    map<string, int> table;
    vector<pair<string, int>> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int idx = -1;
        string s,extension;
        cin >> s;
        extension = getExtension(s, '.');
        if (table[extension] == 0) {
            v.push_back({ extension,0 });
            table[extension] = v.size();
        }
        idx = table[extension] - 1;
        v[idx].second += 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << ' ' << v[i].second << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}