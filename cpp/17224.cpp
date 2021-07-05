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

void solve() {
    vector<pair<int, int>> board;
    int N, L, K, result = 0;
    cin >> N >> L >> K;
    board.resize(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        board[i] = { b,a };
    }
    sort(board.begin(), board.end());

    int i = 0;
    while (i < N && K) {
        if (board[i].first <= L) {
            K -= 1;
            result += 140;
        }
        else if (board[i].second <= L) {
            K -= 1;
            result += 100;
        }
        i += 1;
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