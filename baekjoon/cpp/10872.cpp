#include <iostream>

using namespace std;

int main() {
	int N, tmp = 1;
	cin >> N;
	if (N == 0 || N == 1)
		cout << 1;
	else {
		for (int i = 2; i <= N; i++)
			tmp *= i;
		cout << tmp;
	}
	return 0;
}