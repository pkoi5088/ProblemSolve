#include <iostream>
#define MAX 15
#define endl "\n"

using namespace std;

void solve() {
	long long n, price[MAX];
	long long W, coin = 0;
	cin >> n >> W;
	for (int i = 0; i < n; ++i)
		cin >> price[i];

	int day = 0;
	while (day < n - 1) {
		if (price[day] > price[day + 1]) {
			W += coin * price[day];
			coin = 0;
		}
		else if (price[day] < price[day + 1]) {
			coin += W / price[day];
			W -= (W / price[day]) * price[day];
		}
		day++;
	}
	W += coin * price[n - 1];
	cout << W;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}