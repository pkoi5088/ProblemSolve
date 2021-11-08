#include <iostream>
#include <cmath>
#define MAX 1023
#define endl '\n'

using namespace std;

int tree[MAX], route[MAX];
int K;

//route[start:end+1]은 tree[root]가 루트인 서브트리
void f(int start, int end, int root) {
	if (start > end) return;
	int mid = (start + end) / 2;
	tree[root] = route[mid];
	f(start, mid - 1, 2 * root + 1);
	f(mid + 1, end, 2 * root + 2);
}

void solve() {
	cin >> K;
	for (int i = 0; i < pow(2, K) - 1; ++i) {
		cin >> route[i];
	}
	f(0, pow(2, K) - 1, 0);
	
	int idx = 0;
	for (int i = 1; i <= pow(2, K - 1); i *= 2) {
		for (int j = 0; j < i; ++j) {
			cout << tree[idx++] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
