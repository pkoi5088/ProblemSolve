#include <iostream>

using namespace std;

int fibo(int n) {
	static int mem[41] = { 0 };
	if (mem[n] > 0)return mem[n];
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	return mem[n] = fibo(n - 2) + fibo(n - 1);
}

int main() {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		if (N == 0)
			cout << "1 0\n";
		else
			cout << fibo(N - 1) << " " << fibo(N) << "\n";
	}
	return 0;
}