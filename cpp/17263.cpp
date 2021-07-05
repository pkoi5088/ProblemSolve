#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int r = 0, m;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> m;
		r < m ? r = m : r = r;
	}

	cout << r;
	return 0;
}