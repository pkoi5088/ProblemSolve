#include <iostream>
#include <algorithm>
#include <string>
#define MAX 15
#define endl '\n'

using namespace std;

char arr[MAX];
int L, C;

void pick(int n, string& code, int consonant, int collection) {
	if (n < C) {
		code.push_back(arr[n]);
		switch (arr[n]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			collection++;
			break;

		default:
			consonant++;
		}
		if (code.size() == L) {
			if (consonant >= 2 && collection >= 1) {
				cout << code << endl;
			}
		}
		else {
			pick(n + 1, code, consonant, collection);
		}
		code.pop_back();
		switch (arr[n]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			collection--;
			break;

		default:
			consonant--;
		}
		pick(n + 1, code, consonant, collection);
	}
}

void solve() {
	string code = "";
	cin >> L >> C;
	for (int i = 0; i < C; ++i)
		cin >> arr[i];
	sort(arr, arr + C);
	pick(0, code, 0, 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
