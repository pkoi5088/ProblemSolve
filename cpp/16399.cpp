#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

const int MAX = 1000 + 2;
int C, E, D, N;
long long dist[MAX], price[MAX];
long long cache[MAX][500 + 1];

long long minPrice(int idx, int gas) {
	if (idx == N + 1)
		return 0;

	long long &result = cache[idx][gas];

	if (result != -1)
		return result;

	result = LLONG_MAX;

	if (C < (E * (dist[idx + 1] - dist[idx])))
		return result;

	result = min(result, price[idx] * (C - gas) + minPrice(idx + 1, C - E * (dist[idx + 1] - dist[idx])));

	for (int i = idx + 1; i <= N + 1; i++) {
		int gasUsed = E * (dist[i] - dist[idx]);
		if (gasUsed > C)
			break;

		if (gasUsed <= gas)
			result = min(result, minPrice(i, gas - gasUsed));
		else
			result = min(result, (gasUsed - gas) * price[idx] + minPrice(i, 0));
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> C >> E >> D >> N;
	if (!N)	{
		if (D*E <= C)
			cout << 0 << "\n";
		else
			cout << -1 << "\n";
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		int d;
		cin >> d;
		dist[i] = dist[i - 1] + d;
	}

	dist[N + 1] = D;
	for (int i = 1; i <= N; i++)

		cin >> price[i];
	memset(cache, -1, sizeof(cache));
	long long result = minPrice(0, C);
	if (result == LLONG_MAX || result < 0)
		cout << -1 << "\n";
	else
		cout << result << "\n";
	return 0;
}