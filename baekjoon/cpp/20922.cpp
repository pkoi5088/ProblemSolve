#include <iostream>
#define MAX 200000
#define MAX_A 100001
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/20922
*/

void solve() {
     int N,K;
     int arr[MAX],cnt[MAX_A]={0,};
     cin>>N>>K;
     for(int i=0;i<N;++i){
         cin>>arr[i];
     }

     int start=0,end=0,ret=0;
     cnt[arr[0]]+=1;
     while(true){
         end+=1;
         if(end>=N) break;

         cnt[arr[end]]+=1;
         while(cnt[arr[end]]>K){
            cnt[arr[start]]-=1;
            start+=1;
         }
         ret=max(ret,end-start+1);
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