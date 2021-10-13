//A = 65
#include <iostream>

using namespace std;

struct Vertex {
	char name = '.';
	Vertex* left = nullptr;
	Vertex* right = nullptr;
};

void one(Vertex* start) {
	if (start != nullptr) {
		cout << start->name;
		one(start->left);
		one(start->right);
	}
}

void two(Vertex* start) {
	if (start != nullptr) {
		two(start->left);
		cout << start->name;
		two(start->right);
	}
}

void three(Vertex* start) {
	if (start != nullptr) {
		three(start->left);
		three(start->right);
		cout << start->name;
	}
}

int main() {
	int N;
	char input1, input2, in_name;
	cin >> N;
	Vertex* tree = new Vertex[N];

	for (int i = 0; i < N; i++) {
		cin >> in_name >> input1 >> input2;
		tree[(int)in_name - 65].name = in_name;
		if (input1 != '.') {
			tree[(int)in_name - 65].left = &tree[(int)input1 - 65];
		}
		if (input2 != '.') {
			tree[(int)in_name - 65].right = &tree[(int)input2 - 65];
		}
	}

	one(&tree[0]);
	cout << endl;
	two(&tree[0]);
	cout << endl;
	three(&tree[0]);

	return 0;
}