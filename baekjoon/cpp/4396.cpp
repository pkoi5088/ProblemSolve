#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/4396
*/

int dx[8] = { -1,-1,-1,0,0,1,1,1 }, dy[8] = { -1,0,1,-1,1,-1,0,1 };

void solve() {
    vector<string> v, v2;
    vector<vector<int>> cnt;
    int N, flag = 0;
    cin >> N;
    v.resize(N);
    v2.resize(N);
    cnt.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    for (int i = 0; i < N; ++i)
        cin >> v2[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (v[i][j] == '*') {
                for (int k = 0; k < 8; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        continue;
                    cnt[nx][ny] += 1;
                }
            }

            //밟았는지 체크
            if (v[i][j] == '*' && v2[i][j] == 'x')
                flag = 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (flag && v[i][j] == '*') {
                cout << '*';
            }
            else if (v2[i][j] == 'x') {
                cout << cnt[i][j];
            }
            else {
                cout << '.';
            }
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