#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	int a, max = -1, min = 1001;
	cin >> N;
	while (N--) {
		cin >> a;
		max < a ? max = a : max = max;
		min > a ? min = a : min = min;
	}
	cout << max - min;
	return 0;
}