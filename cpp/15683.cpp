#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;
/*
1. 입력 cctv위치 따로 저장
2. 5번 cctv에 대해서 #처리
3. 나머지 cctv에 대해서 dir처리
4. dir상태에 따른 감시 결과 함수 작성
5. dirUpdate
*/

int N, M;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
vector<pair<int, int>> cctvLoc, cctv5Loc;
vector<int> cctvDir;

//0 1 2 3, 북 서 남 동
void afterCCTV(vector<string>& board, int x, int y, int dir) {
	do {
		x += dx[dir], y += dy[dir];
		if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == '6') return;
		if (board[x][y] == '0') board[x][y] = '#';
	} while (true);
}

void simulation(vector<string>& board) {
	for (int i = 0; i < cctvLoc.size(); ++i) {
		int x = cctvLoc[i].first, y = cctvLoc[i].second;
		switch (cctvDir[i]) {
		case 0:
			if (board[x][y] == '1') {
				afterCCTV(board, x, y, 0);
			}
			else if (board[x][y] == '2') {
				afterCCTV(board, x, y, 0);
				afterCCTV(board, x, y, 2);
			}
			else if (board[x][y] == '3') {
				afterCCTV(board, x, y, 0);
				afterCCTV(board, x, y, 3);
			}
			else if (board[x][y] == '4') {
				afterCCTV(board, x, y, 0);
				afterCCTV(board, x, y, 1);
				afterCCTV(board, x, y, 3);
			}
			break;
		case 1:
			if (board[x][y] == '1') {
				afterCCTV(board, x, y, 1);
			}
			else if (board[x][y] == '2') {
				afterCCTV(board, x, y, 1);
				afterCCTV(board, x, y, 3);
			}
			else if (board[x][y] == '3') {
				afterCCTV(board, x, y, 1);
				afterCCTV(board, x, y, 0);
			}
			else if (board[x][y] == '4') {
				afterCCTV(board, x, y, 1);
				afterCCTV(board, x, y, 2);
				afterCCTV(board, x, y, 0);
			}
			break;
		case 2:
			if (board[x][y] == '1') {
				afterCCTV(board, x, y, 2);
			}
			else if (board[x][y] == '2') {
				afterCCTV(board, x, y, 2);
				afterCCTV(board, x, y, 0);
			}
			else if (board[x][y] == '3') {
				afterCCTV(board, x, y, 2);
				afterCCTV(board, x, y, 1);
			}
			else if (board[x][y] == '4') {
				afterCCTV(board, x, y, 2);
				afterCCTV(board, x, y, 3);
				afterCCTV(board, x, y, 1);
			}
			break;
		case 3:
			if (board[x][y] == '1') {
				afterCCTV(board, x, y, 3);
			}
			else if (board[x][y] == '2') {
				afterCCTV(board, x, y, 3);
				afterCCTV(board, x, y, 1);
			}
			else if (board[x][y] == '3') {
				afterCCTV(board, x, y, 3);
				afterCCTV(board, x, y, 2);
			}
			else if (board[x][y] == '4') {
				afterCCTV(board, x, y, 3);
				afterCCTV(board, x, y, 0);
				afterCCTV(board, x, y, 2);
			}
			break;
		}
	}
}

int count(vector<string>& board) {
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == '0') ret++;
		}
	}
	return ret;
}

int min(int a, int b) {
	return a < b ? a : b;
}

bool dirUpdate() {
	if (cctvDir.empty()) return true;
	int t = cctvDir.size();
	cctvDir[t - 1]++;
	for (int i = t - 1; i > 0; --i) {
		cctvDir[i - 1] += cctvDir[i] / 4;
		cctvDir[i] %= 4;
	}
	return cctvDir[0] >= 4;
}

void solve() {
	vector<string> map;
	cin >> N >> M;
	map.resize(N);
	for (int i = 0; i < N; ++i) {
		map[i].resize(M);
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] == '5') cctv5Loc.push_back({ i,j });
			else if (map[i][j] >= '1' && map[i][j] <= '4') cctvLoc.push_back({ i,j });
		}
	}
	
	//5번 cctv에 대한 처리
	for (int i = 0; i < cctv5Loc.size(); ++i) {
		int x = cctv5Loc[i].first, y = cctv5Loc[i].second;
		afterCCTV(map, x, y, 0);
		afterCCTV(map, x, y, 1);
		afterCCTV(map, x, y, 2);
		afterCCTV(map, x, y, 3);
	}

	//나머지 cctv에 대한 dir처리
	cctvDir.resize(cctvLoc.size(), 0);

	int result = count(map);
	do {
		vector<string> tmp = map;
		simulation(tmp);
		result = min(result, count(tmp));
	} while (!dirUpdate());
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
