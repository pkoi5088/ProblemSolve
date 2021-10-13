#include <iostream>
#include <algorithm>
#define MAX 100
#define endl "\n"

using namespace std;

void solve() {
	int calorie[MAX];
	int N, A, B, C;
	cin >> N >> A >> B >> C;
	for (int i = 0; i < N; ++i)
		cin >> calorie[i];
	sort(calorie, calorie + N, greater<>());
	for (int i = 1; i < N; ++i)
		calorie[i] += calorie[i - 1];

	int ret = C / A;
	for (int i = 0; i < N; ++i) {
		int next = (C + calorie[i]) / (A + (i + 1) * B);
		ret = max(ret, next);
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}