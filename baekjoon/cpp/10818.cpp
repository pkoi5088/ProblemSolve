#include <iostream>
#define MIN -1000001
#define MAX 1000001

using namespace std;

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return a < b ? b : a;
}

int main() {
	int N, m = MAX, M = MIN, input;
	cin >> N;

	while (N--) {
		cin >> input;
		m = min(input, m);
		M = max(input, M);
	}
	cout << m << ' ' << M;
	return 0;
}