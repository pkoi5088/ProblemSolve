#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int m=0;
	int p_max = -1;
	for (int i = 0; i < 4; i++) {
        int a,b;
        cin >> a >> b;
        m = m-a+b;
		p_max = max(p_max, m);
	}
	cout << p_max;
	return 0;
}