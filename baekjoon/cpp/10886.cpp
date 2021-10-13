#include <iostream>

using namespace std;

int main() {
	bool p;
	int N, a = 0, b = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p;
		if (p)
			b++;
		else
			a++;
	}
	a < b ? cout << "Junhee is cute!" : cout << "Junhee is not cute!";
	return 0;
}