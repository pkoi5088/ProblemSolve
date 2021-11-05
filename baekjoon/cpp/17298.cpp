#include <iostream>
#include <stack>
#define MAX 1000000
#define endl '\n'

using namespace std;

int arr[MAX] = { 0, };

void solve() {
	//first: idx, second: A_i
	stack<pair<int, int>> s;
	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		while (!s.empty() && s.top().second < tmp) {
			arr[s.top().first] = tmp;
			s.pop();
		}
		s.push({ i,tmp });
	}
	for (int i = 0; i < N; ++i) {
		if (arr[i] == 0) cout << -1 << ' ';
		else cout << arr[i] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
