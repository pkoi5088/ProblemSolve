#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/10994
*/

vector<vector<bool>> arr;

void function(int x, int y, int n) {
    if (n < 1) return;
    int nx = x + 4 * n - 3, ny = y + 4 * n - 3;
    for (int i = y; i < ny; ++i)
        arr[x][i] = true;
    for (int i = y; i < ny; ++i)
        arr[nx - 1][i] = true;
    for (int i = x; i < nx; ++i)
        arr[i][y] = true;
    for (int i = x; i < nx; ++i)
        arr[i][ny - 1] = true;

    function(x + 2, y + 2, n - 1);
}

void solve() {
    int N;
    cin >> N;
    arr.resize(4 * N - 3, vector<bool>(4 * N - 3, false));

    function(0, 0, N);
    for (int i = 0; i < 4 * N - 3; ++i) {
        for (int j = 0; j < 4 * N - 3; ++j) {
            if (arr[i][j]) cout << '*';
            else cout << ' ';
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