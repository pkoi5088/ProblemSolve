#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int N, X, tmp;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		if (v[i] < X)
			cout << v[i] << ' ';
	}
	return 0;
}