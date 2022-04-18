#include <iostream>
#include <algorithm>
#define MAX 600
#define INF 2000000001
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/20366
*/

void solve() {
    int arr[MAX];
    int N;
    cin>>N;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    sort(arr,arr+N);

    int ret=INF;
    for(int i=0;i<N-1;++i){
        for(int j=i+1;j<N;++j){
            if(j-i<3) continue;
            int elsa=arr[i]+arr[j];
            int left=i+1,right=j-1;
            while(left<right){
                int anna=arr[left]+arr[right];
                ret=min(ret,abs(anna-elsa));
                if(anna>elsa)
                    right-=1;
                else
                    left+=1;
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