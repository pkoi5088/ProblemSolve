#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool function(string& input) {
	stack<char> s;
	for (int j = 0; j < input.size(); j++) {
		switch (input[j]) {
		case '(':
			s.push('(');
			break;

		case ')':
			if (s.empty())
				return false;
			else {
				if (s.top() == '(')
					s.pop();
				else
					return false;
			}
			break;
		}
	}

	if (s.size() == 0)
		return true;
	else
		return false;
}

int main() {
	int T;
	string input;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> input;
		if (function(input))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}