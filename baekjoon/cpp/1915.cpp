#include <iostream>
#include <string>

using namespace std;

int solve() {
	int M[1001][1001] = { 0 };
	int n, m, result = 0;
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		string s;
		cin >> s;
		for (int j = 1; j < m + 1; j++) {
			M[i][j] = s[j - 1] - '0';
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (M[i][j] != 0 && (M[i - 1][j - 1] != 0 && M[i][j - 1] != 0 && M[i - 1][j] != 0)) {
				if (M[i - 1][j - 1] != 1 && M[i][j - 1] != 1 && M[i - 1][j] != 1) {
					int t = min(M[i - 1][j - 1], M[i][j - 1]);
					t = min(M[i - 1][j], t);
					M[i][j] = t + 1;
					result = max(result, M[i][j]);
				}
				else {
					M[i][j] = 2;
					result = max(result, M[i][j]);
				}
			}
			else {
				result = max(result, M[i][j]);
			}
		}
	}

	return result * result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve() << endl;
	return 0;
}