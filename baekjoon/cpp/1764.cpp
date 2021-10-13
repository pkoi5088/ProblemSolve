#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<string> v;

bool binarySearch(int low, int high, string name) {
	if (low > high)
		return false;
	else {
		int mid = (low + high) / 2;
		if (!v[mid].compare(name))
			return true;
		else if (v[mid] > name)
			return binarySearch(low, mid - 1, name);
		else
			return binarySearch(mid + 1, high, name);
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		v.push_back(name);
	}
	sort(v.begin(), v.end());
	vector<string> result;
	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;
		if (binarySearch(0, v.size() - 1, name))
			result.push_back(name);
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}