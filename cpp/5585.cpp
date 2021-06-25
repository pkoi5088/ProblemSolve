#include <iostream>

using namespace std;

int main() {
	int en[6] = { 500,100,50,10,5,1 };
	int cnt = 0, tmp;
	int N;
	cin >> N;
	N = 1000 - N;
	for (int i = 0; i < 6; i++) {
		if (N == 0)
			break;
		if (N / en[i] == 0)
			continue;
		tmp = N / en[i];
		cnt += tmp;
		N -= en[i] * tmp;
	}
	cout << cnt;
	return 0;
}