#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Node {
public:
	string s;
	Node(string is) :s(is) {};
};

bool operator<(Node n1, Node n2) {
	if (n1.s.size() == n2.s.size())
		return n1.s < n2.s;
	return n1.s.size() < n2.s.size();
}

void solve() {
	int N;
	cin >> N;
	vector<Node> v;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		v.push_back(Node(s));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (i > 0 && v[i - 1].s == v[i].s)
			continue;
		cout << v[i].s << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
