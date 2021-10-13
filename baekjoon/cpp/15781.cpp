#include <iostream>

using namespace std;

int main() {
	int N, M, t1 = 0, t2, s = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> t2;
		if (t2 > t1)
			t1 = t2;
	}
	s += t1;
	t1 = 0;
	for (int i = 0; i < M; i++) {
		cin >> t2;
		if (t2 > t1)
			t1 = t2;
	}
	s += t1;

	cout << s;
	return 0;
}