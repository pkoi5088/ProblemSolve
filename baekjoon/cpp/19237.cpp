#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define MAX 20

using namespace std;

/*
	https://www.acmicpc.net/problem/19237
*/

int dx[5] = { 0,-1,1,0,0 }, dy[5] = { 0,0,0,-1,1 };
int N, M, k;
int arr[MAX][MAX];
//first: 상어의 현재방향, second: 상어의 선호방향
vector<pair<int,vector<vector<int>>>> sharkDir;
//first: 몇번상어가, second: 냄새몇번남았는지
pair<int, int> smell[MAX][MAX];

bool finish() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] > 1) return false;
		}
	}
	return true;
}

int confirmDir(int number, vector<int> v) {
	int nowDir = sharkDir[number].first;
	vector<int> priorityVector = sharkDir[number].second[nowDir];
	for (int i = 0; i < priorityVector.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			if (priorityVector[i] == v[j]) return v[j];
		}
	}
}

//number 상어가 [x,y]에서의 다음 방향을 반환
int getNextDir(int number, int x, int y) {
	vector<int> able;

	//냄새없는 칸 찾기
	for (int l = 1; l < 5; ++l) {
		int nx = x + dx[l], ny = y + dy[l];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (smell[nx][ny].second == 0) able.push_back(l);
	}
	//있으면 방향확정하기
	if (!able.empty()) {
		return confirmDir(number, able);
	}

	//자신의 냄새있는 칸 찾기
	for (int l = 1; l < 5; ++l) {
		int nx = x + dx[l], ny = y + dy[l];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (smell[nx][ny].first == number) able.push_back(l);
	}
	//있으면 방향확정하기
	if (!able.empty()) {
		return confirmDir(number, able);
	}

	//여기까지 오면 안됨
	return -1;
}

void sharkMove() {
	int tmp[MAX][MAX] = { 0, };
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] > 0) {
				int nextDir = getNextDir(arr[i][j], i, j);
				int nx = i + dx[nextDir], ny = j + dy[nextDir];
				if (tmp[nx][ny] == 0) tmp[nx][ny] = arr[i][j];
				else {
					tmp[nx][ny] = min(tmp[nx][ny], arr[i][j]);
				}
				sharkDir[arr[i][j]].first = nextDir;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			arr[i][j] = tmp[i][j];
		}
	}
}

void solve() {
	cin >> N >> M >> k;
	memset(smell, 0, sizeof(smell));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}
	sharkDir.resize(M + 1);
	for (int i = 0; i < M; ++i) {
		cin >> sharkDir[i + 1].first;
	}
	for (int i = 0; i < M; ++i) {
		sharkDir[i + 1].second.resize(5);
		for (int j = 1; j < 5; ++j) {
			sharkDir[i + 1].second[j].resize(4);
			for (int l = 0; l < 4; ++l) {
				cin >> sharkDir[i + 1].second[j][l];
			}
		}
	}

	//최초 냄새 뿌리기
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] > 0) {
				smell[i][j] = { arr[i][j],k };
			}
		}
	}

	int ret = 0;
	while (ret <= 1000) {
		if (finish()) break;

		//상어이동
		sharkMove();

		//냄새감소
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (smell[i][j].second > 0) {
					smell[i][j].second -= 1;
					if (smell[i][j].second == 0)
						smell[i][j] = { 0,0 };
				}
			}
		}

		//냄새 뿌리기
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (arr[i][j] > 0) {
					smell[i][j] = { arr[i][j],k };
				}
			}
		}

		ret += 1;
	}
	if (ret > 1000) cout << -1;
	else cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}