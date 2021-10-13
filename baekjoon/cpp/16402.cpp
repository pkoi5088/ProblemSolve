#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 500

using namespace std;

int king[MAX] = { 0, };
map<string, int> si;
map<int, string> is;

//A를 B로
void c_k(int N, int A, int B) {
	for (int i = 0; i < N; i++) {
		if (king[i] == A) {
			king[i] = B;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= 3 * N; i++) {
		cin >> str;
		if (i % 3 == 0) {
			si.insert(make_pair(str, i / 3 - 1));
			is.insert(make_pair(i / 3 - 1, str));
			king[i / 3 - 1] = i / 3 - 1;
			//cout << str << " " << i / 3 - 1 << " " << king[i / 3 - 1] <<si[str]<<is[i/3-1]<< endl;
		}
	}

	for (int i = 0; i < M; i++) {
		string first_name, second_name;
		int first_index, second_index, win;

		cin >> str; cin >> str; cin >> str;
		first_name = str.substr(0, str.find(','));
		first_index = si[first_name];

		cin >> str; cin >> str;
		second_name = str.substr(0, str.find(','));
		second_index = si[second_name];
		win = str.back() - '1';

		if (win) {//second가 이길 때
			if (king[first_index] != king[second_index]) {
				c_k(N, king[first_index], king[second_index]);
			}
			else {
				c_k(N, king[first_index], second_index);
			}
		}
		else {
			if (king[first_index] != king[second_index]) {
				c_k(N, king[second_index], king[first_index]);
			}
			else {
				c_k(N, king[second_index], first_index);
			}
		}
	}

	vector<string> result;
	for (int i = 0; i < N; i++) {
		if (king[i] == i) {
			result.push_back(is[i]);
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << "Kingdom of " << result[i] << "\n";
	}

	return 0;
}