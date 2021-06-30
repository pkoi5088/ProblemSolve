#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> v;

void fun(int num, int f, int t, int b) {
	if (num == 1) {
		v.push_back({ f,t });
	}
	else {
		fun(num - 1, f, b, t);
		v.push_back({ f,t });
		fun(num - 1, b, t, f);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	fun(n, 1, 3, 2);
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}