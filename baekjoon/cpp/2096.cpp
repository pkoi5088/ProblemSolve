#include <iostream>

using namespace std;

int Max(int a, int b) {
	return a > b ? a : b;
}

int Max(int a, int b, int c) {
	if (a > b)
		return a > c ? a : c;
	else
		return b > c ? b : c;
}

int Min(int a, int b) {
	return a < b ? a : b;
}

int Min(int a, int b, int c) {
	if (a < b)
		return a < c ? a : c;
	else
		return b < c ? b : c;
}

void solve() {
	int N, dpMax[3] = { 0, }, dpMin[3] = { 0, }, tmp[3] = { 0, };
	cin >> N;
	int x, y, z;
	cin >> x >> y >> z;
	dpMax[0] = dpMin[0] = x;
	dpMax[1] = dpMin[1] = y;
	dpMax[2] = dpMin[2] = z;
	N -= 1;

	while (N--) {
		cin >> x >> y >> z;
		tmp[0] = Max(dpMax[0], dpMax[1]) + x;
		tmp[1] = Max(dpMax[0], dpMax[1], dpMax[2]) + y;
		tmp[2] = Max(dpMax[1], dpMax[2]) + z;

		for (int i = 0; i < 3; i++)
			dpMax[i] = tmp[i];

		tmp[0] = Min(dpMin[0], dpMin[1]) + x;
		tmp[1] = Min(dpMin[0], dpMin[1], dpMin[2]) + y;
		tmp[2] = Min(dpMin[1], dpMin[2]) + z;

		for (int i = 0; i < 3; i++)
			dpMin[i] = tmp[i];
	}
	cout << Max(dpMax[0], dpMax[1], dpMax[2]) << ' ' << Min(dpMin[0], dpMin[1], dpMin[2]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}