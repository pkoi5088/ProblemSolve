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
	string result = "";
	int sum = 0;
	while (!s1.empty() && !s2.empty()) {
		sum += s1.back() - '0';
		sum += s2.back() - '0';
		s1.pop_back();
		s2.pop_back();
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
	string s1, s2;
	cin >> s1 >> s2;
	cout << strSum(s1, s2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
