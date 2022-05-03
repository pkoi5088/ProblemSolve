#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/21611
*/

vector<vector<int>> arr;
vector<pair<int, int>> route;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int N, M;

void print() {

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void init() {
    int x = 0, y = 0, dir = 1;
    while (x != N / 2 || y != N / 2) {
        //넣고
        route.push_back({ x,y });
        arr[x][y] = 1;

        int nx = x + dx[dir], ny = y + dy[dir];
        //위치이동
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir], ny = y + dy[dir];
        }
        x = nx, y = ny;
        //방향이동
    }
    reverse(route.begin(), route.end());
}

void pulling() {
    vector<vector<int>> tmp(N, vector<int>(N, 0));
    vector<int> v;
    for (int i = 0; i < route.size(); ++i) {
        int x = route[i].first, y = route[i].second;
        if (arr[x][y] != 0) {
            v.push_back(arr[x][y]);
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        int x = route[i].first, y = route[i].second;
        tmp[x][y] = v[i];
    }
    arr = tmp;
}

void explosion(int& ret) {
    //stack용 vector first: 숫자, second: 개수
    vector<vector<int>> tmp(N, vector<int>(N, 0));
    vector<pair<int, int>> v;
    for (int i = 0; i < route.size(); ++i) {
        int x = route[i].first, y = route[i].second;
        if (arr[x][y] != 0) {
            if (v.empty()) {
                v.push_back({ arr[x][y],1 });
            }
            //스택 카운트 증가
            else if (v.back().first == arr[x][y]) {
                int idx = v.size() - 1;
                v[idx].second += 1;
            }
            //폭발 연산
            else if (v.back().first != arr[x][y]) {
                //폭발
                if (v.back().second >= 4) {
                    ret += v.back().first * v.back().second;
                    v.pop_back();
                }

                if (!v.empty() && v.back().first == arr[x][y]) {
                    int idx = v.size() - 1;
                    v[idx].second += 1;
                }
                else {
                    v.push_back({ arr[x][y],1 });
                }
            }
        }
    }
    if (!v.empty() && v.back().second >= 4) {
        ret += v.back().first * v.back().second;
        v.pop_back();
    }

    for (int i = 0, idx = 0; i < v.size() && idx < route.size(); ++i,idx+=2) {
        int x = route[idx].first, y = route[idx].second;
        int nx = route[idx + 1].first, ny = route[idx + 1].second;
        tmp[x][y] = v[i].second;
        tmp[nx][ny] = v[i].first;
    }
    arr = tmp;
}

void solve() {
    int ret = 0;
    cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; ++i) {
        arr[i].resize(N, 0);
    }
    init();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];

    while (M--) {
        int dir, s;
        cin >> dir >> s;
        if (dir == 1) dir = 0;
        else if (dir == 4) dir = 1;

        //블리자드
        for (int i = 1; i <= s; ++i) {
            int nx = N / 2 + dx[dir] * i, ny = N / 2 + dy[dir] * i;
            arr[nx][ny] = 0;
        }

        print();
        //폭발 후 당기기
        explosion(ret);
        //pulling();
        print();
    }
    cout << ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    solve();
    return 0;
}