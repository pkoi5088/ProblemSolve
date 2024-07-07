#include <iostream>
#define endl '\n'

#pragma region INPUT_MACRO
#define INPUT_TESTCASE	\
	int T;				\
	cin>>T;				\
	while(T--)			\
		solve();		
#define INPUT solve();
#pragma endregion

using namespace std;

void solve() {

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	INPUT;
	return 0;
}