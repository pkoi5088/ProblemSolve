#include <iostream>
#include <algorithm>
#define MAX 10000
#define endl '\n'

using namespace std;

int arr[MAX];
int N, M;

//상한액을 limit으로 했을 때 총예산에 맞출수 있는가?
bool check(int limit) {
	int total = 0;
	for (int i = 0; i < N; ++i)
		total += arr[i];
	
	if (total <= M) return true;
	total = 0;
	for (int i = 0; i < N; ++i)
		total += min(arr[i], limit);
	return total <= M;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	cin >> M;
	sort(arr, arr + N);

	int minimum = 1, maximum = arr[N - 1], ret = -1;
	while (minimum <= maximum) {
		int mid = (minimum + maximum) / 2;
		if (check(mid)) {
			ret = max(ret, mid);
			minimum = mid + 1;
		}
		else {
			maximum = mid - 1;
		}
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
