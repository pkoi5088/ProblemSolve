#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2812
*/

void solve() {
    int N,K;
    string number,ret;
    cin>>N>>K>>number;
    for(int i=0;i<N;++i){
        while(!ret.empty()&&K!=0&&ret.back()<number[i]){
            ret.pop_back();
            K-=1;
        }
        ret.push_back(number[i]);
    }
    while(K--)
        ret.pop_back();
    cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}