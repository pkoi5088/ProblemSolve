#include<vector>
#include<queue>
using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/1844
*/

int solution(vector<vector<int>> maps)
{
    bool check[100][100]={false,};
    //maps[N][M]으로 표현
    int N,M,answer=-1,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    N=maps.size(),M=maps[0].size();
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    check[0][0]=true;
    while(!q.empty()){
        int x=q.front().first.first,y=q.front().first.second,dist=q.front().second;
        q.pop();
        if(x==N-1&&y==M-1){
            return dist;
        }
        for(int l=0;l<4;++l){
            int nx=x+dx[l],ny=y+dy[l];
            if(nx<0||nx>=N||ny<0||ny>=M||maps[nx][ny]==0||check[nx][ny]) continue;
            q.push({{nx,ny},dist+1});
            check[nx][ny]=true;
        }
    }
    return -1;
}