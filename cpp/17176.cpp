#include <iostream>
#include <string>

using namespace std;

char ch[53] = { ' ','A' ,'B' ,'C' ,'D' ,'E' ,'F' ,'G' ,'H' ,'I' ,'J'
,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y'
,'Z' ,'a' ,'b' ,'c' ,'d' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k' ,'l' ,'m' ,'n'
,'o' ,'p' ,'q' ,'r' ,'s' ,'t' ,'u' ,'v' ,'w' ,'x' ,'y' ,'z' };

int main() {
	int N, tmp;
	string input;
	int num[100000] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	cin.ignore();
	getline(cin, input);

	for (int i = 0; i < N; i++) {
		tmp = input.find(ch[num[i]]);
		if (tmp != -1) {
			input.erase(tmp, 1);
		}
	}

	if (input.size() == 0)
		cout << 'y';
	else
		cout << 'n';
	return 0;
}