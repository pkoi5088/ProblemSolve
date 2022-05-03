#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/21608
*/

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

bool check(vector<int> v, int n) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == n) return true;
    }
    return false;
}

void solve() {
    int N;
    vector<vector<int>> seat, like;
    cin >> N;
    seat.resize(N);
    like.resize(N * N, vector<int>(4));
    for (int i = 0; i < N; ++i) {
        seat[i].resize(N, 0);
    }

    for (int i = 0; i < N * N; ++i) {
        int num, curX = -1, curY, curLike = 0, curEmpty = 0;
        cin >> num;
        cin >> like[num - 1][0] >> like[num - 1][1] >> like[num - 1][2] >> like[num - 1][3];
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (seat[x][y] != 0) continue;
                int nLike = 0, nEmpty = 0;
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                    if (seat[nx][ny] == 0) nEmpty += 1;
                    else if (check(like[num - 1], seat[nx][ny])) nLike += 1;
                }

                if (curLike < nLike) {
                    curX = x, curY = y, curLike = nLike, curEmpty = nEmpty;
                }
                else if (curLike == nLike && curEmpty < nEmpty) {
                    curX = x, curY = y, curLike = nLike, curEmpty = nEmpty;
                }
                else if (curLike == nLike && curEmpty == nEmpty && curX == -1) {
                    curX = x, curY = y, curLike = nLike, curEmpty = nEmpty;
                }
            }
        }
        seat[curX][curY] = num;
    }

    int ret = 0;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            int num=seat[x][y],cnt = 0;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (check(like[num - 1], seat[nx][ny])) cnt += 1;
            }

            if (cnt) {
                ret += pow(10, cnt - 1);
            }

        }
    }
    cout << ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}