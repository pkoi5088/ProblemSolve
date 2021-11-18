#include <iostream>
#define MAX 10000
#define endl '\n'

using namespace std;

int arr[MAX];
int N = 0;

void f(int start, int end) {
	if (start >= end) return;
	int mid = start + 1;
	while (mid < end && arr[mid] < arr[start]) mid += 1;
	f(start + 1, mid);
	f(mid, end);
	cout << arr[start] << endl;
}

void solve() {
	int tmp;
	while (scanf("%d", &tmp) != EOF) {
		arr[N++] = tmp;
	}
	f(0, N);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
