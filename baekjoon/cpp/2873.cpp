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

int R, C;
vector<vector<int>> v;

void solve() {
    cin >> R >> C;
    v.resize(R);
    for (int i = 0; i < R; ++i)
        v[i].resize(C);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> v[i][j];
        }
    }

    string result = "";
    if (R % 2) {
        string s = "";
        for (int i = 0; i < C - 1; ++i)
            s += 'R';
        s += 'D';
        for (int i = 0; i < C - 1; ++i)
            s += 'L';
        s += 'D';
        for (int i = R; i > 1; i -= 2)
            result += s;
        for (int i = 0; i < C - 1; ++i)
            result += 'R';
    }
    else if (C % 2) {
        string s = "";
        for (int i = 0; i < R - 1; ++i)
            s += 'D';
        s += 'R';
        for (int i = 0; i < R - 1; ++i)
            s += 'U';
        s += 'R';
        for (int i = C; i > 1; i -= 2)
            result += s;
        for (int i = 0; i < R - 1; ++i)
            result += 'D';
    }
    else {
        int tX = 0, tY = 1;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if ((i + j) % 2 && v[i][j] < v[tX][tY]) {
                    tX = i; tY = j;
                }
            }
        }

        string pre = "", post = "";
        while (R - tX > 2) {
            post += 'D';
            for (int i = 0; i < C - 1; ++i)
                post += 'L';
            post += 'D';
            for (int i = 0; i < C - 1; ++i)
                post += 'R';
            R -= 2;
        }
        while (tX >= 2) {
            for (int i = 0; i < C - 1; ++i)
                pre += 'R';
            pre += 'D';
            for (int i = 0; i < C - 1; ++i)
                pre += 'L';
            pre += 'D';
            tX -= 2;
        }

        for (int i = 0; i < tY / 2; ++i)
            pre += "DRUR";
        if (tY % 2) {
            pre += "DR";
        }
        else {
            pre += "RD";
        }

        for (int i = 0; i < (C - 1 - tY) / 2; ++i)
            pre += "RURD";
        result = pre + post;
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