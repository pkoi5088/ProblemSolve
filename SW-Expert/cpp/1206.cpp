#include<iostream>
#include <cstdio>
#define endl '\n'

using namespace std;

int max(int a, int b, int c, int d) {
	return (max(max(a, b), max(c, d)));
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T = 10;
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/* 구현 */
		int N, a = -1, b = -1, now = -1, c = -1, d = -1, ret = 0;
		cin >> N;
		while (N--) {
			cin >> d;
			if (a != -1) {
				ret += max(0, now - max(a, b, c, d));
			}
			a = b;
			b = now;
			now = c;
			c = d;
		}
		cout << '#' << test_case << ' ' << ret << endl;
	}
	return 0;
}