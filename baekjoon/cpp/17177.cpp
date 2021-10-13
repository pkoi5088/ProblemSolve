#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int a, b, c, tmp;
	float t1, t2;
	cin >> a >> b >> c;
	t1 = sqrt((float)(a*a - b * b));
	t2 = sqrt((float)(a*a - c * c));
	tmp = (int)((t1*t2 - b * c) / a);
	if (tmp <= 0)
		cout << -1;
	else
		cout << (t1*t2 - b * c) / a;
	return 0;
}