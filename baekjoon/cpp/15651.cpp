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

vector<int> result;
int N, M;

void permutation() {
    if (result.size() == M) {
        for (int i = 0; i < M; ++i) {
            cout << result[i] << ' ';
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < N; ++i) {
            result.push_back(i + 1);
            permutation();
            result.pop_back();
        }
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        result.push_back(i + 1);
        permutation();
        result.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}