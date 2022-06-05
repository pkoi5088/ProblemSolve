#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/15787
*/

bool check[(1 << 20)] = { false, };
int convert = (1 << 20);

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> v(N, 0);
    
    while (M--) {
        int c, i, x;
        cin >> c >> i;
        if (c == 1 || c == 2)
            cin >> x;

        if (c == 1) {
            v[i - 1] |= (1 << (x - 1));
        }
        else if (c == 2) {
            v[i - 1] &= ~(1 << (x - 1));
        }
        else if (c == 3) {
            v[i - 1] <<= 1;
            v[i - 1] &= ~convert;
        }
        else {
            v[i - 1] >>= 1;
        }
    }

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        if (check[v[i]] == false) {
            ret += 1;
            check[v[i]] = true;
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