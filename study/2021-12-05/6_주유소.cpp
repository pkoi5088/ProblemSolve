#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/13305
*/

int getNext(int start,vector<int>& dist,vector<int>& price){
    int ret=start;
    for(;ret<price.size()-1&&price[start]<=price[ret];++ret);
    return ret;
}

void solve() {
    int N;
    vector<int> dist,price;
    cin>>N;
    dist.resize(N);
    price.resize(N);
    for(int i=0;i<N-1;++i)
        cin>>dist[i];
    for(int i=0;i<N;++i)
        cin>>price[i];
    
    long long ret=0;
    int now=0;
    while(now!=N-1){
        int next=getNext(now,dist,price),nextDist=0;
        for(int i=now;i<next;++i){
            nextDist+=dist[i];
        }
        ret+=(long long)price[now]*nextDist;
        now=next;
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