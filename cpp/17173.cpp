#include<iostream>

using namespace std;

int main() {
	int N, M, sum = 0, t;
	bool K[1001] = { false, };

	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> t;
		for (int j = t; j <= N; j += t) {
			K[j] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (K[i])
			sum += i;
	}
	cout << sum;
	return 0;
}