#include <iostream>
#define MAX 26
#define endl '\n'

using namespace std;

//0: 왼쪽자식, 1: 오른쪽자식
int tree[MAX][2];
int N;

void preorder(int n) {
	if (n == -1) return;
	cout << (char)(n + 'A');
	preorder(tree[n][0]);
	preorder(tree[n][1]);
}

void inorder(int n) {
	if (n == -1) return;
	inorder(tree[n][0]);
	cout << (char)(n + 'A');
	inorder(tree[n][1]);
}

void postorder(int n) {
	if (n == -1) return;
	postorder(tree[n][0]);
	postorder(tree[n][1]);
	cout << (char)(n + 'A');
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b == '.') tree[a - 'A'][0] = -1;
		else tree[a - 'A'][0] = b - 'A';
		if (c == '.') tree[a - 'A'][1] = -1;
		else tree[a - 'A'][1] = c - 'A';
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
