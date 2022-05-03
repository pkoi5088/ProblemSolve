#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/21608
*/

vector<vector<int>> seat;
int N;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};

bool check(vector<int>& like,int n){
    for(int i:like){
        if(i==n) return true;
    }
    return false;
}

void solve() {
    cin>>N;
    seat.resize(N);
    for(int i=0;i<N;++i)
        seat[i].resize(N,0);

    int tmp=N*N;
    while(tmp--){
        int num,x=-1,y=-1,curLike=0,curEmpty=0;
        vector<int> like(4);
        cin>>num;
        for(int i=0;i<4;++i)
            cin>>like[i];
        
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(seat[i][j]!=0) continue;

                int tLike=0,tEmpty=0;
                for(int k=0;k<4;++k){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx<0||nx>=N||ny<0||ny>=N) continue;
                    if(seat[nx][ny]==0) tEmpty+=1;
                    else if(check(like,seat[nx][ny])) tLike+=1;
                }

                if(curLike<tLike){
                    x=i,y=j,curLike=tLike,curEmpty=tEmpty;
                }else if(curLike==tLike&&curEmpty<tEmpty){
                    x=i,y=j,curLike=tLike,curEmpty=tEmpty;
                }else if(curLike==tLike&&curEmpty==tEmpty&&x==-1){
                    x=i,y=j,curLike=tLike,curEmpty=tEmpty;
                }
            }
        }
        seat[x][y]=num;
    }

    int ret=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){

        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}