#include <iostream>
#define MAX 1000000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/22862
*/

void solve() {
     int N,K;
     int arr[MAX],cnt=0;
     cin>>N>>K;
     for(int i=0;i<N;++i){
         cin>>arr[i];
     }
     
     int start=0,end=0,ret=0;
     cnt=arr[0]%2;
     while(true){
         end+=1;
         if(end>=N) break;

         cnt+=arr[end]%2;
         while(cnt>K){
             cnt-=arr[start]%2;
             start+=1;
         }
        ret=max(ret,end-start+1);
     }
     cout<<ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}