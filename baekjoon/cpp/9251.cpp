#include <iostream>
#include <string>

using namespace std;

int solve() {
	string s1, s2;
	cin >> s1 >> s2;
	int** B = new int* [s1.size()+1];
	for (int i = 0; i < s1.size() + 1; i++) {
		B[i] = new int[s2.size()+1];
	}
	for (int i = 0; i < s1.size() + 1; i++) {
		for (int j = 0; j < s2.size() + 1; j++) {
			B[i][j] = 0;
		}
	}

	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				B[i + 1][j + 1] = B[i][j] + 1;
			}
			else {
				B[i + 1][j + 1] = max(B[i + 1][j], B[i][j + 1]);
			}
		}
	}
	return B[s1.size()][s2.size()];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve();
	return 0;
}