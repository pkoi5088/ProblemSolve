#include <iostream>

using namespace std;

int N;
int result = 0;
int num[15] = { 0, };

int can(int i) {
	for (int j = 0; j < i; j++) {
		if (num[i] == num[j] || abs(num[i] - num[j]) == i - j)
			return false;
	}
	return true;
}

void solve(int a) {
	if (a == N) {
		result++;
	}
	else {
		for (int i = 0; i < N; i++) {
			num[a] = i;
			if (can(a) == 1) {
				solve(a+1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	solve(0);
	cout << result;
	return 0;
}