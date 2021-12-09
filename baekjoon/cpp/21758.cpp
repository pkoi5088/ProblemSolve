#include <iostream>
#define MAX 100000
#define endl '\n'

using namespace std;

int getPsum(int start,int end,int* psum){
	if(start>end) return 0;
	if(start==0) return psum[end];
	return psum[end]-psum[start-1];
}

void solve() {
    int N,arr[MAX],psum[MAX];
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
		psum[i]=arr[i];
	}
	
	for(int i=1;i<N;++i)
		psum[i]+=psum[i-1];
	
	int ret=0;
	for(int i=1;i<N-1;++i){
		int tmp=0;
		//0에 벌통
		tmp=2*getPsum(0,i-1,psum);
		if(i!=N-2) tmp+=getPsum(i+1,N-2,psum);
		ret=max(ret,tmp);
		//i에 벌통
		tmp=getPsum(1,i,psum)+getPsum(i,N-2,psum);
		ret=max(ret,tmp);
		//N-1에 벌통
		tmp=2*getPsum(i+1,N-1,psum);
		if(i!=1) tmp+=getPsum(1,i-1,psum);
		ret=max(ret,tmp);
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