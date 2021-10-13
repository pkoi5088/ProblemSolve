#include <iostream>

using namespace std;

int main() {
	int n;
	bool check[30];
	for (int i = 0; i < 30; i++)
		check[i] = false;

	for (int i = 0; i < 28; i++) {
		cin >> n;
		check[n - 1] = true;
	}

	for (int i = 0; i < 30; i++) {
		if (check[i] == false) {
			cout << i + 1 << endl;
		}
	}
	return 0;
}