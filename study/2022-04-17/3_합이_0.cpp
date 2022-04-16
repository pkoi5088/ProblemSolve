#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/3151
*/
int N;
vector<int> arr;

void solve() {
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    long long ret = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            int start, end;
            start = lower_bound(arr.begin() + j + 1, arr.end(), -(arr[i] + arr[j])) - arr.begin();
            end = upper_bound(arr.begin() + j + 1, arr.end(), -(arr[i] + arr[j])) - arr.begin();
            ret += end - start;
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