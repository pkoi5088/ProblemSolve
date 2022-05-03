#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/21918
*/

void solve() {
    vector<int> v;
    int N,M;
    cin>>N>>M;
    v.resize(N);
    for(int i=0;i<N;++i)
        cin>>v[i];
    while(M--){
        int type,l,r;
        cin>>type>>l>>r;
        switch(type){
            case 1:
            v[l-1]=r;
            break;

            case 2:
            for(int i=l-1;i<r;++i)
                v[i]=!v[i];
            break;

            case 3:
            for(int i=l-1;i<r;++i)
                v[i]=0;
            break;

            case 4:
            for(int i=l-1;i<r;++i)
                v[i]=1;
            break;
        }
    }

    for(int i=0;i<N;++i){
        cout<<v[i]<< ' ';
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}