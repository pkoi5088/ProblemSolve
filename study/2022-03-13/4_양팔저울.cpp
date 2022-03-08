#include <iostream>
#include <vector>
#define MAX 15001
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2629
*/

void solve() {
    bool check[MAX]={false};
    int N,M;
    cin>>N;
    for(int i=0;i<N;++i){
        vector<int> v;
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
        for(int j=1;j<MAX;++j){
            if(check[j]){
                v.push_back(abs(j-tmp));
                v.push_back(abs(j+tmp));
            }
        }

        for(int a:v){
            if(a>0&&a<MAX)
                check[a]=true;
        }
    }
    cin>>M;
    while(M--){
        int tmp;
        cin>>tmp;
        if(tmp>=MAX||!check[tmp]) cout<<"N ";
        else cout<<"Y ";
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}