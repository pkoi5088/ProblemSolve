#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#define MAX 100
#define endl '\n'

using namespace std;

string M[MAX];
bool visit[MAX][MAX];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int h, w;

void solve() {
	int key = 0;
	vector<pair<int, int>> wait[26];
	string tmp;

	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		cin >> M[i];
	}
	cin >> tmp;
	if (tmp != "0") {
		for (int i = 0; i < tmp.size(); ++i) {
			key |= (1 << (tmp[i] - 'a'));
		}
	}
	memset(visit, false, sizeof(visit));

	queue<pair<int, int>> q;
	char c;
	for (int i = 0; i < w; ++i) {
		c = M[0][i];
		if (c != '*' && visit[0][i] == false) {
			q.push({ 0,i });
			visit[0][i] = true;
		}
		c = M[h - 1][i];
		if (c != '*' && visit[h - 1][i] == false) {
			q.push({ h - 1,i });
			visit[h - 1][i] = true;
		}
	}
	for (int i = 0; i < h; ++i) {
		c = M[i][0];
		if (c != '*' && visit[i][0] == false) {
			q.push({ i,0 });
			visit[i][0] = true;
		}
		c = M[i][w - 1];
		if (c != '*' && visit[i][w - 1] == false) {
			q.push({ i,w - 1 });
			visit[i][w - 1] = true;
		}
	}
	
	int result = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		c = M[x][y];
		//문
		if ('A' <= c && c <= 'Z') {
			if (!(key & (1 << (c - 'A')))) {
				wait[c - 'A'].push_back({ x,y });
				continue;
			}
		}
		//열쇠
		else if ('a' <= c && c <= 'z') {
			key |= (1 << (c - 'a'));
			for (int i = 0; i < wait[c - 'a'].size(); ++i) {
				q.push({ wait[c - 'a'][i] });
			}
			wait[c - 'a'].clear();
		}
		//문서
		else if (c == '$') {
			result += 1;
		}

		//다음칸
		for (int l = 0; l < 4; ++l) {
			int nx = x + dx[l], ny = y + dy[l];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && M[nx][ny] != '*' && visit[nx][ny] == false) {
				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
	cout << result << endl;
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
