#include <iostream>
#include <algorithm>
#define MAX 100
#define endl "\n"

using namespace std;

int map[MAX][MAX];
int N, L;

bool ifRow(int n) {
	//경사로를 놓았는가
	int tmp[MAX] = { 0 };
	for (int i = 1; i < N; ++i) {
		int diff = map[n][i] - map[n][i - 1];
		if (diff > 1 || diff < -1) return false;
		//왼쪽(i-1)이 더 낮음
		else if (diff == 1) {
			//길이가 안되거나
			if (i <= L - 1) return false;
			//이미 경사로가 설치 되었거나
			for (int j = 1; j <= L; ++j) {
				if (tmp[i - j] == 1) return false;
			}
			//높이가 다르면 FALSE
			for (int j = 1; j < L; ++j) {
				if (map[n][i - j] != map[n][i - j - 1]) return false;
			}
			for (int j = 1; j <= L; ++j) {
				tmp[i - j] = 1;
			}
		}
		//오른쪽(i)이 더 낮음
		else if (diff == -1) {
			//길이가 안되거나 높이가 서로 다르다면
			if (i >= N - L + 1) return false;
			for (int j = 1; j < L; ++j) {
				if (map[n][i] != map[n][i + j]) return false;
			}
			for (int j = 0; j < L; ++j) {
				tmp[i + j] = 1;
			}
		}
	}
	return true;
}

bool ifCol(int n) {
	//경사로를 놓았는가
	int tmp[MAX] = { 0 };
	for (int i = 1; i < N; ++i) {
		int diff = map[i][n] - map[i - 1][n];
		if (diff > 1 || diff < -1) return false;
		//왼쪽(i-1)이 더 낮음
		else if (diff == 1) {
			//길이가 안되거나
			if (i <= L - 1) return false;
			//이미 경사로가 설치 되었거나
			for (int j = 1; j <= L; ++j) {
				if (tmp[i - j] == 1) return false;
			}
			//높이가 다르면 FALSE
			for (int j = 1; j < L; ++j) {
				if (map[i - j][n] != map[i - j - 1][n]) return false;
			}
			for (int j = 1; j <= L; ++j) {
				tmp[i - j] = 1;
			}
		}
		//오른쪽(i)이 더 낮음
		else if (diff == -1) {
			//길이가 안되거나 높이가 서로 다르다면
			if (i >= N - L + 1) return false;
			for (int j = 1; j < L; ++j) {
				if (map[i][n] != map[i + j][n]) return false;
			}
			for (int j = 0; j < L; ++j) {
				tmp[i + j] = 1;
			}
		}
	}
	return true;
}

void solve() {
	int result = 0;
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		if (ifRow(i)) {
			//cout << "Row " << i << endl;
			result += 1;
		}
		if (ifCol(i)) {
			//cout << "Col " << i << endl;
			result += 1;
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}