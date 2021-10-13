#include <iostream>
#include <string>

using namespace std;

bool map[65][65] = { false, };

void function(int a, int b, int size) {
	if (size == 1) {
		cout << map[a][b];
		return;
	}

	bool check = false;
	for (int i = a; i < a + size; i++) {
		for (int j = b; j < b + size; j++) {
			if (map[a][b] != map[i][j]) {
				check = true;
				break;
			}
		}
	}

	if (check) {
		cout << "(";
		function(a, b, size / 2);
		function(a, b + size / 2, size / 2);
		function(a + size / 2, b, size / 2);
		function(a + size / 2, b + size / 2, size / 2);
		cout << ")";
	}
	else {
		cout << map[a][b];
		return;
	}
}

int main() {
	int N;
	string in;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> in;
		for (int j = 1; j <=N; j++) {
			map[i][j] = in[j - 1] - '0';
		}
	}

	function(1, 1, N);

	return 0;
}