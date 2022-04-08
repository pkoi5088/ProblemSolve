#include <iostream>
#define MAX 250000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/21921
*/

int arr[MAX];

int getPsum(int a,int b){
    if(a==0) return arr[b];
    return arr[b]-arr[a-1];
}

void solve() {
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;++i){
        cin>>arr[i];
        if(i!=0) arr[i]+=arr[i-1];
    }

    int ret=-1,count=0;
    for(int i=0;i<N-K+1;++i){
        if(ret<getPsum(i,i+K-1)){
            ret=getPsum(i,i+K-1);
            count=1;
        }else if(ret==getPsum(i,i+K-1)){
            count+=1;
        }
    }
    if(ret==0) cout<<"SAD";
    else cout<<ret<<endl<<count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}