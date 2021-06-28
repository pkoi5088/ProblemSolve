#include <iostream>
#include <string>

using namespace std;

int main() {
	string n;
	cin >> n;
	int sum = 0, cnt = 0;

	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '(') {
			if (n[i + 1] == '(') {
				cnt++;
			}
			else {
				sum += cnt;
				i++;
			}
		}
		else {
			sum++;
			cnt--;
		}
	}
	cout << sum;
	return 0;
}