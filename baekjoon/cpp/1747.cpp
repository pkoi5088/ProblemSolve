#include <iostream>
#include <vector>
#define MAX 1003002
#define endl "\n"

using namespace std;

bool isFal(int n) {
	vector<int> arr;
	while (n != 0) {
		arr.push_back(n % 10);
		n /= 10;
	}
	for (int i = 0; i < arr.size() / 2; ++i) {
		if (arr[i] != arr[arr.size() - i - 1]) return false;
	}
	return true;
}

void solve() {
	int N;
	cin >> N;
	bool prime[MAX] = { false };
    prime[1] = true;
	for (int n = 2; n < MAX; ++n) {
		if (prime[n] == true) continue;
		for (int i = 2 * n; i < MAX; i += n) prime[i] = true;
	}
	for (int n = N; n < MAX; ++n) {
		if (prime[n] == false && isFal(n)) {
			cout << n;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}