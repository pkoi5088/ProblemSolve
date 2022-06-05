#include <iostream>
#include <cstring>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/2615
*/

int arr[21][21] = { 0, };

bool check(int x, int y) {
    if (arr[x][y] == 0) return false;
    //왼쪽 위
    if (x >= 5 && y <= 15) {
        int target = arr[x][y];
        if (x + 1 < 20 && y - 1 >= 0 && arr[x + 1][y - 1] != target) {
            int cnt = 1, cx = x, cy = y;
            while (target == arr[cx - 1][cy + 1]) {
                cnt += 1;
                cx -= 1;
                cy += 1;
            }
            if (cnt == 5) return true;
        }
    }

    //오른쪽
    if (y <= 15) {
        int target = arr[x][y];
        if (y - 1 >= 0 && arr[x][y - 1] != target) {
            int cnt = 1, cx = x, cy = y;
            while (target == arr[cx][cy + 1]) {
                cnt += 1;
                cy += 1;
            }
            if (cnt == 5) return true;
        }
    }

    //오른쪽 아래
    if (x <= 15 && y <= 15) {
        int target = arr[x][y];
        if (x - 1 >=0 && y - 1 >=0 && arr[x - 1][y - 1] != target) {
            int cnt = 1, cx = x, cy = y;
            while (target == arr[cx + 1][cy + 1]) {
                cnt += 1;
                cx += 1;
                cy += 1;
            }
            if (cnt == 5) return true;
        }
    }
    
    //아래
    if (x <= 15) {
        int target = arr[x][y];
        if (x - 1 >=0 && arr[x - 1][y] != target) {
            int cnt = 1, cx = x, cy = y;
            while (target == arr[cx + 1][cy]) {
                cnt += 1;
                cx += 1;
            }
            if (cnt == 5) return true;
        }
    }
    return false;
}

void solve() {
    memset(arr, -1, sizeof(arr));
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j < 20; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j < 20; ++j) {
            if (check(i, j)) {
                cout << arr[i][j] << endl;
                cout << i << ' ' << j << endl;
                return;
            }
        }
    }
    cout << 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}