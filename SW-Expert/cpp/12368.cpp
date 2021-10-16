#include<iostream>
#include <cstdio>
#define endl '\n'

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/* 구현 */
		int A, B;
		cin >> A >> B;
		cout << '#' << test_case << ' ' << (A + B) % 24 << endl;
	}
	return 0;
}