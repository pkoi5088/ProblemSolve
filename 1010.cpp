#include <iostream>

using namespace std;

int main() {
	int t, i, j, k, n, m;
	cin >> t;
	while (t > 0) {
		int d[30][30] = { 0 };
		cin >> n >> m;
		for (i = 0; i <= m; i++)
			d[1][i] = i;
		for (i = 2; i <= n; i++)
			for (j = i; j <= m; j++)
				for (k = j; k >= i; k--)
					d[i][j] += d[i - 1][k - 1];
		cout << d[n][m] << endl;
		t--;
	}
	return 0;
}