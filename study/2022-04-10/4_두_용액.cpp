#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2470
*/

void solve() {
    int N;
    int arr[MAX];
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    sort(arr,arr+N);

    int answer[2]={arr[0],arr[N-1]};
    int left=0,right=N-1;
    while(left<right){
        if(abs(answer[0]+answer[1])>abs(arr[left]+arr[right])){
            answer[0]=arr[left];
            answer[1]=arr[right];
        }
        if(arr[left]+arr[right]>=0){
            right-=1;
        }else{
            left+=1;
        }
    }
    cout<<answer[0]<<' '<<answer[1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}