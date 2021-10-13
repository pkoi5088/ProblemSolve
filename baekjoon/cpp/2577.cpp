#include <iostream>

using namespace std;

int main() {
	int A, B, C, T;
	int m[10] = { 0 };
	cin >> A >> B >> C;
	T = A * B * C;
	while (T != 0) {
		m[T % 10]++;
		T /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << m[i] << endl;
	return 0;
}