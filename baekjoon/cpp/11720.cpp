#include <iostream>

using namespace std;

int main() {
	int N, s = 0;
	char c;
	cin >> N;
	while (N--) {
		cin >> c;
		s += c - '0';
	}
	cout << s;
	return 0;
}