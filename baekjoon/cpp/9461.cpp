#include <iostream>
#include <vector>

using namespace std;

long long pado[101] = { 0,1,1,1,2,2,3,4,5,7,9, };

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		if (pado[N])
			cout << pado[N] << endl;
		else {
			for (int i = 11; i <= N; i++)
				pado[i] = pado[i - 1] + pado[i - 5];
			cout << pado[N] << endl;
		}
	}
	return 0;
}