#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/2578
*/

void solve() {
    pair<int, int> loc[26];
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int tmp;
            cin >> tmp;
            loc[tmp] = { i,j };
        }
    }

    vector<int> arr(25);
    vector<vector<bool>> check(5, vector<bool>(5, true));
    for (int i = 0; i < 25; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < 25; ++i) {
        int x = loc[arr[i]].first, y = loc[arr[i]].second;
        check[x][y] = false;

        //가로
        int cnt = 0;
        for (int k = 0; k < 5; ++k) {
            int flag;
            for (flag = 0; flag < 5; ++flag) {
                if (check[k][flag] == true) break;
            }
            if (flag == 5) {
                cnt += 1;
            }
        }

        //세로
        for (int k = 0; k < 5; ++k) {
            int flag;
            for (flag = 0; flag < 5; ++flag) {
                if (check[flag][k] == true) break;
            }
            if (flag == 5) {
                cnt += 1;
            }
        }

        //대각
        int k;
        for (k = 0; k < 5; ++k) {
            if (check[k][k] == true) break;
        }
        if (k == 5) cnt += 1;
        k = 0;
        for (k = 0; k < 5; ++k) {
            if (check[4-k][k] == true) break;
        }
        if (k == 5) cnt += 1;

        //빙고체크
        if (cnt >= 3) {
            cout << i + 1;
            break;
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