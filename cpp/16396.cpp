#include <iostream>

using namespace std;

bool l[100001];
int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < b; i++) {
            l[i] = true;
        }
    }
    int c = 0;
    for (int i = 1; i <= 100000; i++) {
        if (l[i]) {
            c++;
        }
    }
    cout << c;
}