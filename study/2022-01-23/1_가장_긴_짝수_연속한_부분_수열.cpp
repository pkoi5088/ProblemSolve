#include <iostream>
#define MAX 50000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/22857
*/

int psum[MAX]={0,},arr[MAX];

int getPsum(int s,int e){
    if(s==0) return psum[e];
    return psum[e]-psum[s-1];
}

void solve() {
    int N,K,ret=0;
    cin>>N>>K;
    for(int i=0;i<N;++i){
        cin>>arr[i];
        if(i!=0)
            psum[i]=psum[i-1]+(arr[i]%2);
        else
            psum[i]=arr[i]%2;
    }

    for(int i=0;i<N;++i){
        for(int j=0;j<=i;++j){
            if(getPsum(j,i)<=K){
                if(ret<i-j+1-getPsum(j,i)){
                    ret=i-j+1-getPsum(j,i);
                }
                break;
            }
        }
    }
    cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}