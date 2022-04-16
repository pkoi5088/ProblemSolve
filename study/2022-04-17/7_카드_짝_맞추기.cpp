#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
    https://programmers.co.kr/learn/courses/30/lessons/72415
*/

class Node{
    public:
    int x,y,dist;
    Node(int ix,int iy,int id){
        x=ix,y=iy,dist=id;
    }
};

int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int state[7]={0,};
vector<pair<int,int>> loc[7];

int getDist(vector<vector<int>>& board,int sx,int sy,int gx,int gy){
    queue<Node> q;
    bool visit[4][4]={false,};
    q.push(Node(sx,sy,0));
    visit[sx][sy]=true;
    while(!q.empty()){
        int x=q.front().x,y=q.front().y,dist=q.front().dist;
        q.pop();
        if(x==gx&&y==gy){
            return dist;
        }
        
        //상하좌우
        for(int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=4||ny<0||ny>=4||visit[nx][ny]) continue;
            q.push(Node(nx,ny,dist+1));
            visit[nx][ny]=true;
        }
        
        //컨트롤방향키
        for(int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||nx>=4||ny<0||ny>=4) continue;
            while(!(nx+dx[i]<0||nx+dx[i]>=4||ny+dy[i]<0||ny+dy[i]>=4||board[nx][ny]!=0)){
                nx+=dx[i];
                ny+=dy[i];
            }
            if(!visit[nx][ny]){
                q.push(Node(nx,ny,dist+1));
                visit[nx][ny]=true;
            }
        }
    }
}

//x,y에서 n번 카드를 뒤집는데 걸리는 횟수
int pick(vector<vector<int>>& board,int x,int y){
    int ret=0;
    for(int next=1;next<=6;++next){
        if(state[next]==0) continue;
        pair<int,int> p0=loc[next][0];
        pair<int,int> p1=loc[next][1];
        int dist01,dist10;
        
        //0->1
        dist01=getDist(board,x,y,p0.first,p0.second)+1
            +getDist(board,p0.first,p0.second,p1.first,p1.second)+1;
        //1->0
        dist10=getDist(board,x,y,p1.first,p1.second)+1
            +getDist(board,p1.first,p1.second,p0.first,p0.second)+1;
        
        state[next]=0;
        board[p0.first][p0.second]=0;
        board[p1.first][p1.second]=0;        
        
        dist01+=pick(board,p1.first,p1.second);
        dist10+=pick(board,p0.first,p0.second);
        if(ret==0) ret=min(dist01,dist10);
        else ret=min(ret,min(dist01,dist10));
        
        board[p0.first][p0.second]=next;
        board[p1.first][p1.second]=next;
        state[next]=1;
    }
    return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(board[i][j]!=0){
                state[board[i][j]]|=1;
                loc[board[i][j]].push_back({i,j});
            }
        }
    }
    answer=pick(board,r,c);
    return answer;
}