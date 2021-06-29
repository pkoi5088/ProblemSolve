#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 1000001
#define endl '\n'

using namespace std;

int arrow[MAX] = { 0, };

void solve() {
    int N, result = 0, x;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        ++arrow[x - 1];
        if (arrow[x]) {
            --arrow[x];
        }
        else {
            result += 1;
        }
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