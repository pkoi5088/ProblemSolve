#include <iostream>

using namespace std;

int main() {
	int N, tmp;
	cin >> N;

	tmp = 1;

	while (N--) {
		for (int i = 1; i <= N; i++)
			cout << ' ';
		for (int i = 1; i <= tmp; i++)
			cout << '*';
		tmp += 2;
		cout << endl;
	}
	return 0;
}