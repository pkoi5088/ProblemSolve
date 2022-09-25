#include <iostream>
#define endl '\n'
#define MAX 200

using namespace std;

/*
	https://www.acmicpc.net/problem/20055
*/

//first: 내구도, second: 로봇번호
pair<int, int> arr[MAX];
int N, K;

bool finish() {
	int cnt = 0;
	for (int i = 0; i < 2 * N; ++i) {
		if (arr[i].first <= 0) cnt += 1;
		if (cnt >= K) return true;
	}
	return false;
}

void rotate() {
	pair<int, int> tmp = arr[2 * N - 1];
	for (int i = 2 * N - 1; i > 0; --i) {
		arr[i] = arr[i - 1];
	}
	arr[0] = tmp;
}

void solve() {
	cin >> N >> K;
	for (int i = 0; i < 2 * N; ++i) {
		cin >> arr[i].first;
		arr[i].second = -1;
	}

	//cnt: 벨트위 로봇의 개수
	int ret = 1, cnt = 0;
	while (true) {
		//회전
		rotate();
		//로봇내리기
		arr[N - 1].second = -1;

		//로봇이동
		for (int idx = N - 1; idx >= 0; --idx) {
			if (arr[idx].second == -1) continue;
			if (arr[idx + 1].first <= 0 || arr[idx + 1].second != -1) continue;
			arr[idx + 1].first -= 1;
			arr[idx + 1].second = arr[idx].second;
			arr[idx].second = -1;
		}

		//로봇내리기
		arr[N - 1].second = -1;
		
		//로봇올리기
		if (arr[0].first > 0) {
			arr[0].first -= 1;
			cnt += 1;
			arr[0].second = cnt;
		}

		if (finish())
			break;
		ret += 1;
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