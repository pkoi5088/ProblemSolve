#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int N, M, H, result = -1;

int min(int a, int b) {
	if (a == -1) return b;
	return a < b ? a : b;
}

bool isAble(vector<vector<bool>>& map, int a, int b) {
	if (map[a][b]) return false;
	if (a > 0 && map[a - 1][b]) return false;
	if (a < N - 1 && map[a+1][b]) return false;
	return true;
}

bool isGood(vector<vector<bool>>& map) {
	for (int line = 0; line < N; ++line) {
		int now = line;
		for (int j = 0; j < H; ++j) {
			if (now > 0 && map[now - 1][j]) now--;
			else if (now < N - 1 && map[now][j]) now++;
		}
		if (now != line) return false;
	}
	return true;
}

void pick(vector<vector<bool>>& map, vector<pair<int, int>>& able, int n, int depth) {
    if (result!=-1&&depth>=result)
        return;
	if (isGood(map))
		result = min(result, depth);
	if (n < able.size()) {
		int x = able[n].first, y = able[n].second;
		if (isAble(map, x, y)) {
			map[x][y] = true;
			if (depth < 3)
				pick(map, able, n + 1, depth + 1);
			map[x][y] = false;
		}
		if (depth < 3)
			pick(map, able, n + 1, depth);
	}
}

void solve() {
	cin >> N >> M >> H;
	vector<vector<bool>> map;
	vector<pair<int, int>> able;
	map.resize(N);
	for (int i = 0; i < N; ++i)
		map[i].resize(H, false);
	while (M--) {
		int a, b;
		cin >> a >> b;
		map[b - 1][a - 1] = true;
	}

	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < H; ++j) {
			if (isAble(map, i, j))
				able.push_back({ i,j });
		}
	}
	pick(map, able, 0, 0);
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
