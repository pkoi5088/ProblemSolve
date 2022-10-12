#include <iostream>
#include <vector>
#include <unordered_set>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/22233

*/

vector<string> split(string s, char d) {
	vector<string> ret;
	string tmp;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ',') {
			ret.push_back(tmp);
			tmp.clear();
		}
		else {
			tmp.push_back(s[i]);
		}
	}
	ret.push_back(tmp);
	return ret;
}

void solve() {
	int N, M;
	unordered_set<string> s;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		s.insert(tmp);
	}

	while (M--) {
		string t;
		cin >> t;
		vector<string> v = split(t, ',');
		for (auto tmp : v) {
			if (s.find(tmp) != s.end()) {
				s.erase(tmp);
			}
		}
		cout << s.size() << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}