#include <iostream>
#include <math.h>

using namespace std;

int function(int N, int* cost) {
	int i = 0, j = N - 1;
	int minimum = 200000001;
	while (i < j) {
		int sum = cost[i] + cost[j];
		if (abs(minimum) > abs(sum))
			minimum = sum;

		if (sum < 0)
			i++;
		else
			j--;
	}
	return minimum;
}

int main() {
	int N;
	cin >> N;

	int* cost = new int[N];
	for (int i = 0; i < N; i++)
		cin >> cost[i];

	cout << function(N, cost) << endl;
	return 0;
}