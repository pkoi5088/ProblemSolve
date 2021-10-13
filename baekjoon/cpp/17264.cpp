#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int N, P, W, L, G, grade = 0;
	bool flag = false;
	cin >> N >> P >> W >> L >> G;

	map<string, bool> m;

	for (int i = 0; i < P; i++) {
		string tmp;
		char t;
		cin >> tmp >> t;
		m.insert({ tmp,t == 'W' ? true : false });
	}

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		if (m[input])
			grade += W;
		else {
			grade -= L;
			grade < 0 ? grade = 0 : grade = grade;
		}

		if (grade >= G)
			flag = true;
	}

	if (flag)
		cout << "I AM NOT IRONMAN!!\n";
	else
		cout << "I AM IRONMAN!!\n";

	return 0;
}