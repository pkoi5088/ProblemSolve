#include <iostream>

using namespace std;

int main() {
	int N, K, t, s = 0;
	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> t;
		s += (t / 2) + (t % 2);
	}

	if (s >= N)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}