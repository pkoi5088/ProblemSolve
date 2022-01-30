#include <iostream>
#include <vector>
#define MAX 1024
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/15724
*/

int arr[MAX][MAX],psum[MAX][MAX]={0,};

void init(int N,int M){
    psum[0][0]=arr[0][0];
    for(int i=1;i<N;++i){
        psum[i][0]=psum[i-1][0]+arr[i][0];
    }
    for(int i=1;i<M;++i){
        psum[0][i]=psum[0][i-1]+arr[0][i];
    }
    for(int i=1;i<N;++i){
        for(int j=1;j<M;++j){
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+arr[i][j];
        }
    }
}

int getPsum(int x,int y){
    if(x<0||y<0) return 0;
    return psum[x][y];
}

void solve() {
    int N,M,K;
    cin>>N>>M;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>arr[i][j];
        }
    }
    init(N,M);
    cin>>K;
    while(K--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1-=2;x2-=1;y1-=2;y2-=1;
        cout<<getPsum(x2,y2)-getPsum(x1,y2)-getPsum(x2,y1)+getPsum(x1,y1)<<endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}