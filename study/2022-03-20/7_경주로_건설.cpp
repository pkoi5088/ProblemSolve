#include <string>
#include <vector>
#include <queue>
#define MAX 25
#define INF 2000000000

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/67259
*/

struct Node{
    int x,y,dir,cost;
    Node(int ix,int iy,int id,int ic){
        x=ix,y=iy,dir=id,cost=ic;
    }
};

//상 좌 하 우
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int dp[MAX][MAX][4],N;

int solution(vector<vector<int>> board) {
    N=board.size();
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            for(int k=0;k<4;++k)
                dp[i][j][k]=INF;
        }
    }
    
    queue<Node> q;
    q.push(Node(0,0,2,0));
    q.push(Node(0,0,3,0));
    dp[0][0][2]=dp[0][0][3]=0;
    
    int answer=INF;
    while(!q.empty()){
        int x=q.front().x,y=q.front().y,dir=q.front().dir,cost=q.front().cost;
        q.pop();
        
        //도착
        if(x==N-1&&y==N-1){
            answer=min(answer,cost);
            continue;
        }
        
        int nx,ny,ndir;
        
        //직진
        ndir=dir;
        nx=x+dx[ndir],ny=y+dy[ndir];
        if(nx>=0&&nx<N&&ny>=0&&ny<N&&board[nx][ny]!=1){
            if(dp[nx][ny][ndir]>=cost+100){
                q.push(Node(nx,ny,ndir,cost+100));
                dp[nx][ny][ndir]=cost+100;
            }
        }
        //좌회전
        ndir=(dir+1)%4;
        nx=x+dx[ndir],ny=y+dy[ndir];
        if(nx>=0&&nx<N&&ny>=0&&ny<N&&board[nx][ny]!=1){
            if(dp[nx][ny][ndir]>=cost+600){
                q.push(Node(nx,ny,ndir,cost+600));
                dp[nx][ny][ndir]=cost+600;
            }
        }
        //우회전
        ndir=(dir+3)%4;
        nx=x+dx[ndir],ny=y+dy[ndir];
        if(nx>=0&&nx<N&&ny>=0&&ny<N&&board[nx][ny]!=1){
            if(dp[nx][ny][ndir]>=cost+600){
                q.push(Node(nx,ny,ndir,cost+600));
                dp[nx][ny][ndir]=cost+600;
            }
        }
    }
    return answer;
}