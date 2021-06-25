#include <iostream>

using namespace std;

int main() {
	int N, tmp;
	cin >> N;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		N -= tmp;
	}
	cout << N;
	return 0;
}