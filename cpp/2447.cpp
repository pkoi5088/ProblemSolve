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

vector<vector<bool>> star;

//x,y부터 length길이의 별을 찍어라
void dfs(int x, int y, int length) {
    if (length == 3) {
        for (int i = 0; i < 3; ++i) {
            star[x][y + i] = true;
            star[x + 2][y + i] = true;
        }
        star[x + 1][y] = star[x + 1][y + 2] = true;
    }
    else {
        for (int i = 0; i < 3; ++i) {
            dfs(x, y + length / 3 * i, length / 3);
            dfs(x + length / 3 * 2, y + length / 3 * i, length / 3);
        }
        dfs(x + length / 3, y, length / 3);
        dfs(x + length / 3, y + length / 3 * 2, length / 3);
    }
}

void solve() {
    int N;
    cin >> N;
    star.resize(N);
    for (int i = 0; i < N; ++i)
        star[i].resize(N);
    dfs(0, 0, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (star[i][j] ? '*' : ' ');
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}