#include <iostream>

using namespace std;

int a[246913], N;

int main() {
	a[1] = 1;
	for (int i = 2; i <= 246912; i++) {
		if (a[i] == 1)
			continue;
		for (int j = i + i; j <= 246912; j += i)
			a[j] = 1;
	}
	while (true) {
		cin >> N;
		if (!N)
			break;
		int c = 0;
		for (int i = N + 1; i <= 2 * N; i++)
			if (!a[i])
				c++;
		cout << c << '\n';
	}

	return 0;
}
