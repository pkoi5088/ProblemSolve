#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 68
#define endl '\n'

using namespace std;

vector<long long int> koong;

long long int getKoong(int n) {
    if (koong[n] != -1)
        return koong[n];
    else
        return koong[n] = getKoong(n - 1) + getKoong(n - 2) + getKoong(n - 3) + getKoong(n - 4);
}

void solve() {
    int N;
    cin >> N;
    koong.resize(MAX, -1);
    koong[0] = koong[1] = 1;
    koong[2] = 2;
    koong[3] = 4;
    cout << getKoong(N) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}