#include <iostream>
#include <string>
#include <cstdio>
#define endl '\n'

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/* 구현 */
		int N;
		string ret = "No";
		cin >> N;
		for (int a = 1; a < 10; ++a) {
			for (int b = 1; b < 10; ++b) {
				if (a * b == N) ret = "Yes";
			}
		}
		cout << '#' << test_case << ' ' << ret << endl;
	}
	return 0;
}