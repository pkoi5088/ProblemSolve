#include <iostream>

using namespace std;

int main() {
	short T, N, M;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			short a;
			cin >> a >> a;
		}
		cout << N - 1 << "\n";
	}
	return 0;
}