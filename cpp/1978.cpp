#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100;
int minFactor[1001];

void eratosthenes() {
	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i <= 1001; i++)
		minFactor[i] = i;

	int sqrtN = int(sqrt(1001));

	for (int i = 2; i <= sqrtN; i++)
		if (minFactor[i] == i)
			for (int j = i * i; j <= 1001; j += i)
				if (minFactor[j] == j)
					minFactor[j] = i;

}

int main() {
	int N;
	cin >> N;
	int cnt = 0;

	eratosthenes();

	for (int i = 0; i < N; i++)	{
		int num;
		cin >> num;
		if (minFactor[num] == num)
			cnt++;
	}

	cout << cnt;
	return 0;
}