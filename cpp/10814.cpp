#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Member {
public:
	int age, number;
	string name;
	Member(int a, int b, string c) :age(a), number(b), name(c) {};
};

bool operator<(Member m1, Member m2) {
	if (m1.age == m2.age)
		return m1.number < m2.number;
	return m1.age < m2.age;
}

vector<Member> v;

void solve() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		string s;
		cin >> a >> s;
		v.push_back(Member(a, i, s));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].age << ' ' << v[i].name << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
