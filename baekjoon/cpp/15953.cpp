#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a[22] = { 0, }, b[32] = { 0, };
	a[1] = 5000000;
	a[2] = a[3] = 3000000;
	a[4] = a[5] = a[6] = 2000000;
	a[7] = a[8] = a[9] = a[10] = 500000;
	a[11] = a[12] = a[13] = a[14] = a[15] = 300000;
	a[16] = a[17] = a[18] = a[19] = a[20] = a[21] = 100000;

	b[1] = 5120000;
	b[2] = b[3] = 2560000;
	b[4] = b[5] = b[6] = b[7] = 1280000;
	b[8] = b[9] = b[10] = b[11] =
		b[12] = b[13] = b[14] = b[15] = 640000;
	b[16] = b[17] = b[18] = b[19] =
		b[20] = b[21] = b[22] = b[23] =
		b[24] = b[25] = b[26] = b[27] =
		b[28] = b[29] = b[30] = b[31] = 320000;

	int T, ia, ib;
	cin >> T;
	while (T--) {
		cin >> ia >> ib;
		if (ia > 21)
			ia = 0;
		if (ib > 31)
			ib = 0;
		cout << a[ia] + b[ib] << endl;
	}
	return 0;
}