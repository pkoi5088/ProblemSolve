#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	string S, ret = "", v;
	getline(cin, S);

	for (int i = 0; i < S.size();) {
		if (S[i] == ' ') {
			reverse(v.begin(), v.end());
			ret += v;
			v.clear();
			ret += S[i];
		}
		else if (S[i] == '<') {
			if (!v.empty()) {
				reverse(v.begin(), v.end());
				ret += v;
				v.clear();
			}
			while (S[i] != '>') {
				ret += S[i];
				i += 1;
			}
			ret += S[i];
		}
		else {
			v.push_back(S[i]);
		}
		i += 1;
	}
	if (!v.empty()) {
		reverse(v.begin(), v.end());
		ret += v;
		v.clear();
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
