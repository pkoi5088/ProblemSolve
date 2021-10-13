#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		int wb = 0, bw = 0;
		cin >> N;
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				if (s1[i] == 'B')
					bw++;
				else
					wb++;
			}
		}
		cout << (wb < bw ? bw : wb) << endl;
	}
	return 0;
}