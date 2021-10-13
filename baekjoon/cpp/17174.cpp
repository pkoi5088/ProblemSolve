#include <iostream>

using namespace std;

int f(int N, int M) {
	if (N < M)
		return N;
	return N + f(N / M, M);
}

int main() {
	int N, M;
	cin >> N >> M;

	cout << f(N, M);
	return 0;
}