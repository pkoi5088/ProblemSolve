#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Ticket {
public:
	Ticket() {}
	Ticket(string& num) { this->setNum(num); }

	void setNum(string& num) {
		this->num += num[0];
		this->num += num[1];
		for (int i = 0; i < 5 - num.size(); i++) {
			this->num += "0";
		}
		for (int i = 2; i < num.size(); i++) {
			this->num += num[i];
		}
	}

	void print() {
		cout << num << endl;
	}

	string num = "";

	bool operator < (Ticket& t) {
		return this->num < t.num;
	}

	bool operator == (Ticket& t) {
		return this->num == t.num;
	}
};

bool function(vector<Ticket>& q, vector<Ticket>& p_q) {
	stack<Ticket> s;
	int c_i = 0;
	for (int i = 0; i < q.size(); i++) {
		if (q[i] == p_q[c_i]) {
			c_i++;
		}
		else if (!s.empty()) {
			if (s.top() == p_q[c_i]) {
				i--;
				c_i++;
				s.pop();
			}
			else {
				s.push(q[i]);
			}
		}
		else {
			s.push(q[i]);
		}
	}

	if (s.empty())
		return true;
	else {
		while (!s.empty()) {
			if (s.top() == p_q[c_i]) {
				s.pop();
				c_i++;
			}
			else {
				return false;
			}
		}
		return true;
	}
}

int main() {
	int N;
	string input;
	Ticket* tmp = NULL;
	cin >> N;

	vector<Ticket> q;
	vector<Ticket> rank;

	for (int i = 0; i < 5 * N; i++) {
		cin >> input;
		tmp = new Ticket(input);
		q.push_back(*tmp);
	}

	rank = q;

	sort(rank.begin(), rank.end());

	if (function(q, rank))
		cout << "GOOD" << endl;
	else
		cout << "BAD" << endl;

	return 0;
}