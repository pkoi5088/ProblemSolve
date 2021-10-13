#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 40001;
const int MOD = 123456789;

int N;
int cache[MAX];
int minFactor[MAX];
vector<int> prime;

void eratosthenes() {
	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i < MAX; i++)
		minFactor[i] = i;

	for (int i = 2; i < MAX; i++)
		if (minFactor[i] == i) {
			for (int j = i * i; j < MAX; j += i)
				if (minFactor[j] == j)
					minFactor[j] = i;
		}
	for (int i = 2; i < MAX; i++)
		if (minFactor[i] == i)
			prime.push_back(i);
}

int main() {
	cin >> N;
	eratosthenes();
	cache[0] = 1;
	for (int i = 0; i < prime.size(); i++)
		for (int j = prime[i]; j <= N; j++) {
			cache[j] = (cache[j] + cache[j - prime[i]]) % MOD;
			cache[j] %= MOD;
		}
	cout << cache[N] << "\n";
	return 0;

}