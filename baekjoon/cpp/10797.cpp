#include <iostream>

using namespace std;

int main() {
	int N, cnt = 0;
	int m[5] = { 0 };
	cin >> N;
	for (int i = 0; i < 5; i++) {
		cin >> m[i];
		if (N == m[i])
			cnt++;
	}
	cout << cnt;
	return 0;
}