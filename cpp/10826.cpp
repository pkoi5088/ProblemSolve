#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

string strSum(string s1, string s2) {
	int sum = 0;
	string result = "";
	while (!s1.empty() && !s2.empty()) {
		sum += s1.back() - '0';
		sum += s2.back() - '0';
		s1.pop_back(); s2.pop_back();
		result.push_back(sum % 10 + '0');
		sum /= 10;
	}
	while (!s1.empty()) {
		sum += s1.back() - '0';
		s1.pop_back();
		result.push_back(sum % 10 + '0');
		sum /= 10;
	}
	while (!s2.empty()) {
		sum += s2.back() - '0';
		s2.pop_back();
		result.push_back(sum % 10 + '0');
		sum /= 10;
	}
	while (sum != 0) {
		result.push_back(sum % 10 + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

void solve() {
	vector<string> v;
	int n;
	cin >> n;
	if (n < 2)
		cout << n;
	else {
		v.resize(n + 1);
		v[0] = "0";
		v[1] = "1";
		for (int i = 2; i < n + 1; ++i) {
			v[i] = strSum(v[i - 1], v[i - 2]);
		}
		cout << v[n];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
