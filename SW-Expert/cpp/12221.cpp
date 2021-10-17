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
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/* 구현 */
		int A, B, ret = -1;
		cin >> A >> B;
		if (A < 10 && B < 10) ret = A * B;
		cout << '#' << test_case << ' ' << ret << endl;
	}
	return 0;
}