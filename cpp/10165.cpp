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

struct Train {
    int from, length, index;
};

vector<Train> v;
int N, M, startIdx = -1, startNum;

bool cmp(Train& t1, Train& t2) {
    int dist1, dist2;
    dist1 = (t1.from - startNum + N) % N;
    dist2 = (t2.from - startNum + N) % N;
    if (dist1 == dist2) {
        return  t1.length > t2.length;
    }
    else {
        return dist1 < dist2;
    }
}

void solve() {
    cin >> N >> M;
    v.resize(M);
    for (int i = 0; i < M; ++i) {
        Train tmp;
        int a, b, d;
        cin >> a >> b;
        d = (b - a + N) % N;
        tmp.from = a; tmp.length = d; tmp.index = i + 1;
        v[i] = tmp;
        if (startIdx == -1 || v[startIdx].length < d) {
            startIdx = i;
            startNum = v[startIdx].from;
        }
    }
    sort(v.begin(), v.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> result;
    int left = 0, right = 0;
    int idx = 0;
    while (idx < M) {
        int start = (v[idx].from - startNum + N) % N;
        int end = start + v[idx].length;
        if (end > right) {
            result.push(v[idx].index);
            right = end;
        }
        idx += 1;
    }

    while (!result.empty()) {
        cout << result.top() << ' ';
        result.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}