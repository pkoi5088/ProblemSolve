#include <iostream>
#include <string>
#include <vector>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/16918
*/

int dx[5] = { -1,1,0,0,0 }, dy[5] = { 0,0,-1,1,0 };

vector<string> function(vector<string> arr, int R, int C) {
    vector<string> ret;
    vector<vector<int>> v(R, vector<int>(C, 0));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (arr[i][j] == 'O') {
                for (int k = 0; k < 5; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                    v[nx][ny] -= 1;
                }
            }
        }
    }

    for (int i = 0; i < R; ++i) {
        string tmp;
        for (int j = 0; j < C; ++j) {
            if (v[i][j]<0) {
                tmp += '.';
            }
            else {
                tmp += 'O';
            }
        }
        ret.push_back(tmp);
    }
    return ret;
}

void solve() {
    int R, C, N;
    cin >> R >> C >> N;

    vector<string> arr(R);
    for (int i = 0; i < R; ++i) {
        cin >> arr[i];
    }
    if (N % 2 == 0) {
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cout << 'O';
            }
            cout << endl;
        }
    }
    else {
        N -= 2;
        while (N >= 1) {
            arr = function(arr, R, C);
            N -= 2;
        }

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}