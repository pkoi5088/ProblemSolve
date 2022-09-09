#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/20061
*/

bool greenArr[6][4], blueArr[4][6];
int ret = 0;

//green에 1x1 사이즈를 놓는다.
void greenOneSize(int x, int y) {
	x = 0;
	while (x < 6 && greenArr[x][y] == false) {
		x += 1;
	}
	greenArr[x - 1][y] = true;
}

//blue에 1x1 사이즈를 놓는다.
void blueOneSize(int x, int y) {
	y = 0;
	while (y < 6 && blueArr[x][y] == false) {
		y += 1;
	}
	blueArr[x][y - 1] = true;
}

//green에 1x2 사이즈를 놓는다.
void greenTwoSize(int x, int y) {
	x = 0;
	while (x < 6 && greenArr[x][y] == false && greenArr[x][y + 1] == false) {
		x += 1;
	}
	greenArr[x - 1][y] = true;
	greenArr[x - 1][y + 1] = true;
}

//blue에 2x1 사이즈를 놓는다.
void blueTwoSize(int x, int y) {
	y = 0;
	while (y < 6 && blueArr[x][y] == false && blueArr[x+1][y] == false) {
		y += 1;
	}
	blueArr[x][y - 1] = true;
	blueArr[x + 1][y - 1] = true;
}

void calculate() {
	//green
	for (int i = 2; i < 6; ++i) {
		bool flag = false;
		for (int j = 0; j < 4; ++j) {
			if (greenArr[i][j] == false) flag = true;
		}
		if (!flag) {
			for (int j = 0; j < 4; ++j) {
				greenArr[i][j] = false;
			}
			ret += 1;
		}
	}

	//blue
	for (int i = 2; i < 6; ++i) {
		bool flag = false;
		for (int j = 0; j < 4; ++j) {
			if (blueArr[j][i] == false) flag = true;
		}
		if (!flag) {
			for (int j = 0; j < 4; ++j) {
				blueArr[j][i] = false;
			}
			ret += 1;
		}
	}
}

void correction() {
	int idx = 5;
	vector<int> v;
	//green
	for (int i = 0; i < 6; ++i) {
		bool flag = false;
		for (int j = 0; j < 4; ++j) {
			if (greenArr[i][j]) flag = true;
		}
		if (flag) {
			v.push_back(i);
		}
	}
	while (!v.empty()) {
		int nidx = v.back();
		for (int i = 0; i < 4; ++i) {
			greenArr[idx][i] = greenArr[nidx][i];
		}
		idx -= 1;
		v.pop_back();
	}
	while (idx >= 0) {
		for (int i = 0; i < 4; ++i) {
			greenArr[idx][i] = false;
		}
		idx -= 1;
	}

	idx = 5;
	//blue
	for (int i = 0; i < 6; ++i) {
		bool flag = false;
		for (int j = 0; j < 4; ++j) {
			if (blueArr[j][i]) flag = true;
		}
		if (flag) {
			v.push_back(i);
		}
	}
	while (!v.empty()) {
		int nidx = v.back();
		for (int i = 0; i < 4; ++i) {
			blueArr[i][idx] = blueArr[i][nidx];
		}
		idx -= 1;
		v.pop_back();
	}
	while (idx >= 0) {
		for (int i = 0; i < 4; ++i) {
			blueArr[i][idx] = false;
		}
		idx -= 1;
	}

	//green
	int cnt = 0;
	for (int i = 0; i < 2; ++i) {
		bool flag = false;
		for (int j = 0; j < 4; ++j) {
			if (greenArr[i][j]) flag = true;
		}
		if (flag) cnt += 1;
	}
	while (cnt != 0) {
		for (int i = 5; i > 0; --i) {
			for (int j = 0; j < 4; ++j) {
				greenArr[i][j] = greenArr[i - 1][j];
			}
		}
		for (int j = 0; j < 4; ++j) {
			greenArr[0][j] = false;
		}
		cnt -= 1;
	}

	//blue
	cnt = 0;
	for (int i = 0; i < 2; ++i) {
		bool flag = false;
		for (int j = 0; j < 4; ++j) {
			if (blueArr[j][i]) flag = true;
		}
		if (flag) cnt += 1;
	}
	while (cnt != 0) {
		for (int i = 5; i > 0; --i) {
			for (int j = 0; j < 4; ++j) {
				blueArr[j][i] = blueArr[j][i - 1];
			}
		}
		for (int j = 0; j < 4; ++j) {
			blueArr[j][0] = false;
		}
		cnt -= 1;
	}
}

void solve() {
	int N;
	cin >> N;
	while (N--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			greenOneSize(x, y);
			blueOneSize(x, y);
		}
		else if (t == 2) {
			greenTwoSize(x, y);
			blueOneSize(x, y);
			blueOneSize(x, y);
		}
		else {
			greenOneSize(x, y);
			greenOneSize(x, y);
			blueTwoSize(x, y);
		}

		//점수계산
		calculate();

		//당기고 삭제하기
		correction();
	}

	int cnt = 0;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (greenArr[i][j]) cnt += 1;
			if (blueArr[j][i]) cnt += 1;
		}
	}

	cout << ret << endl << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}