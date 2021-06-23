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

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};

int dayOfMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> flower;
    int N, result = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b, c, d, start = 0, end = 0;
        cin >> a >> b >> c >> d;
        for (int i = 1; i < a; ++i)
            start += dayOfMonth[i];
        start += b - 1;
        for (int i = 1; i < c; ++i)
            end += dayOfMonth[i];
        end += d - 1;
        flower.push({ start,end });
    }

    //now-1까지는 꽃이 핌, goal은 12월 1일 즉, 11월 30일까지는 꽃이핌을 확신
    int now = 31 + 28, goal = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
    int i = 0;

    while (!flower.empty() && now < goal) {
        if (flower.top().second <= now || flower.top().first > now) {
            flower.pop();
        }
        else {
            int rest = -1;
            while (!flower.empty() && flower.top().first <= now) {
                rest = max(rest, flower.top().second);
                flower.pop();
            }
            now = rest;
            result += 1;
        }
    }

    if (now >= goal)
        cout << result;
    else
        cout << 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    solve();
    return 0;
}