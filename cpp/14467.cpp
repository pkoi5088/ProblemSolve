#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int cow[11] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        if (cow[a] == -1) {
            cow[a] = b;
        }
        else if (cow[a] != b && cow[a] != -1) {
            cow[a] = b;
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}