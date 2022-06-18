#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
    https://www.acmicpc.net/problem/16719
*/

string s;
vector<pair<int, char>>tmp;

void printTmp() {
    sort(tmp.begin(), tmp.end());
    string ret;
    for (int i = 0; i < tmp.size(); ++i) {
        ret += tmp[i].second;
    }
    cout << ret << endl;
}

void dfs(int start, int end) {
    if (start > end) return;
    //인덱스 탐색
    int idx = start;
    for (int i = start; i <= end; ++i) {
        if (s[idx] > s[i]) idx = i;
    }

    //tmp에 넣고 출력
    tmp.push_back({ idx,s[idx] });
    printTmp();

    //추가 탐색
    dfs(idx + 1, end);
    dfs(start, idx - 1);
}

void solve() {
    cin >> s;
    dfs(0, s.size() - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}