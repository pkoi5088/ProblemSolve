#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 101
#define endl '\n'

using namespace std;

vector<int> result, v;
int N, M, resultSum = 300001;

//size<=M이면 기준을 낮춰도된다. 아니면 높여야 한다.
bool check(int mid) {
    vector<int> tmp;
    int i = 0, high = -1;
    while (i < N) {
        int j = i + 1, S = v[i];
        while (j < N && S + v[j] <= mid) {
            S += v[j];
            j += 1;
        }
        tmp.push_back(j - i);
        high = max(high, S);
        i = j;
    }
    if (tmp.size() == M) {
        resultSum = min(resultSum, high);
        result = tmp;
    }
    return tmp.size() <= M;
}

void solve() {
    int low = MAX, high = 0;
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        low = min(low, v[i]);
        high += v[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << resultSum << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}