#include <iostream>
#include <algorithm>

using namespace std;

int* s;

bool p(int& a, int& N,int& M) {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		cnt += s[i] / a;

	if (cnt >= M)
		return true;
	return false;
}

int main() {
	int M, N, low, high = -1, result = 0;
	cin >> M >> N;
	s = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		high = max(high, s[i]);
	}
	low = 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (p(mid, N, M)) {
			result = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout << result;
	return 0;
}