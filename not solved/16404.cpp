#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

class Node {
public:
	long long m = 0;

	Node* super = NULL;
};

long long cal(Node* node) {
	Node* tmp = node;
	long long r = 0;
	while (tmp != NULL) {
		r += tmp->m;
		tmp = tmp->super;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	Node* person = new Node[N];
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if (input != -1) {
			person[i].super = &person[input - 1];
		}
	}

	for (int i = 0; i < M; i++) {
		int tmp, a, b;
		cin >> tmp >> a;
		
		switch (tmp) {
		case 1:
			cin >> b;
			person[a - 1].m += b;
			break;

		case 2:
			cout << cal(&person[a-1]) << "\n";
			break;
		}
	}

	return 0;
}