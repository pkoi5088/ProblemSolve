#include <iostream>
#include <string>
#include <map>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/20436
*/

map<char, pair<int, int>> table;

void init() {
    table['q'] = { 0,0 };
    table['w'] = { 0,1 };
    table['e'] = { 0,2 };
    table['r'] = { 0,3 };
    table['t'] = { 0,4 };
    table['y'] = { 0,5 };
    table['u'] = { 0,6 };
    table['i'] = { 0,7 };
    table['o'] = { 0,8 };
    table['p'] = { 0,9 };
    table['a'] = { 1,0 };
    table['s'] = { 1,1 };
    table['d'] = { 1,2 };
    table['f'] = { 1,3 };
    table['g'] = { 1,4 };
    table['h'] = { 1,5 };
    table['j'] = { 1,6 };
    table['k'] = { 1,7 };
    table['l'] = { 1,8 };
    table['z'] = { 2,0 };
    table['x'] = { 2,1 };
    table['c'] = { 2,2 };
    table['v'] = { 2,3 };
    table['b'] = { 2,4 };
    table['n'] = { 2,5 };
    table['m'] = { 2,6 };
}

bool isConsonant(char c) {
    switch (c) {
    case 'q':
    case 'w':
    case 'e':
    case 'r':
    case 't':
    case 'a':
    case 's':
    case 'd':
    case 'f':
    case 'g':
    case 'z':
    case 'x':
    case 'c':
    case 'v':
        return true;

    default:
        return false;
    }
}

int getDist(pair<int, int> a, pair<int, int> b) {
    int ret = 0;
    ret += abs(b.first - a.first);
    ret += abs(b.second - a.second);
    return ret;
}

void solve() {
    init();
    pair<int, int> left, right;
    char tmp;
    cin >> tmp;
    left = table[tmp];
    cin >> tmp;
    right = table[tmp];
    string s;
    cin >> s;

    int ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (isConsonant(s[i])) {
            ret += getDist(left, table[s[i]]) + 1;
            left = table[s[i]];
        }
        else {
            ret += getDist(right, table[s[i]]) + 1;
            right = table[s[i]];
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