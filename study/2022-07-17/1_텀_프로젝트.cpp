#include <iostream>
#include <cstring>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/9466
*/

int num[MAX];
//0: 탐색안함, 1: 탐색중, 2: 팀X, 3: 팀O
int visit[MAX];
int N;

void solve() {
	int result = 0;
	memset(visit, 0, sizeof(visit));
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
		num[i] -= 1;
	}

	for (int start = 0; start < N; ++start) {
		if (visit[start] != 0)
			continue;
		int i = start;
		while (visit[i] == 0) {
			visit[i] = 1;
			i = num[i];
		}
		if (visit[i] == 1) {
			while (visit[i] != 3) {
				visit[i] = 3;
				i = num[i];
			}
		}
		i = start;
		while (visit[i] == 1) {
			result += 1;
			visit[i] = 2;
			i = num[i];
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
	while(T--)
		solve();
	return 0;
}
